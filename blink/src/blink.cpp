//*Code written by Mabele Leonard*
//programming an LED connected to an Arduino Uno 
//language used is C++ through Platformio

//calling the Arduino Library
#include "Arduino.h"

//connect the LED to pin 8, you can still use Pin13 as the default if you do not have a resistor and an LED as well as other components such as jumper wires, breadboard etc
#define LEDPin 8

//set the time interval for the LED  to blink on and off
const int time = 100;

//this is the entry point of your code - it is called once during execution
void setup(){

	//this is the definition of the assigned pin 8 to provide the output
	pinMode(LEDPin, OUTPUT);
}

//this section runs over and over on your arduino Uno during execution
void loop(){

	//this is the feedback digital method on the LED status - either on or off
	digitalWrite(LEDPin, HIGH);
	delay(time);
	digitalWrite(LEDPin, LOW);
	delay(time);
}


