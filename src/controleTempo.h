#include <Arduino.h>
void FuncaoTimerForno()
{
    if (Liga && TempoAtual > 0)
    {
        TempoAtual--;
    }
    else
    {
        Liga = false;
        TempoAtual = 0;
    }
}
