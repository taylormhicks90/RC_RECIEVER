#include "functions.h"
void printData(DATA_PACKET data)
{
  Serial.print(data.x1);
  Serial.print('\t');
  Serial.print(data.y1);
  Serial.print('\t');
  Serial.print(data.s1);
  Serial.print('\t');
  Serial.print(data.x2);
  Serial.print('\t');
  Serial.print(data.y2);
  Serial.print('\t');
  Serial.println(data.s2);
}

void setPosition(int &servo, int position){
  if(position > 180) servo = 180;
  else if(position < 0) servo = 0;
  else servo = position;
}