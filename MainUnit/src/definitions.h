/*
  Definitions.h - Heatingcontrol by hagre 2018.
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
//************************************************************************
