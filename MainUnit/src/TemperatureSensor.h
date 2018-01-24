/*
 *  TemperatureSensor.h - Heatingcontrol by hagre 2018.
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
