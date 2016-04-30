/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servodiffdrive.h"
#include "servo.h" 
#include "ping.h"


#define leftMotor 16
#define rightMotor 17
#define LED 1
#define Ultrasonic 2
#define stanServo 15
#define stanServo_2 14
#define openClawAngle 1600
#define closeClawAngle 0
#define openArmAngle 1700
#define closeArmAngle 0
#define openClaw_ButtonVal 3
#define closeClaw_ButtonVal 4

//BEFORE LOADING, CHECK ALL PINS
void checkSensors(void); 
void moveArm(void); 
void useClaw(void); 
void executePattern(void); 

int main()                                    // Main function
{ 
  drive_pins(leftMotor, rightMotor);
  executePattern(); 
  
  while(1)
  {
    
  }  
}
void executePattern() 
{
  int straightSpeed_Left = 90;
  int straightSpeed_Right = 45;  
 
  drive_speeds(straightSpeed_Left, straightSpeed_Right); 
  pause(5000); 
  
  drive_speeds(0, 100);
  pause(3000); 
  
  drive_speeds(straightSpeed_Left, straightSpeed_Right); 
  pause(1000); 
}
void checkSensors() 
{  
  int dist = ping_cm(Ultrasonic);
  if(dist <= 5) 
  {
    high(1);
    pause(50);   
    low(1);
    pause(50);    
  } 
}
void moveArm() 
{
  if() //FIND HOW TO PROGRAM JOYSTICK, Y AXIS UP
  { 
    servo_angle(stanServo, openArmAngle);   
  }
  else if() 
  {
    servo_angle(stanServo, openArmAngle);   
  }
}
void useClaw() 
{
  int openClawButton = input(openClaw_ButtonVal); 
  int closeClawButton = input(closeClaw_ButtonVal); 
  
  if(openClawButton == 1) 
  {
    servo_angle(stanServo_2, openClawAngle);  
  }
  else(closeClawButton == 1) 
  {
    servo_angle(stanServo_2, closeClawAngle);     
  }
}
  
