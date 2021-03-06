/*
 * THIS SOFTWARE IS THE CODE THAT WILL BE UPLOADED TO THE
 * ROBOT. IT HANDLES THE CHARACTER RECEIVED FROM THE 
 * XBEE WIRELESS CHANNEL, AND THEN EXECUTES A SPECIFIC
 * BLOCK OF CODE, FOR EXAMPLE, OPERATING THE LIFT.
 * 
 * THIS CODE HANDLES THE FUNCTION OF THE CLAW, LIFT, AND
 * THE DRIVE SYSTEM. BASED ON THE FOLLOWING SERIES OF CHARACTERS,
 * THE CODE PERFORMS SPECIFIC TASKS:
 * 
 *  FORWARD - F
 *  REVERSE - R
 *  LEFT = L
 *  RIGHT = R
 *  
 *  CLAW OPEN = O
 *  CLAW CLOSE = C
 *  LIFT UP = U
 *  LIFT DOWN = D
*/
#include "simpletools.h"                      // Include simple tools
#include "adcDCpropab.h" 
#include "fdserial.h"
#include "servodiffdrive.h" 
#include "servo.h" 

#define lMotor 16
#define rMotor 17

#define liftServo 15
#define liftUp_speed 150
#define liftDown_speed -150
#define clawServo 14
#define clawOpen_angle 1200
#define clawClose_angle 15

fdserial *xbee; 

int main()                                    // Main function
{
  xbee = fdserial_open(9, 8, 0, 9600);
  writeChar(xbee, CLS);
  
  char c;
 
  while(1)
  {
    c = fdserial_rxChar(xbee); 
    drive_pins(lMotor, rMotor); 
    
    if(c = 'f') 
    {
      // forward
      drive_speeds(90, 45);   
    }
    else if(c = 'r') 
    {
      // reverse
      drive_speeds(-45, -90);   
    }
    else if(c = 'l') 
    {
      // left
      drive_speeds(-5, 100);   
    }
    else if(c = 'r') 
    {
      // right
      drive_speeds(100, -5);   
    }
    else if(c = 's') 
    {
      // stop
      drive_sleep();   
    }
    else if(c = 'o') 
    {
      // claw open
      servo_angle(clawServo, clawOpen_angle); 
    }
    else if(c = 'c') 
    {
      // claw close
      servo_angle(clawServo, clawClose_angle);
    }
    else if(c = 'u') 
    {
      // lift up 
      servo_angle(liftServo, liftUp_speed); 
    }
    else if(c = 'd') 
    {
      // lift down
      servo_angle(liftServo, liftDown_speed); 
    } 
  }  
}
