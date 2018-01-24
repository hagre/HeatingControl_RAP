/*
 *  ValveMotorModul.h - Heatingcontrol by hagre 2018.
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

#ifndef valvemotormodul_h
#define valvemotormodul_h

class ValveMotorModul {

  public:
    ValveMotorModul (void);
    void initMotorModul (int8_t IdNo);

    void operate (unsigned long timeNow);
    void setActualPosition (float_t input);
    void setTargetPosition (float_t input);
    void setError (int input);

    float_t getActualPosition (void);
    float_t getTargetPosition (void);

    int8_t resetErrorFlag (void);
    int8_t getErrorActiveNow (void);
    int8_t getReveivedError (void);
    int8_t getErrorFlag (void);

    int8_t getIdNo (void);

  private:
    float_t _ActualPosition;
    float_t _TargetPosition;

    unsigned long _timeLastAlive;
    unsigned long _timeLastOperate;

    int8_t _errorFlag;
    int8_t _ErrorReceived;
    int8_t _timingErrorActive;

    int8_t _IdNo;
};

#endif
