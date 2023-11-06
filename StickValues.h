#ifndef STICK_VALUES_H
#define STICK_VALUES_H

class StickValues {
  public:
    int xAxis;
    int yAxis;
    bool switchValue;

    StickValues(int xValue, int yValue, bool switchValue);
};
#endif
