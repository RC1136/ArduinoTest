#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <string.h>

LiquidCrystal_I2C lcd(0x27,16,4); 


const int IN_A0 = A6;
const int IN_D0 = PD6;

void setup() {
  
  lcd.init();
  lcd.backlight();
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  

  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  
}



int value_A0;
int value_D0;

void loop() {

  char msg[5] = "";
  value_A0 = analogRead(IN_A0);
  value_D0 = digitalRead(IN_D0);
 
  //itoa(value_A0, msg, 10);
  sprintf(msg, "%04d", value_A0);
  
  lcd.setCursor(1,0);
  lcd.print(msg);
  lcd.setCursor(1,1);
  lcd.print(value_D0 ? "T" : "F");
  delay(1000);
}
