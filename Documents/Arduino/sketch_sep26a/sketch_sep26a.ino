#include <KNWRobot.h>

int tempPin = 0; //voltage divider tap connected to analog pin 0
int motorPinIn = 2;//motor pin assigned to 2(note subject to change
int motorPinOut = 3;//motor pin assigned to 3(note subject to change)
KNWRobot* myRobot;
bool success;

void setup() {
  // put your setup code here, to run once:
  myRobot = new KNWRobot();//create instance of the robot
  success = myRobot->setupTemp(tempPin);//setup probe with input pin
  if (success){
    Serial.begin(9600);//setup serial communication with laptop
    }


  pinMode(motrPinIn,INPUT);
  pinMode(motorPinOut,OUTPUT);
  Serial.begin(9600);
   While (!Serial);
   Serial.println("speed 0 to 255");
}

void loop() {
  // put your main code here, to run repeatedly:
  int i,adc;

  if (success) {
    adc = 0;
    for (i = 0;i < 10;i++){//read adc 10 times
      adc += myRobot->getTemp();//read adc for temperature probe
      }
      Serial.println(adc / 10); //report average value to the serial port
    }
    delay(1000); //wait a second

    
    digitalWrite(motorPin,HIGH);
    if (Serial.available()){
      int speed = Serial.parseInt();
      if (speed >= 0 && speed <= 255){
        analogWrite(motorPin,speed);
        }
      
      }
}
