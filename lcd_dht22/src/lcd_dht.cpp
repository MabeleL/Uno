#include "Arduino.h"
#include <LiquidCrystal.h>
#include "DHT.h"

DHT dht;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){

	lcd.begin(16,2);
	Serial.begin(9600);
	dht.setup(6);
}

void loop(){

	uint8_t humidity = dht.getHumidity();
  uint8_t temperature = dht.getTemperature();

	Serial.print("Humidity is:");
	Serial.print(humidity,1);
	Serial.print("\t%");
	Serial.print("\nTemperature is:");
	Serial.print(temperature,1);
	Serial.print("\t°C");
  
	lcd.setCursor(0,0);
	lcd.print("humidity:");
	lcd.print(humidity);
	lcd.print("%");
	lcd.setCursor(0,1);
	lcd.print("temp:");
	lcd.print(temperature);
	lcd.print(" degrees");


	delay(20000);

}
