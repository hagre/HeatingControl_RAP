/*
  TemperatureModule.h - Heatingcontrol by hagre 2018.
*/

#include "Arduino.h"

#include "definitions.h"
#include "TemperatureSensor.h"

#ifndef temperaturemodule_h
#define temperaturemodule_h

class TemperatureModule {

  public:
    TemperatureModule (void);
    void initModule (int8_t iDNo, int8_t _NumberOfSensors, TemperatureSensor **ptrArray);
    void operate (unsigned long timeNow);
    void setTemperature (int8_t indexNo, float input);
    void setError (int8_t input);
    int8_t resetErrorFlagModule (void);
    int8_t resetErrorFlagOnSensors(int8_t indexNo);
    int8_t resetErrorFlagOnAllSensors(void);
    int8_t getErrorActiveNowModule (void);
    int8_t getErrorActiveNowAnySensor (void);
    int8_t getErrorFlagModule (void);
    int8_t getReceivedErrorModul (void);
    int8_t getErrorFlagOnSensors(int8_t indexNo);

    float getLastTemperature (int8_t indexNo);
    float getAverageTemperature (int8_t indexNo);

    int8_t getIdNo (void);
    int8_t getSubIdNo (int8_t indexNo); //only test

  private:
    TemperatureSensor **_SensorList;

    int8_t _NumberOfSensors;
    int8_t _IdNo;
    int8_t _ErrorReceived;

    unsigned long _timeLastAlive;
    unsigned long _timeLastOperate;

    int8_t _errorFlag;
    int8_t _timingErrorActive;
};

#endif
