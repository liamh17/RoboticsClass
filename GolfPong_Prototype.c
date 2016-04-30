/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h"
#include "servodiffdrive.h"

#define clawServo 17
#define openClawAngle 1600
#define closeClawAngle 50
#define openClaw_ButtonPin 1
#define closeClaw_ButtonPin 2

void operateClaw(void); 
int main()                                    // Main function
{
   
  while(1)
  {
    operateClaw();
    pause(100); 
  }  
}
void operateClaw() 
{
   int openClaw_Button = input(openClaw_ButtonPin); 
   int closeClaw_Button = input(closeClaw_ButtonPin); 
   
   print("%c", HOME); 
   print("OpenClaw_Button = %d\n", openClaw_Button); 
   print("CloseClaw_Button = %d\n", closeClaw_Button);
   
   if(openClaw_Button == 1) 
   {
      print("Opening claw");
      pause(50); 
      servo_angle(clawServo, openClawAngle);   
   }
   else if(closeClaw_Button == 1) 
   {
      print("Closing claw"); 
      pause(50);
      servo_angle(clawServo, closeClawAngle);   
   }
}
