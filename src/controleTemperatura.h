#include <Arduino.h>
void controleDeTemperatura()
{
    if (Temperatura < (SetPointTemperatura - Histerese))
    {
        TemperaturaBaixa = true;
    }
    if (Temperatura > (SetPointTemperatura + Histerese))
    {
        TemperaturaBaixa = false;
    }
}
