// Autor: Marcos Gerling.
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Wire.h>
#include "max6675.h"

int ktcSO = 11;  //PINO DIGITAL (SO)
int ktcCS = 12;  //PINO DIGITAL (CS)
int ktcCLK = 13; //PINO DIGITAL (CLK / SCK)

MAX6675 ktc(ktcCLK, ktcCS, ktcSO); //CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CLK, CS, SO)

/* Entradas ou saidas disponiveis
Entradas 2,3,11,12,13
2 = fio azul;
3 = fio verde;
11 = branco;
12 = marrom;
13 = branco do marrom;
*/
float Temperatura = 0.0;
unsigned int TempoAtual = 0;
unsigned int SetPointTemperatura = 100.0;
unsigned int SetPointTempo = 10;
unsigned int tela = 0;
unsigned int SetPointTempoParametros = 20;
unsigned int tempoParametros = 0;
unsigned long tempoanterior = 0;
byte contabuzer = 0;
byte contateladados = 0;
byte botao = 0;
bool t = false;
bool ligabip = false;
bool Liga = false;
// define some values used by the panel and buttons
int lcd_key = 0;
int adc_key_in = 0;

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

#define LedDisplay 10

#define buzzer 3 //Constante armazenando o número do pino que vamos utilizar
#define rele 2   // Rele que liga a resistencia
#define BotaoLiga A1
#define PotenciometroTemp A2
#define PotenciometroTimer A3

#include <telas.h>
#include <bip.h>
#include <controleTempo.h>
#include <temporizador.h>
#include <eprom.h>
#include <readLcdButtons.h>

void setup()
{
  //Declara as variaveis do LCD
  pinMode(LedDisplay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rele, OUTPUT);
  pinMode(BotaoLiga, INPUT);
  digitalWrite(LedDisplay, HIGH);
  digitalWrite(buzzer, LOW);
  digitalWrite(rele, LOW);
  lcd.begin(16, 2);    // start the library
  lcd.setCursor(0, 0); // set the LCD cursor   position
  lcd.print("Controle forno");
  lcd.setCursor(0, 1);
  lcd.print("Autor: Marcos G.");
  delay(4000);
  ler();           // Chama a eeprom
  telaprincipal(); // Chama a tela principal
  Serial.begin(9600);
}

void NavegacaoTelas(unsigned NumeroTela, bool botao)
{
  bool processou = false;
  if (tela == 0 && botao && !processou)
  {
    telaSetpointTemperatura();
    tela = 1;
    processou = true;
  }
  else if (tela == 1 && !processou)
  {
    if (botao)
    {
      tela = 2;
      telaSetPointTempo();
    }
    else
    {
      tela = 0;
      telaprincipal();
    }
    processou = true;
  }
  else if (tela == 2 && !processou)
  {
    telaprincipal();
    if (botao)
    {
      tela = 0;
      telaprincipal();
    }
    else
    {
      tela = 1;
      telaSetPointTempo();
    }
    processou = true;
  }
}

void setPoint(char tecla)
{
  if (tela == 1)
  {
    if (tecla == 'u')
    {
      SetPointTemperatura++;
      ChamaSetpointTemperatura();
    }
    else
    {
      SetPointTemperatura--;
      ChamaSetpointTemperatura();
    }
    delay(300);
  }
  else if (tela == 2)
  {
    if (tecla == 'u')
    {
      SetPointTempo++;
      ChamaSetpointTempo();
    }
    else
    {
      SetPointTempo--;
      ChamaSetpointTempo();
    }
    delay(300);
  }
}

void loop()
{
  // ligabip = true;

  if (digitalRead(BotaoLiga) == HIGH)
  {
    if (Liga == false)
    {
      Liga = true;
      TempoAtual = SetPointTempo;
      delay(300);
    }
    else
    {
      Liga = false;
      delay(300);
    }
  }

  if (Liga)
  {
    digitalWrite(rele, HIGH);
  }
  else
  {
    digitalWrite(rele, LOW);
  }

  temporizador();

  botao = read_LCD_buttons(); // CONTINUAR DAQUI...

  switch (botao)
  {
  case btnSELECT:
  {
    if (tela == 1)
    {
      //SetPoint = Medida;
    }
    tela = 0;
    telaprincipal();
    //grava();
  }
  break;

  case btnRIGHT:
  {
    NavegacaoTelas(tela, true);
    delay(200);
  }
  break;

  case btnLEFT:
  {
    NavegacaoTelas(tela, false);
    delay(200);
  }
  break;
  case btnUP:
  {
    setPoint('u');
  }
  break;

  case btnDOWN:
  {
    setPoint('d');
  }
  break;
  }
}
