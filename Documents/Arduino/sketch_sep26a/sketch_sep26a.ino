#include <KNWRobot.h>

int tempPin = 0; //voltage divider tap connected to analog pin 0
KNWRobot* robot;
bool success;

void setup() {
  // put your setup code here, to run once:
  robot = new KNWRobot();//create instance of the robot
  success = robot->setupTemp(tempPin);//setup probe with input pin
  if (success){
    Serial.begin(9600);//setup serial communication with laptop
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i,adc;

  if (success) {
    adc = 0;
    for (i = 0;i < 10;i++){//read adc 10 times
      adc += robot->getTemp();//read adc for temperature probe
      }
      Serial.println(adc / 10); //report average value to the serial port
    }
    delay(1000); //wait a second
}
