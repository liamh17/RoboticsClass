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
#define liftUp_angle 1800
#define liftDown_angle 0
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
  xbee = fdserial_open(9, 8, 0, 9600); 
  
  drive_pins(lMotor, rMotor);  
  
  adc_init(21, 20, 19, 18);                         // CS=21, SCL=20, DO=19, DI=18                           
  
  writeChar(xbee, CLS);
  char c; 

  float udV, lrV; 
  int liftUp, liftDown, clawOpen, clawClose; 
  
  while(1)                                        
  {  
    putChar(HOME); 
    
    udV = adc_volts(2);
    lrV = adc_volts(3);
    liftUp = input(liftUp_b);
    liftDown = input(liftDown_b);
    clawOpen = input(clawOpen_b);
    clawClose = input(clawClose_b);
    
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
    
    fdserial_txChar(xbee, c); 
    pause(50); 
  }  
}

/*
void handleButtonInput() 
{
  //Will handle all input from buttons and will also adjust pos. of lift and claw. 
    
    int liftUp = input(liftUp_b);
    int liftDown = input(liftDown_b);
    int clawOpen = input(clawOpen_b);
    int clawClose = input(clawClose_b);
    
    print("LU = %d, LD = %d, CO = %d, CC = %d\n", liftUp, liftDown, clawOpen, clawClose);  
    if(liftUp == 1) 
    {
       print("Lift Up"); 
       servo_angle(liftServo, liftUp_angle); 
    }
    else if(liftDown == 1)
    {
       print("Lift Down");
       servo_angle(liftServo, liftDown_angle);
    }
    else if(clawOpen == 1)
    {
       print("Claw Open"); 
       servo_angle(clawServo, clawOpen_angle); 
    }
    else if(clawClose == 1)
    {
       print("Claw Close"); 
       servo_angle(clawServo, clawClose_angle); 
    }
}
*/
