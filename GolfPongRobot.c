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

float forwardThresh 3.00
float reverseThresh 2.00
float rightThresh 3.00
float leftThresh 2.00

// CHECK PINS
int liftUp_b = 15;
int liftDown_b = 14;
int clawOpen_b = 13;
int clawClose_b = 12;

void handleButtonInput(void)
int main()                                          // Main function
{
  fdserial *xbee;
  drive_pins(lMotor, rMotor);  
  
  adc_init(21, 20, 19, 18);                         // CS=21, SCL=20, DO=19, DI=18
  float lrV, udV;                                   // Voltage variables
  
  writeChar(xbee, CLS);
  char c;

  while(1)                                          // Loop repeats indefinitely
  {
    udV = adc_volts(2);                             // Check A/D 2                
    lrV = adc_volts(3);                             // Check A/D 3
   
    putChar(HOME);                                  // Cursor -> top-left "home"
    print("Up/Down = %.2f V %c\n", udV, CLREOL);    // Display voltage
    print("Left/Right = %.2f V %c\n", lrV, CLREOL); // Display voltage

    int liftUp = input(liftUp_b);
    int liftDown = input(liftDown_b);
    int clawOpen = input(clawOpen_b);
    int clawClose = input(clawClose_b);
    pause(100);                                     // Wait 1/10 s
    
    // OPERATE ROBOT
    checkJoystick();
    if(c == 'f') 
    {
      print("Forward!"); 
      servo_speeds(90, 45);   
    }
    else if(c == 'r') 
    {
      print("Reverse!");
      servo_speeds(-45, -90);  
    }
    else if(c == 'l') 
    {
      print("Left!");
      servo_speeds(-5, 100);   
    }
    else if(c == 'r') 
    {
      print("Right!"); 
      servo_speeds(100, -5);  
    }
    handleButtonInput(); 
    
    fdserial_txChar(xbee, c); 
    pause(50); 
  }  
}

void handleButtonInput() 
{
  //Will handle all input from buttons and will also adjust pos. of lift and claw. 
    if(liftUp == 1) 
    {
       servo_angle(liftServo, liftUp_angle); 
    }
    else if(liftDown == 1)
    {
       servo_angle(liftServo, liftDown_angle);
    }
    else if(clawOpen == 1)
    {
       servo_angle(clawServo, clawOpen_angle); 
    }
    else if(clawClose == 1)
    {
       servo_angle(clawServo, clawClose_angle); 
    }
}
void checkJoystick() 
{
   // GLOBAL CHAR C?
   // CHECK IF STATEMENTS. REWRITE IF NEEDED.
    if(udV > 2.6)
    {
      print("Forward!"); 
      c = 'f';    
    }
    if(udV < 2.4) 
    {
      print("Reverse!");
      c = 'r';    
    }
    if(lrV < 2.2) 
    {
      print("Left!");
      c = 'l'; 
    }
    if(lrV > 2.6)
    {
      print("Right!");
      c = 'r';  
    }
    else 
    {
       c = 's';  
    }   
    
}
