#include <Arduino.h>
#include <EEPROM.h>
void grava()
{
    int eeAddress = 0;
    EEPROM.put(eeAddress, SetPointTemperatura);
    eeAddress = 2;
    //EEPROM.put(eeAddress, Offset);
}

void ler()
{
    int eeAddress = 0;
    unsigned int set = 0, off = 0;
    EEPROM.get(eeAddress, set);
    eeAddress = 2;
    EEPROM.get(eeAddress, off);
    if (set > 0 && set < 65535)
    {
        SetPointTemperatura = set;
    }
    else
    {
        SetPointTemperatura = 100;
    }
    if (off > 0 && off < 65535)
    {
       // Offset = off;
    }
    else
    {
        //Offset = 5;
    }
    Serial.print("Set");
    Serial.println(SetPointTemperatura);
}