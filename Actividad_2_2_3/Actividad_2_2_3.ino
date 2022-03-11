#include <Wire.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27,16,2);
int analogPin = A0;
float temp = 0;
float volt = 0;
int adc=0;
const int numLect  = 7;
float Lect [numLect];
float LecO [numLect];
int i  = 0;
float total  = 0;
float media = 0;

float sort_desc(const void *cmp1, const void *cmp2)
{
  float a = *((float *)cmp1);
  float b = *((float *)cmp2);
  return a > b ? -1 : (a < b ? 1 : 0);
}

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Tecnologico de"); 
  lcd.setCursor(3, 1);
  lcd.print("Monterrey");
  Serial.println("Voltaje Temperatura Temperatura_Media Temperatura_Mediana");
  
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T: ");
  lcd.setCursor(3,0);
  adc = analogRead(analogPin);
  volt = adc*(5.000/1023.000);
  temp = volt*10;
  total = total - Lect[i];
  Lect[i] = temp;
  total = total + Lect[i];
  i += 1;
  if (i >= numLect) {
    i = 0;
  }
  media = total / numLect;
  //lcd.print(media);
  for (int i = 0; i < numLect; i++) {
    LecO[i] = Lect[i];
  }
  qsort(LecO, numLect, sizeof(LecO[0]), sort_desc);
  lcd.print(LecO[(numLect-1)/2]);
  lcd.setCursor(9,0);
  lcd.print("'C");
  lcd.setCursor(0,1);
  lcd.print("V: ");
  lcd.setCursor(3,1);
  lcd.print(volt);
  Serial.print(volt);
  Serial.print(',');
  Serial.print(temp);
  Serial.print(',');
  Serial.print(media);
  Serial.print(',');
  Serial.println(LecO[(numLect-1)/2]);
  delay(400);
}
