/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "adcDCpropab.h"                            // Include adcDCpropAB
#include "simpletools.h"                            // Include simpletools
#include "fdserial.h" 

float forwardThresh 3.00
float reverseThresh 2.00
float rightThresh 3.00
float leftThresh 2.00

int liftUp_b
int liftDown_b
int clawOpen_b
int clawClose_b

int main()                                          // Main function
{
  fdserial *xbee; 
  
  adc_init(21, 20, 19, 18);                         // CS=21, SCL=20, DO=19, DI=18

  float lrV, udV;                                   // Voltage variables

  while(1)                                          // Loop repeats indefinitely
  {
    udV = adc_volts(2);                             // Check A/D 2                
    lrV = adc_volts(3);                             // Check A/D 3
   
    putChar(HOME);                                  // Cursor -> top-left "home"
    print("Up/Down = %.2f V %c\n", udV, CLREOL);    // Display voltage
    print("Left/Right = %.2f V %c\n", lrV, CLREOL); // Display voltage

    pause(100);                                     // Wait 1/10 s
    
    if(udV > 2.6)
    {
      print("Forward!"); 
      high(26);
      pause(200);
      low(26);
      pause(200);   
    }
    if(udV < 2.4) 
    {
      print("Reverse!");
      high(27); 
      pause(200); 
      low(27);
      pause(200);   
    }
    if(lrV < 2.2) 
    {
      print("Left!");
      high(26);
      high(27);
      pause(200);
      low(26);
      low(27);
      pause(200);   
    }
    if(lrV > 2.6)
    {
      print("Right!");
      high(26);
      low(27);
      pause(200);
      high(27);
      low(26); 
    }
  }  
}
