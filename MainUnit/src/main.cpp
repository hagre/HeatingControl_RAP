/************************************************************************
 *                     Solarheatingcontrol for RAP
 *                              2018
 *
 *                            MAIN UNIT
 *
 *                             by hagre
 * **********************************************************************
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

Diese Anlage besteht aus einer Hauptregeleinheit, die über CANbus mit den anderen Komponenten verbunden ist.
- Die Hauptregeleinheit bestitzt:
  + 1x MODESELEKTOR (automatisch oder manuell)
  + 4x DREHSCHALTER für manuelle Veltilsteuerung
  + 1x Encoder für das umschalten/zwischen den verschiedenen Regelzuständen
  + Relayausgänge um die mit 12v Versorgten Komponenten resetten zu können (öffner)
  + Watchdogtimer
  + 1x CANbus Schnittstelle
  + Hardware EEPROM Erweiterung (Arduion Due hat sonst keinen EEPROM)
  + EEPROM speicherung der Parameter, ID/Adressen der Komponenten, letzter Zustand,
- Temparatursensoren, Sonnenintensitätssensoren, ... werden auf von zusätzlichen Kontrolern zusammengefasst und über CANbus gemeldet.
- Stellglieder (Schrittmotor gesteuerte 4 Wegeventile)
- Eine LCD/TFT Einheit zeigt alle relevanten Daten auf mehreren Displays (Schalttafel der Steuerungshaupteinheit)
- Eine oder mehrere LCD/TFT Fernbedienungen
 */

#include <Arduino.h>
#include "definitions.h"

#include "TemperatureSensor.h"
#include "TemperatureModule.h"
#include "ValveMotorModul.h"

TemperatureSensor Puffer;
TemperatureSensor Puffer2;
TemperatureSensor *mySensorArray []= {&Puffer,&Puffer2};

TemperatureSensor Puffer3;
TemperatureSensor Puffer4;
TemperatureSensor *mySensorArray2 []= {&Puffer3,&Puffer4};

TemperatureModule tempModule1;
TemperatureModule tempModule2;
TemperatureModule *tempModuleArray [] = {&tempModule1, &tempModule2};

ValveMotorModul motorModul1;
ValveMotorModul motorModul2;
//ValveMotorModul *motorModuleArray [] = {&motorModul1, &motorModul2};

void setup() {
  Serial.begin(SERIALSPEED);
    Puffer.initSensor(15);
    Puffer2.initSensor(16);
    tempModule1.initModule(0, 2, mySensorArray);
    tempModule2.initModule(1, 2, mySensorArray2);
    motorModul1.initMotorModul(0);
    motorModul2.initMotorModul(1);

    Serial.println ("First Test Sensor: ");

    Serial.println (Puffer.getSubIdNo());
    Serial.println (tempModule1.getSubIdNo(0));
    Serial.println (Puffer2.getSubIdNo());
    Serial.println (tempModule1.getSubIdNo(1));

    Serial.println ("END Test Sensor: ");

}

void loop() {
  Puffer.setTemperature(50.0);
  tempModule1.setTemperature(1, 5.0);
  tempModule1.operate(millis());
  Serial.println (Puffer.getSubIdNo());

  Serial.println (Puffer.getAverageTemperature());
  Serial.println (tempModule1.getAverageTemperature(0));
  Serial.println (Puffer2.getSubIdNo());

  Serial.println (Puffer2.getAverageTemperature());
  Serial.println (tempModule1.getAverageTemperature(1));
  Serial.println ("-");
  delay (200);
}
