/*
 *  OutputSignal.cpp - Heatingcontrol by hagre 2018.
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

#include "OutputSignal.h"

OutputSignal::OutputSignal (void){
}

void OutputSignal::initOutput (int8_t subIdNo){
  _subIdNo = subIdNo;
  _timeLastAlive = 0;
  _timeLastOperate = 0;
  _errorFlag = 0;
  _timingErrorActive = 0;
  _TargetValue = 0;
  _ActualValue = 0;
}

void OutputSignal::operate (unsigned long timeNow){
  _timeLastOperate = timeNow;
  if (timeNow - _timeLastAlive > TEMPERATURESENSOR_ALIVE_TIMEINTERVAL){
    _timingErrorActive = 1;
    _errorFlag = 1;
  }
  else {
    _timingErrorActive = 0;
  }
}

void OutputSignal::setActualValue (float_t input){
  _ActualValue = input;
  _timeLastAlive = _timeLastOperate;
}

void OutputSignal::setActualValue (int8_t input){
  _ActualValue = float (input);
  _timeLastAlive = _timeLastOperate;
}

void OutputSignal::setTargetValue (float_t input){
  _TargetValue = input;
}

void OutputSignal::setTargetValue (int8_t input){
  _TargetValue = float (input);
}

float_t OutputSignal::getActualValueAnalog (void) {
  return _ActualValue;
}

float_t OutputSignal::getTargetValueAnalog (void) {
  return _TargetValue;
}

int8_t OutputSignal::getActualValueDigital (void) {
  return int (_ActualValue);
}

int8_t OutputSignal::getTargetValueDigital (void) {
  return int(_TargetValue);
}

int8_t OutputSignal::resetErrorFlag (void){
  if (_errorFlag == 0){
    return 0;
  }
  else {
    _errorFlag = 0;
    return 1;
  }
}

int8_t OutputSignal::getErrorActiveNow (void){
  return _timingErrorActive;
}

int8_t OutputSignal::getErrorFlag (void){
  return _errorFlag;
}

int8_t OutputSignal::getSubIdNo (void){
  return _subIdNo;
}
