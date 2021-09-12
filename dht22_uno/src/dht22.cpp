#include "DHT.h"
#include <Arduino.h>

DHT dht;

void setup(){
	Serial.begin(9600);

	dht.setup(6);

}

void loop(){
	uint8_t humidity = dht.getHumidity();
  uint8_t temperature = dht.getTemperature();

	//Serial.print(dht.getStatusString());
	Serial.print("Humidity is:");
	Serial.print(humidity,1);
	Serial.print("\t%");
	Serial.print("\nTemperature is:");
	Serial.print(temperature,1);
	Serial.print("\t°C");

	delay(1000);
}
