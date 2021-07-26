#include <Arduino.h>
void bip()
{
    //Serial.print("t:");
    //Serial.println(t);
    //if (ligabip && t)
    //{
        /* Ligamos o buzzer com uma frequencia de 1500hz*/
        tone(buzzer, 1500);
        /*Esperamos um segundo para finalizar o método*/
        /*Em delay esperamos um segundo para avançar para a próxima linha*/
        delay(1000);
        noTone(buzzer);
       

}