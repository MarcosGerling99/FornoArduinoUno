#include <Arduino.h>
#include <LiquidCrystal.h>

// Make custom characters:
byte Heart[] = {
    B00000,
    B01010,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000,
    B00000};
byte Bell[] = {
    B00100,
    B01110,
    B01110,
    B01110,
    B11111,
    B00000,
    B00100,
    B00000};
byte Alien[] = {
    B11111,
    B10101,
    B11111,
    B11111,
    B01110,
    B01010,
    B11011,
    B00000};
byte Check[] = {
    B00000,
    B00001,
    B00011,
    B10110,
    B11100,
    B01000,
    B00000,
    B00000};
byte Speaker[] = {
    B00001,
    B00011,
    B01111,
    B01111,
    B01111,
    B00011,
    B00001,
    B00000};
byte Sound[] = {
    B00001,
    B00011,
    B00101,
    B01001,
    B01001,
    B01011,
    B11011,
    B11000};
byte Skull[] = {
    B00000,
    B01110,
    B10101,
    B11011,
    B01110,
    B01110,
    B00000,
    B00000};
byte Lock[] = {
    B01110,
    B10001,
    B10001,
    B11111,
    B11011,
    B11011,
    B11111,
    B00000};

//defining House Icon
byte housechar1[8] = {
    B00000,
    B00001,
    B00011,
    B00011, //Row 0, Col 0
    B00111,
    B01111,
    B01111,
    B11111,
};
byte housechar2[8] = {
    B11111,
    B11111,
    B11100,
    B11100, //Row 1, Col 0
    B11100,
    B11100,
    B11100,
    B11100,
};
byte housechar3[8] = {
    B00000,
    B10010,
    B11010,
    B11010, //ROW 0, Col 1
    B11110,
    B11110,
    B11110,
    B11111,
};
byte housechar4[8] = {
    B11111,
    B11111,
    B11111,
    B10001, //Row 1, Col 1
    B10001,
    B10001,
    B11111,
    B11111,
};
//Definining Termometer Icon
byte tempchar1[8] = {
    B00000,
    B00001,
    B00010,
    B00100, //Row 0, Col 2
    B00100,
    B00100,
    B00100,
    B00111,
};
byte tempchar2[8] = {
    B00111,
    B00111,
    B00111,
    B01111, //Row 1, Col 2
    B11111,
    B11111,
    B01111,
    B00011,
};
byte tempchar3[8] = {
    B00000,
    B10000,
    B01011,
    B00100, //ROW 0, Col 3
    B00111,
    B00100,
    B00111,
    B11100,
};
byte tempchar4[8] = {
    B11111,
    B11100,
    B11100,
    B11110, //Row 1, Col 3
    B11111,
    B11111,
    B11110,
    B11000,
};

//Defining Humidity Icon
byte humchar1[8] = {
    B00000,
    B00001,
    B00011,
    B00011,
    B00111,
    B01111,
    B01111,
    B11111,
};
byte humchar2[8] = {
    B11111,
    B11111,
    B11111,
    B01111,
    B00011,
    B00000,
    B00000,
    B00000,
};
byte humchar3[8] = {
    B00000,
    B10000,
    B11000,
    B11000,
    B11100,
    B11110,
    B11110,
    B11111,
};
byte humchar4[8] = {
    B11111,
    B11111,
    B11111,
    B11110,
    B11100,
    B00000,
    B00000,
    B00000,
};

/*

  // Create a new characters:
  lcd.createChar(0, Heart);
  lcd.createChar(1, Bell);
  lcd.createChar(2, Alien);
  lcd.createChar(3, Check);
  lcd.createChar(4, Speaker);
  lcd.createChar(5, Sound);
  lcd.createChar(6, Skull);
  lcd.createChar(7, Lock);

  */

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // select the pins used on the LCD panel

void IconeTemperatura()
{
  lcd.clear();
  delay(1000);
  lcd.createChar(1, tempchar1);
  lcd.createChar(2, tempchar2);
  lcd.createChar(3, tempchar3);
  lcd.createChar(4, tempchar4);
  lcd.setCursor(0, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.write(2);
  lcd.setCursor(1, 0);
  lcd.write(3);
  lcd.setCursor(1, 1);
  lcd.write(4);
  lcd.setCursor(3, 0);
}

void IconeCasa()
{
  lcd.clear();
  lcd.createChar(1, housechar1);
  lcd.createChar(2, housechar2);
  lcd.createChar(3, housechar3);
  lcd.createChar(4, housechar4);
  lcd.setCursor(0, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.write(2);
  lcd.setCursor(1, 0);
  lcd.write(3);
  lcd.setCursor(1, 1);
  lcd.write(4);
  lcd.setCursor(3, 0);
}

void Iconeumidade()
{
  lcd.clear();
  lcd.createChar(1, humchar1);
  lcd.createChar(2, humchar2);
  lcd.createChar(3, humchar3);
  lcd.createChar(4, humchar4);
  lcd.setCursor(0, 0);
  lcd.write(1);
  lcd.setCursor(0, 1);
  lcd.write(2);
  lcd.setCursor(1, 0);
  lcd.write(3);
  lcd.setCursor(1, 1);
  lcd.write(4);
  lcd.setCursor(3, 0);
}

// FUNÇÕES ONDE ESTA A TELA PRINCIPAL
void telaprincipal()
{
  // Menu principal mostra todos os dados
  lcd.clear(); // Limpa o LCD
  //IconeTemperatura();
  lcd.setCursor(13, 0);
  lcd.print("(C)");
  lcd.setCursor(13, 1);
  lcd.print("min");
}

void ChamaSetpointTemperatura()
{
  unsigned temperatura = (SetPointTemperatura / 10);
  lcd.setCursor(3, 1);
  lcd.print(SetPointTemperatura);
  if (temperatura < 10)
  {
    lcd.setCursor(3, 1);
    lcd.print(' ');
  }
}

// Tela do Set Oint de temperatura
void telaSetpointTemperatura()
{
  // Menu principal mostra todos os dados
  //lcd.clear(); // Limpa o LCD
  Iconeumidade();
  lcd.setCursor(5, 0);
  lcd.print("Temperatura");
  ChamaSetpointTemperatura();
  lcd.setCursor(10, 1);
  lcd.print("C");
}

void ChamaSetpointTempo()
{
  unsigned tempo = (SetPointTempo / 10);
  lcd.setCursor(3, 1);
  lcd.print(SetPointTempo);
  if (tempo < 10)
  {
    lcd.setCursor(5, 1);
    lcd.print(' ');
  }
}

// tela do set point de tempo
void telaSetPointTempo()
{
  //lcd.clear(); // Limpa o LCDks
  IconeCasa();
  lcd.setCursor(5, 0);
  lcd.print("Temporizador");
  ChamaSetpointTempo();
  lcd.setCursor(10, 1);
  lcd.print("min");
}

void Minutos(unsigned posicaoInicial)
{
  lcd.setCursor(posicaoInicial, 1);
  lcd.print(':');
  lcd.setCursor(posicaoInicial + 1, 1);
  lcd.print(MinutoAtual);
  if (MinutoAtual < 10)
  {
    lcd.print(' ');
  }
}

void DadosTelaPrincipal()
{
  lcd.setCursor(0, 0);
  lcd.print(Temperatura);

  if (TempoAtual >= 100)
  {
    lcd.setCursor(0, 1);
    lcd.print(TempoAtual);
    Minutos(3);
  }
  else if (TempoAtual < 100 && TempoAtual >= 10)
  {
    lcd.setCursor(0, 1);
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(TempoAtual);
    Minutos(3);
  }
  else if (TempoAtual < 10 && TempoAtual > 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("00");
    lcd.setCursor(2, 1);
    lcd.print(TempoAtual);
    Minutos(3);
  }
  else if (TempoAtual == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("000");
    Minutos(3);
  }
}

void AjustesPot()
{
  lcd.setCursor(9, 0);
  lcd.print(SetPointTemperatura);
  if (SetPointTemperatura < 100)
  {
    lcd.setCursor(11, 0);
    lcd.print(' ');
  }
  if (SetPointTemperatura < 10)
  {
    lcd.setCursor(10, 0);
    lcd.print(' ');
  }
  lcd.setCursor(9, 1);
  lcd.print(SetPointTempo);
  if (SetPointTempo < 100)
  {
    lcd.setCursor(11, 1);
  }
  lcd.print(' ');
  if (SetPointTempo < 10)
  {
    lcd.setCursor(10, 1);
    lcd.print(' ');
  }
}
