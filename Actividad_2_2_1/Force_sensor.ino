// C++ code
//
int adc = 0;
float F = 0;
double v = 0.0;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
	adc = analogRead(A0);
  	v = adc*5.000/1023.000;
  Serial.print("ADC: ");
  Serial.print(adc);
  Serial.print("\t V: ");
  Serial.print(v,4);
  Serial.print("\t");
  
  if(v>=0 && v<=2.5171){
    F = 0.0335*(v*v) + 0.1094*v + 0.0049;}
  else if(v>2.5171 && v<3.6559){
    F = 0.9242*(v*v) - 4.4255*v + 5.8066;}
    else if(v>=3.6559){
    F = 20.779*(v*v*v*v) - 321.22*(v*v*v) + 1866.6*(v*v) - 4827.8*v + 4687.9 ;
  }
    Serial.print("F: ");
    Serial.print(F);
	Serial.println();
}
