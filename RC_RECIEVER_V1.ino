#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include "PinDefinitions.h"
#include "functions.h"

RF24 radio(RF_CE,RF_CSN);

const byte address[6] = "00001";


DATA_PACKET data;
SERVO_POSITIONS position;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  Serial.begin(9600);
  //Setup Radio
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  //Attach Servos
  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  servo3.attach(SERVO_3_PIN);
  servo4.attach(SERVO_4_PIN);
}

void loop() {
  if(radio.available())
  {
    radio.read(&data,sizeof(data));
    //printData(data);
    controlServos(data);
  }
}



void controlServos(DATA_PACKET data){
  controlServo(servo1,position.servo1,data.x1,data.s1);
  controlServo(servo2,position.servo2,data.y1,data.s1);
  controlServo(servo3,position.servo3,data.x2,data.s2);
  controlServo(servo4,position.servo4,data.y2,data.s2);
}

void controlServo(Servo servo, int &position, int data, bool reset){
    if(!reset)
  {
      int move =  map(data,-100,100,-7,7);
      setPosition(position,position += move);
  }else{
    setPosition(position,90);
  }
  servo.write(position);
}





