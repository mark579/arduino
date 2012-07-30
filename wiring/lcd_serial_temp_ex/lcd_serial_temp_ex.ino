
// include the library code:
#include <LiquidCrystal.h>
#define _TEMP_PIN 0
byte intByte;
float temperature;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  int printHi = 0;
  if(Serial.available()){
   intByte = Serial.read();
   Serial.println(intByte); 
  
   if(intByte == '#'){
     printHi = 1;
   } 
  }
  lcd.setCursor(0, 0);
  lcd.print("The Temp is:");
  //Get Voltage 
  if(((millis()/1000) % 5) == 0){
    temperature = analogRead(_TEMP_PIN) * .004882814;
    temperature = (temperature - .5 ) * 100;
    temperature = (temperature * 1.8) + 32;
  //  lcd.print(" DegF");
  }
  lcd.print(temperature);
  lcd.setCursor(0, 1);
  if(printHi == 1){
    lcd.print("Hi! ");
    
  }
  else{
    lcd.print("Bye!");
  }
  //delay(250);
}

