#include "StickValues.h"

StickValues::StickValues(int xValue = 0, int yValue = 0, bool switchValue = 0){
  this->xAxis = (int) xValue;
  this->yAxis = (int) yValue;
  this->switchValue = switchValue;
}