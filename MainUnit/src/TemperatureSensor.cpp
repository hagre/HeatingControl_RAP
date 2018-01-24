/*
 *  TemperatureSensor.cpp - Heatingcontrol by hagre 2018.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "Arduino.h"
#include "definitions.h"

#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor (void){
}

void TemperatureSensor::initSensor (int8_t subIdNo){
  _subIdNo = subIdNo;
  setInitialTemperature(0);
  _readIndex = -1;
  _total = 0;
  _average = 0;
  _timeLastCalculate = 0;
  _timeLastAlive = 0;
  _timeLastOperate = 0;
  _errorFlag = 0;
  _timingErrorActive = 0;
}

void TemperatureSensor::operate (unsigned long timeNow){
  _timeLastOperate = timeNow;
  if (timeNow - _timeLastCalculate > TEMPERATURESENSOR_AVERAGE_TIMEDELAY_OF_READINGS){
    makeAverage (_input);
    _timeLastCalculate = timeNow;
  }
  if (timeNow - _timeLastAlive > TEMPERATURESENSOR_ALIVE_TIMEINTERVAL){
    _timingErrorActive = 1;
    _errorFlag = 1;
  }
  else {
    _timingErrorActive = 0;
  }
}

void TemperatureSensor::setTemperature (float_t input){
  _input = input;
  _timeLastAlive = _timeLastOperate;
}

void TemperatureSensor::makeAverage (float_t input){
  _readIndex = _readIndex + 1;
  if (_readIndex >= _numReadings) {
    _readIndex = 0;
  }
  _total = _total - _readings[_readIndex];
  _readings[_readIndex] = input;
  _total = _total + _readings[_readIndex];
  _average = _total / _numReadings;
}

void TemperatureSensor::setInitialTemperature (float_t input){
  for (int8_t i = 0; i < _numReadings; i++) {
    _readings[i] = input;
  }
  _input = input;
}

float_t TemperatureSensor::getLastTemperature (void) {
  return _readings[_readIndex];
}

float_t TemperatureSensor::getAverageTemperature (void){
  return _average;
}

int8_t TemperatureSensor::resetErrorFlag (void){
  if (_errorFlag == 0){
    return 0;
  }
  else {
    _errorFlag = 0;
    return 1;
  }
}

int8_t TemperatureSensor::getErrorActiveNow (void){
  return _timingErrorActive;
}

int8_t TemperatureSensor::getErrorFlag (void){
  return _errorFlag;
}

int8_t TemperatureSensor::getSubIdNo (void){
  return _subIdNo;
}
