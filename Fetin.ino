//Programa: Display LCD 16x2
//Autor: MakerHero
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(13, 11, 5, 4, 6, 2);
const int pinoLed = 12; //PINO DIGITAL UTILIZADO PELO LED
const int pinoSensor = 3; //PINO DIGITAL UTILIZADO PELO SENSOR
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
}
 
void loop()
{
  if(digitalRead(pinoSensor) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      digitalWrite(pinoLed, HIGH); //ACENDE O LED
  }else{ //SENÃO, FAZ
    digitalWrite(pinoLed, LOW); //APAGA O LED
  }
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Vencemos a fetin!!!");
  lcd.setCursor(3, 1);
  lcd.print(" LCD 16x2");
  delay(5000);
    
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 20; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(1000);
  }
    
  //Rolagem para a direita
  //for (int posicao = 0; posicao < 6; posicao++)
  //{
    //lcd.scrollDisplayRight();
    //delay(1000);
  //}
}