#include <Arduino.h>
void temporizador()
{
    unsigned long tempoatual = millis();
    if (tempoatual > tempoanterior + 1000)
    {
        FuncaoTimerForno();

        if (!t)
        {
            t = true;
        }
        else
        {
            t = false;
        }
        if (tela == 0)
        {
            DadosTelaPrincipal();
        }
        if (tela > 0)
        {
            if (tempoParametros < SetPointTempoParametros)
            {
                tempoParametros++;
            }
            else
            {
                tempoParametros = 0;
                tela = 0;
                telaprincipal();
            }
        }

        if ((SetPointTempo > UltimoSetPoint + 1) || (SetPointTempo < UltimoSetPoint -1))
        {
            TempoAlterar++;
            
        }

        if (TempoAlterar == SetPointTempoAlterar)
        {
            UltimoSetPoint = SetPointTempo;
            TempoAtual = SetPointTempo;
            TempoAlterar = 0;

        }
        //Serial.print("tela:");
        //Serial.println(tela);
        //Serial.print("SetPoint:");
        //Serial.println(Temperatura);
        // Serial.print("offset");
        // Serial.println(Offset);
        // Serial.print("botao:");
        // Serial.println(botao);
        Temperatura = ktc.readCelsius();
        //Serial.print("Temperatura: ");   //IMPRIME O TEXTO NO MONITOR SERIAL
        //Serial.print(ktc.readCelsius()); //IMPRIME NO MONITOR SERIAL A TEMPERATURA MEDIDA
        //Serial.println("*C");            //IMPRIME O TEXTO NO MONITOR SERIAL

        Serial.print("TempoAlterar: ");
        Serial.println(TempoAlterar);

        //Serial.print("SetPointTemperatura");
        //Serial.println(SetPointTemperatura);

        tempoanterior = tempoatual;
    }
}