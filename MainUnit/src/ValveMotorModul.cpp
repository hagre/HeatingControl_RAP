/*
 *  ValveMotorModul.cpp - Heatingcontrol by hagre 2018.
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

#include "ValveMotorModul.h"

ValveMotorModul::ValveMotorModul (void){
}

void ValveMotorModul::initMotorModul (int8_t IdNo){
  _IdNo = IdNo;
  _ActualPosition = 0;
  _TargetPosition = 0;
  _ErrorReceived = 0;
  _timeLastAlive = 0;
  _timeLastOperate = 0;
  _errorFlag = 0;
  _timingErrorActive = 0;
}

void ValveMotorModul::operate (unsigned long timeNow){
  _timeLastOperate = timeNow;
  if (timeNow - _timeLastAlive > VALVEMOTOR_ALIVE_TIMEINTERVAL){
    _timingErrorActive = 1;
    _errorFlag = 1;
  }
  else {
    _timingErrorActive = 0;
  }
}

void ValveMotorModul::setActualPosition (float_t input){
  _ActualPosition = input;
  _timeLastAlive = _timeLastOperate;
}

void ValveMotorModul::setTargetPosition (float_t input){
  _TargetPosition = input;
}

void ValveMotorModul::setError (int input){
  _errorFlag = 1;
  _ErrorReceived = input;
}

int8_t ValveMotorModul::getReveivedError (void){
  return _ErrorReceived;
}

float_t ValveMotorModul::getActualPosition (void) {
  return _ActualPosition;
}

float_t ValveMotorModul::getTargetPosition (void){
  return _TargetPosition;
}

int8_t ValveMotorModul::resetErrorFlag (void){
  if (_errorFlag == 0){
    return 0;
  }
  else {
    _errorFlag = 0;
    return 1;
  }
}

int8_t ValveMotorModul::getErrorActiveNow (void){
  return _timingErrorActive;
}

int8_t ValveMotorModul::getErrorFlag (void){
  return _errorFlag;
}

int8_t ValveMotorModul::getIdNo (void){
  return _IdNo;
}
