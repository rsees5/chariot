#include <String.h>                       // the String library is needed for the memset command only

// initialize variables to be used in the code
int gLed = 10;
int yLed = 11;
int rLed = 12;
char myCol[20];
bool gOn = true;
bool yOn = true;
bool rOn = true;

void setup() {  
   Serial.begin (9600);                    // open serial communication at baud rate of 9600
   
   // establish output pins for RYG LEDs on the Arduino
   pinMode(gLed, OUTPUT);   
   pinMode(yLed, OUTPUT);   
   pinMode(rLed, OUTPUT);   
  
   // start with LEDs on
   digitalWrite(gLed, HIGH);
   digitalWrite(yLed, HIGH);
   digitalWrite(rLed, HIGH); 
 
}


void loop() {                               // loop this code indefinitely
  int lf = 10;                              // establish string size (in bytes)
  Serial.readBytesUntil(lf, myCol, 1);      // read first 10 bytes from serial communication into myCol 
   
   if(strcmp(myCol,"r")==0){                //if myCol string is "r"
      if(rOn == false){                     //if the red LED is off
        digitalWrite(rLed, HIGH);           //turn the red LED on
        rOn = true;                         //set marker that red LED is on
        //Serial.print("r");                //print to serial - for debugging purposes only
      }
      else {                                //if the red LED is on
        digitalWrite(rLed, LOW);            //turn red LED off
        rOn = false;                        //set marker that red LED is off       
      }
   }
  if(strcmp(myCol,"y")==0){                 //if myCOl string is "y"
    if(yOn == false) {                      //if the yellow LED is off
      digitalWrite(yLed, HIGH);             //turn the yellow LED on
      yOn = true;                           //set marker that yellow LED is on
      //Serial.print("y");                  //print to serial - for debugging purposes only
    }
    else {                                  //if the yellow LED is on
      digitalWrite(yLed, LOW);              //turn yellow LED off
      yOn = false;                          //set marker that yellow LED is off
    }
   }
  if(strcmp(myCol,"g")==0){                 //if myCOl string is "g"
    if(gOn == false) {                      //if the green LED is off
      digitalWrite(gLed, HIGH);             //turn the green LED on
      gOn = true;                           //set marker that green LED is on
      //Serial.print("g");                  //print to serial - for debugging purposes only
    }
    else {                                  //if the green LED is on
      digitalWrite(gLed, LOW);              //turn green LED off
      gOn = false;                          //set marker that green LED is off
    }
   }
   memset(myCol, 0, sizeof myCol);         //clear serial log - prevents LED blinking

}

