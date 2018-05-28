#include <String.h>


int gLed = 10;
int yLed = 11;
int rLed = 12;
char myCol[20];
bool gOn = true;
bool yOn = true;
bool rOn = true;

void setup() {  
   Serial.begin (9600);  
   pinMode(gLed, OUTPUT);    
   pinMode(yLed, OUTPUT);   
   pinMode(rLed, OUTPUT);   
  
   digitalWrite(gLed, HIGH);
   digitalWrite(yLed, HIGH);
   digitalWrite(rLed, HIGH); 
 
}


void loop() {
  int lf = 10;
  Serial.readBytesUntil(lf, myCol, 1);
    if(strcmp(myCol,"r")==0){             //if myCol string is "r"
      if(rOn == false){                   //if the LED is off
        digitalWrite(rLed, HIGH);         //turn the LED on
        rOn = true;                       //set marker that LED is on
        //Serial.print("r");                //print to serial - for debugging
      }
      else { //if the LED is on
        digitalWrite(rLed, LOW); //turn LED off
        rOn = false; //set marker that LED is off       
      }
   }
  if(strcmp(myCol,"y")==0){
    if(yOn == false) {
      digitalWrite(yLed, HIGH);
      yOn = true;
      //Serial.print("y");
    }
    else {
      digitalWrite(yLed, LOW);
      yOn = false;
    }
   }
  if(strcmp(myCol,"g")==0){
    if(gOn == false) {
      digitalWrite(gLed, HIGH);
      gOn = true;
      //Serial.print("g");
    }
    else {
      digitalWrite(gLed, LOW);
      gOn = false;
    }
   }
   memset(myCol, 0, sizeof myCol); //clears serial log

}

