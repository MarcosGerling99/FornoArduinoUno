#include <Arduino.h>
void controleDeTemperatura()
{
    if (Temperatura < (SetPointTemperatura - Histerese))
    {
        TemperaturaBaixa = true;
    }
    else if (Temperatura > (SetPointTemperatura - Histerese + 1))
    {
        if (Temperatura < SetPointTemperatura - 5)
        {
            incremento = 120;
        }
        else
        {
            incremento = 60;
        }

        if (Temperatura < SetPointTemperatura - 2)
        {
            if (ContadorSobe < incremento)
            {
                ContadorSobe++;
            }
            else
            {
                ContadorSobe = 0;
                TemperaturaBaixa = !TemperaturaBaixa;
            }
        }
        else
        {
            TemperaturaBaixa = false;
            ContadorSobe = 0;
        }
    }
}