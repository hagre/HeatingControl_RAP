/*
 *  OutputSignal.h - Heatingcontrol by hagre 2018.
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

#ifndef outputsignal_h
#define outputsignal_h

class OutputSignal {

  public:
    OutputSignal (void);
    void initOutput (int8_t subIdNo);

    void operate (unsigned long timeNow);
    void setTargetValue (float_t input);
    void setTargetValue (int8_t input);
    void setActualValue (float_t input);
    void setActualValue (int8_t input);

    float_t getTargetValueAnalog (void);
    int8_t getTargetValueDigital (void);
    float_t getActualValueAnalog (void);
    int8_t getActualValueDigital (void);

    int8_t resetErrorFlag (void);
    int8_t getErrorActiveNow (void);
    int8_t getErrorFlag (void);

    int8_t getSubIdNo (void);

  private:
    float_t _TargetValue;
    float_t _ActualValue;

    unsigned long _timeLastCalculate;
    unsigned long _timeLastAlive;
    unsigned long _timeLastOperate;

    int8_t _errorFlag;
    int8_t _timingErrorActive;

    int8_t _subIdNo;
};

#endif
