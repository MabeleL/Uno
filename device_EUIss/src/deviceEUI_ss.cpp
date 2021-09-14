
//define the libraries to be used. TTN library downloaded at https://platformio.org/lib/show/987/TheThingsNetwork
#include <Arduino.h>
#include <TheThingsNetwork.h>
#include <SoftwareSerial.h>

#define debugSerial Serial

//pin 8 is tx pin of the RN2483 module while pin 7 is the rx pin of the Rn2483
SoftwareSerial loraSerial = SoftwareSerial(8,7); //rx, tx

#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup(){

  //pin 13 is defined here for reset
  pinMode(13, OUTPUT);
  loraSerial.begin(57600);
  debugSerial.begin(9600);
}

void loop(){
  digitalWrite(13, LOW);
  delay(50);
  digitalWrite(13, HIGH);
  debugSerial.println("Device Information");
  debugSerial.println();
  ttn.showStatus();
  debugSerial.println();
  debugSerial.println("EUI:");
  debugSerial.println("               ");
  debugSerial.println();

  delay(10000);
}
