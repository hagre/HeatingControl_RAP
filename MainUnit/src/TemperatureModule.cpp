/*
  TemperatureModule.cpp - Heatingcontrol by hagre 2018.
*/

#include "Arduino.h"
#include "definitions.h"

#include "TemperatureSensor.h"

#include "TemperatureModule.h"

TemperatureModule::TemperatureModule (void) {
}

void TemperatureModule::initModule (int8_t idNo, int8_t numberOfSensors, TemperatureSensor **ptrArray) {
  _SensorList = ptrArray;
  _NumberOfSensors = numberOfSensors;
  _IdNo = idNo;
  _timeLastAlive = 0;
  _timeLastOperate = 0;
  _errorFlag = 0;
  _ErrorReceived = 0;
  _timingErrorActive = 0;
}

void TemperatureModule::operate (unsigned long timeNow){
  _timeLastOperate = timeNow;
  for (int i = 0; i < _NumberOfSensors; i++ ){
    _SensorList [i]->operate (timeNow);
  }
  if (timeNow - _timeLastAlive > TEMPERATUREMODULE_ALIVE_TIMEINTERVAL){
    _timingErrorActive = 1;
    _errorFlag = 1;
  }
  else {
    _timingErrorActive = 0;
  }
}

int8_t TemperatureModule::resetErrorFlagModule (void){
  if (_errorFlag == 0){
    return 0;
  }
  else {
    _errorFlag = 0;
    return 1;
  }
}

void TemperatureModule::setError (int8_t input){
  _errorFlag = 1;
  _ErrorReceived = input;
}

int8_t TemperatureModule::resetErrorFlagOnSensors(int8_t indexNo){
  return _SensorList [indexNo]->resetErrorFlag ();
}

int8_t TemperatureModule::resetErrorFlagOnAllSensors(void){
  int8_t errorFlagCounter = 0;
  for (int i = _NumberOfSensors - 1; i >= 0; i-- ){
    errorFlagCounter = errorFlagCounter << 1;
    errorFlagCounter = errorFlagCounter + _SensorList [i]->resetErrorFlag();
  }
  return errorFlagCounter;
}

int8_t TemperatureModule::getErrorActiveNowModule (void){
  return _timingErrorActive;
}

int8_t TemperatureModule::getErrorActiveNowAnySensor (void){
  int8_t errorAcvtiveCounter = 0;
  for (int i = _NumberOfSensors - 1; i >= 0; i-- ){
    errorAcvtiveCounter = errorAcvtiveCounter << 1;
    errorAcvtiveCounter = errorAcvtiveCounter + _SensorList [i]->getErrorActiveNow();
  }
  return errorAcvtiveCounter;
}

int8_t TemperatureModule::getErrorFlagModule (void){
  return _errorFlag;
}

int8_t TemperatureModule::getReceivedErrorModul (void){
  return _ErrorReceived;
}

int8_t TemperatureModule::getErrorFlagOnSensors(int8_t indexNo){
  return _SensorList [indexNo]->getErrorFlag ();
}

void TemperatureModule::setTemperature (int8_t indexNo, float input){
  _SensorList [indexNo]->setTemperature (input);
  _timeLastAlive = _timeLastOperate;
}

float TemperatureModule::getLastTemperature (int8_t indexNo){
  return _SensorList [indexNo]->getLastTemperature ();
}

float TemperatureModule::getAverageTemperature (int8_t indexNo){
  return _SensorList [indexNo]->getAverageTemperature ();
}

int8_t TemperatureModule::getIdNo (void){
  return _IdNo;
}

int8_t TemperatureModule::getSubIdNo (int8_t indexNo){ // only test
  return _SensorList [indexNo]->getSubIdNo ();
}
