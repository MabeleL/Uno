#include "DHT.h"
#include <Arduino.h>
#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>


#define debugSerial Serial

//pin 8 is tx pin of the RN2483 module while pin 7 is the rx pin of the Rn2483
SoftwareSerial loraSerial = SoftwareSerial(8,7); //rx, tx

#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

DHT dht;

const char *appEui = "0000000000000000";
const char *appKey = "3E2A70273271DF27E1B45F246251FDC5";


void setup(){
	debugSerial.begin(9600);
	dht.setup(6);
	loraSerial.begin(57600);

	// Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000);

  debugSerial.println("-- STATUS");
  ttn.showStatus();
  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);

}

void loop(){
	uint8_t humidity = dht.getHumidity();
  uint8_t temperature = dht.getTemperature();

	uint8_t payload[4];

	payload[0] = highByte(humidity);
  payload[1] = lowByte(humidity);
  payload[2] = highByte(temperature);
  payload[3] = lowByte(temperature);


	debugSerial.print("\t");
  debugSerial.print(humidity, 1);
  debugSerial.print("\t\t");
  debugSerial.print(temperature, 1);
  debugSerial.print("\t\t");

	 ttn.sendBytes(payload, sizeof(payload));
   delay(2000);


}
