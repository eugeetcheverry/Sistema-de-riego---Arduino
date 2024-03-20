#include <LiquidCrystal.h>

int lectura;
int sensorpin = A0;
int V0 = 3; 
int RS = 4;
int E = 5;
int D4 = 6;
int D5 = 7;
int D6 = 8;
int D7 = 9;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);


void setup() {
  Serial.begin(9600); 
  
  analogWrite(V0, 50);
  lcd.begin(16,2);
  
}

void loop() {
   lectura = analogRead(sensorpin); 

// pulsos de mas de 1000 indican que el sensor no esta en el suelo o esta desconectado 

  if(lectura >= 1000){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("desconectado");
    
  }
  //pulsos entre 600 y mil indican que el suelo esta seco
  
  else if(lectura<1000 && lectura >=600){
    lcd.setCursor(0,0);
    lcd.print("estoy seca :(");
  }
  //pulsos entre 370 y 600 indican que el suelo esta humedo
  
  else if(lectura<600 && lectura >= 370){
    lcd.setCursor(0,0);
    lcd.print("Feliz :)");
  }
  //pulsos menores a 370 indican que esta muy humedo 
  
  else if(lectura<370){
    lcd.setCursor(0,0);
    lcd.print("me ahogaste :|");
  }

delay(50000);
lcd.clear();
  

}
