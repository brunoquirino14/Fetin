
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
const int pinoLed = 7;
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  digitalWrite(pinoLed, HIGH); //LED INICIA DESLIGADO
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  //Serial.begin(9600);
}
 
void loop()
{
  float sensorVoltage; 
  float sensorValue;
  sensorValue = analogRead(A0);
  sensorVoltage = sensorValue/1024*5.0;
  if(sensorVoltage >= 0.3){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
      digitalWrite(pinoLed, LOW); //ACENDE O LED
  }else{ //SENÃO, FAZ
    digitalWrite(pinoLed, HIGH); //APAGA O LED
  }
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(2, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Vencemos a FETIN");
  lcd.setCursor(2, 1);
  lcd.print("Tensao sensor:");
  lcd.print(sensorVoltage);
  delay(5000);
    
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 2; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(600);
  }
    
  //Rolagem para a direita
  for (int posicao = 0; posicao < 2; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(600);
  }
 
}