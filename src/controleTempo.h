#include <Arduino.h>
void FuncaoTimerForno()
{
    if (!ligamemoria && Liga)
    {
        MinutoAtual = 59;
        ligamemoria = true;
    }

    if (Liga && TempoAtual > 1 && MinutoAtual > 0)
    {
        if (MinutoAtual > 0)
        {
            MinutoAtual--;
        }
        else
        {
            if (TempoAtual > 1)
            {
                TempoAtual--;
            }
            MinutoAtual = 59;
        }
    }
    else
    {
        if (Liga)
        {
            bip();
        }
        Liga = false;
        TempoAtual = 0;
        MinutoAtual = 0;
        ligamemoria = false;
    }
}
