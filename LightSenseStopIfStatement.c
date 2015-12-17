/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servodiffdrive.h" 

/*
 * This is extra code to be inserted into the
 * existing program. It's the drive straight
 * method, with an if statement inside of it 
 * to, hopefully, over-ride, the driving forward, 
 * then stop the robot. 
 */

int main()                                    // Main function
{
  //Don't paste in with code, variables already exist.
  drive_speeds(17, 16); 
  
  while(1)
  {
    high(15); 
    pause(1); 
    int l = rc_time(15, 1);
    
    high(1);
    pause(1); 
    int r = rc_time(1, 1); 
    
    if(abs(l - r) < 10) 
    {
      drive_speeds(100, 55); 
      high(27);
      high(26); 
      pause(100); 
      low(27); 
      low(26);
      pause(200); 
      
      if(abs(l - r) <= 2) 
      {
        drive_speeds(0, 0); 
        high(27);
        low(26); 
        pause(100); 
        high(26); 
        low(27);
        pause(200); 
      }              
    } 
  }  
}
