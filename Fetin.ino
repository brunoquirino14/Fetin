#include <Ultrasonic.h>
//Define os pinos para o trigger e echo
#define pino_trigger 9
#define pino_echo 8
#define pino_vidro 30
#define pino_porta 32

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
const int pinoLed = 7;
const int led = 6;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  pinMode(chave, INPUT);
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADO
  //Define o número de colunas e linhas do LCD
  lcd.begin(20, 4);
  Serial.begin(9600);
  
}
 
void loop()
{
  float sensorVoltage; 
  float sensorValue;
  float estado;
  long distancia;
  distancia = ultrasonic(CM);
  sensorValue = analogRead(A0);
  estado = analogRead(A1);
  sensorVoltage = sensorValue/1024*5.0;

 
  if(estado == 0){ 
      digitalWrite(led, LOW); 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Chave desligada");
      lcd.setCursor(0, 1);
      lcd.print("Sistema travado");
      delay(250);
  }else{ //SENÃO, FAZ
    digitalWrite(led, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
      lcd.print("Chave ligada");
      delay(1000);
       if(sensorVoltage >= 0.5){ 
       lcd.clear();
       digitalWrite(pinoLed, HIGH);
       lcd.setCursor(0, 0);
       lcd.print("Nivel de embriaguez"); //Mostrar "Nível de embriaguez detectado no condutor, sistema de ignição não ativado." no display
       lcd.setCursor(0, 1);
       lcd.print("detectado");
       lcd.setCursor(0, 2);
       lcd.print("Sistema de ignicao");
       lcd.setCursor(0, 3);
       lcd.print("Desligado");
       delay(5000);
  }else{ //SENÃO, FAZ
       lcd.clear();
       digitalWrite(pinoLed, LOW); 
       lcd.setCursor(0, 0);
       lcd.print("Amostra sem");
       lcd.setCursor(0, 1);
       lcd.print("deteccao de alcool");
       delay(5000);
  }
  }

    
  //Rolagem para a esquerda
 // for (int posicao = 0; posicao < 2; posicao++)
 // {
 //   lcd.scrollDisplayLeft();
 //   delay(600);
 // }
 //   
  //Rolagem para a direita
  //for (int posicao = 0; posicao < 2; posicao++)
  //{
   // lcd.scrollDisplayRight();
   // delay(600);
/////}
 
}