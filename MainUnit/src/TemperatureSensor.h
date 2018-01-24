/*
  TemperatureSensor.h - Heatingcontrol by hagre 2018.
*/

#include "Arduino.h"

#include "definitions.h"

#ifndef temperaturesensor_h
#define temperaturesensor_h

class TemperatureSensor {

  public:
    TemperatureSensor (void);
    void initSensor (int8_t subIdNo);

    void operate (unsigned long timeNow);
    void setTemperature (float input);

    float getLastTemperature (void);
    float getAverageTemperature (void);

    int8_t resetErrorFlag (void);
    int8_t getErrorActiveNow (void);
    int8_t getErrorFlag (void);

    int8_t getSubIdNo (void);

  private:
    void setInitialTemperature (float input);
    void makeAverage (float input);

    int8_t _numReadings = TEMPERATURESENSOR_AVERAGE_NUMBER_OF_READINGS;
    float_t _readings[TEMPERATURESENSOR_AVERAGE_NUMBER_OF_READINGS];
    int8_t _readIndex;
    float_t _total;
    float_t _average;
    float_t _input;
    unsigned long _timeLastCalculate;
    unsigned long _timeLastAlive;
    unsigned long _timeLastOperate;

    int8_t _errorFlag;
    int8_t _timingErrorActive;

    int8_t _subIdNo;
};

#endif
