#include <Arduino.h>
void bip()
{
    //Serial.print("t:");
    //Serial.println(t);
    if (ligabip && t)
    {
        /* Ligamos o buzzer com uma frequencia de 1500hz*/
        tone(buzzer, 1500);
        /*Esperamos um segundo para finalizar o método*/
    }
    if (ligabip && !t)
    {
        /*Em delay esperamos um segundo para avançar para a próxima linha*/
        noTone(buzzer);
        ligabip = false;
        contabuzer = 0;
    }
}