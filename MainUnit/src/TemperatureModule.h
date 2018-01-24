/*
 *  TemperatureModule.h - Heatingcontrol by hagre 2018.
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
