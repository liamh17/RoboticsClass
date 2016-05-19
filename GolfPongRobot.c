/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "adcDCpropab.h"                            // Include adcDCpropAB
#include "simpletools.h"                            // Include simpletools
#include "fdserial.h" 
#include "servodiffdrive.h" 
#include "servo.h" 

// CHECK ALL ANGLES
#define liftUp_speed 150
#define liftDown_speed -150
#define clawOpen_angle 10
#define clawClose_angle 1600

#define lMotor 16
#define rMotor 17
#define liftServo 15
#define clawServo 14

float forwardThresh =3.00;
float reverseThresh = 2.00;
float rightThresh = 3.00;
float leftThresh = 2.00;

// CHECK PINS
int liftUp_b = 15;
int liftDown_b = 14;
int clawOpen_b = 13;
int clawClose_b = 12;

fdserial *xbee;

void handleButtonInput(void);
void checkJoystick(void); 
int main()                                          // Main function
{
  // CHECK PARAMETERS
  xbee = fdserial_open(9, 8, 0, 9600); 
  writeChar(xbee, CLS);
  char c; 
    
  drive_pins(lMotor, rMotor);  
  
  adc_init(21, 20, 19, 18);                         // CS=21, SCL=20, DO=19, DI=18                           
     
  while(1)                                        
  {  
    putChar(HOME); 
    
    float udV = adc_volts(2);
    float lrV = adc_volts(3);
    
    int liftUp = input(liftUp_b);
    int liftDown = input(liftDown_b);
    int clawOpen = input(clawOpen_b);
    int clawClose = input(clawClose_b);
    
    if(udV > forwardThresh) 
    {
      c = 'f';       
    }
    if(udV < reverseThresh) 
    {
      // Reverse
      c = 'r';   
    }
    if(lrV > rightThresh) 
    {
      // Right 
      c = 'r';   
    }
    if(lrV < leftThresh) 
    {
      // Left
      c = 'l';     
    }
    else if(liftUp == 1) 
    {
      // lift up
      c = 'u';   
    }
    else if(liftDown == 1) 
    {
      // lift down
      c = 'd';   
    }
    else if(clawOpen == 1) 
    {
      // claw open
      c = 'o';
    }
    else if(clawClose == 1) 
    {
      // claw close
      c = 'c';  
    }
    
    fdserial_txChar(xbee, c); 
    pause(50); 
  }  
}
