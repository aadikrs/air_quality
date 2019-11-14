#include <LiquidCrystal.h>
const int rs = 12, e = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float t=0;
void setup() 

{                

  lcd.begin(16, 2);
  lcd.clear(); 
  lcd.print("Welcome");
  delay(1000);
  lcd.clear();
  lcd.print(" To "); 
  delay(1000);
  lcd.clear();
  lcd.print("AIR");
  delay(1000); 
  lcd.clear();
  lcd.print("QUALITY MONITOR");  
  delay(1000); 
  lcd.clear();
  lcd.print (" Calibrating :");
  delay (3000);
  lcd.clear();
  lcd.print("Done");
  delay(1000);
  lcd.clear();
  lcd.print("AQ=Air Quality");
  delay(1000);
  lcd.clear();
  Serial.begin(9600);

 }

void loop()

{

  delay(100);
  t = analogRead(A0); 
  Serial.println("Airquality = ");
  Serial.println(t);
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.clear();
  lcd.print ("AQ : ");
  lcd.print (t);
  lcd.print (" PPM ");
  delay(1000);
  lcd.setCursor (0,1);
  if (t<=200)
    {
     lcd.print("FRESH AIR");
     Serial.println("FRESH AIR");
    }
  else if (t>=200 && t<250)
   {
   lcd.print("Not Fresh Air");
   Serial.println("Not Fresh Air ");
  }
  else if( t>=250 && t<=500 )
  {
   lcd.print("Poor Air");
   Serial.println("Poor Air");
  }
  else if (t>=500 && t<1000 )
  {
  lcd.print("Very Poor");
  Serial.println("Very Poor");  
  }
  else
  {
    lcd.print("Polluted Air");
    Serial.println("Polluted Air");
  }
  delay(5000);
  lcd.clear();
}
