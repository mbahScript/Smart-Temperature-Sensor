#include <LiquidCrystal.h>
#define RS 12
#define EN 11
#define D4 10
#define D5 9
#define D6 8
#define D7 7
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
const int Sensor = A0;
int lamp = 6;
float tempc;
float tempf;
float Vout;
float temp;
void setup() {
  // put your setup code here, to run once:
  for(int i=6;i<13;i++){
    pinMode(i,OUTPUT);
  }
pinMode(Sensor, INPUT);
lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("  TEMPERATURE ");
lcd.setCursor(0,1);
lcd.print(" DIGITAL METER ");
delay(500);
lcd.clear();
digitalWrite(lamp, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
Vout = analogRead(Sensor);// read analog volt from sensor and save to variable Vout
temp = (Vout*500)/1023;// converts the analog volt to its temperature equivalent.
tempc = temp;// storing value in degree celsius...
tempf = (tempc*1.8)+32;// conveting to Fahrenheit..
lcd.setCursor(0,0);
lcd.print("DegreeC ");
lcd.print(temp);// display temperature value
lcd.setCursor(0,1);
lcd.print("Fahrenheit ");
lcd.print(tempf);// displays in fahrenheit
delay(1000);// update sensor reading each one second
if(temp>37.59){
  digitalWrite(lamp, LOW);
}else{
  digitalWrite(lamp, HIGH);
}
}
