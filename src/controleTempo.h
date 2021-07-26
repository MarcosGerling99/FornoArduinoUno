#include <Arduino.h>
void FuncaoTimerForno()
{
    if (!ligamemoria && Liga)
    {
        MinutoAtual = 60;
        TempoAtual = TempoAtual - 1;
        ligamemoria = true;
    }

    if (Liga)
    {
        if (MinutoAtual > 0)
        {
            MinutoAtual--;
        }
        else
        {
            if (MinutoAtual == 0 && TempoAtual == 0)
            {
                Liga = false;
                bip();
                ligamemoria = false;
            }
            else
            {
                TempoAtual--;
                MinutoAtual = 60;
            }
        }
    }
}
