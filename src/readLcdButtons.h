#include <Arduino.h>
// Variaveis do LCD.
int read_LCD_buttons()
{                               // read the buttons
    adc_key_in = analogRead(0); // read the value from the sensor

    // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
    // we add approx 50 to those values and check to see if we are close
    // We make this the 1st option for speed reasons since it will be the most likely result

    if (adc_key_in > 1000)
    {
        return btnNONE;
    }
    else
    {
        tempoParametros = 0;
    }
    // For V1.1 us this threshold
    if (adc_key_in < 50)
    {
        return btnRIGHT; //50
    }
    if (adc_key_in < 250)
    {
        return btnUP; // 250
    }
    if (adc_key_in < 450)
    {
        return btnDOWN; //450
    }
    if (adc_key_in < 650)
    {
        return btnLEFT; //650
    }
    if (adc_key_in < 850)
    {
        return btnSELECT; // era 850
    }

    return btnNONE; // when all others fail, return this.
}