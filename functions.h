#ifndef FUNCTIONS
#define FUCNTIONS

#include <HardwareSerial.h>

struct DATA_PACKET {
  short x1 = 0;
  short y1 = 0;
  bool s1 = false;
  short x2 = 0;
  short y2 = 0;
  bool s2 = false;
};

struct SERVO_POSITIONS
{
  int servo1 = 90;
  int servo2 = 90;
  int servo3 = 90;
  int servo4 = 90;
};

void printData(DATA_PACKET data);
void setPosition(int &servo, int position);
#endif