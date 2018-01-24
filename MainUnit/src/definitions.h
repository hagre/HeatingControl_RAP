/*
 *  Definitions.h - Heatingcontrol by hagre 2018.
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

#define SOFTWARE_VERSION 0
#define SOFTWARE_SUB_VERSION 5


//*************** Overall ************************************************
#define SERIALSPEED 115200
#define ID_NAME_LEN 8
//************************************************************************


//*************** TemperatureSensor.h *************************************
#define TEMPERATURESENSOR_AVERAGE_NUMBER_OF_READINGS 5 //1min
#define TEMPERATURESENSOR_AVERAGE_TIMEDELAY_OF_READINGS 1000 //10sec
#define TEMPERATURESENSOR_ALIVE_TIMEINTERVAL 5000 //10sec
#define TEMPERATURESENSOR_ID_NAME_LEN ID_NAME_LEN
//************************************************************************

//*************** TemperatureModul.h *************************************
#define TEMPERATUREMODULE_ALIVE_TIMEINTERVAL 5000 //10sec
//************************************************************************

//*************** ValveMotor.h *******************************************
#define VALVEMOTOR_ALIVE_TIMEINTERVAL 5000 //10sec
//************************************************************************
