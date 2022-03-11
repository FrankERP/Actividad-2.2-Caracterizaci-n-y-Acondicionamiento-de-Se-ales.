
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int analogPin = A1;
float temp = 0;
float volt = 0;
int adc=0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Tecnologico de"); 
  lcd.setCursor(3, 1);
  lcd.print("Monterrey");
  
  
  while(true){
  delay(100);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("La temperatura ");
  lcd.setCursor(1,1);
  lcd.print("es : ");
  lcd.setCursor(6,1);
  adc = analogRead(analogPin);
  volt = adc*5.000/1023.000;
  temp = (33.0)*(volt-2.25)+25;
  lcd.print(temp);
  }
}
 
