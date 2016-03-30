
/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servodiffdrive.h" 
#include "colorpal.h"
#include "ping.h"

#define leftMotor 16
#define rightMotor 17
#define leftBump 1
#define rightBump 15
#define ultrasonic 3
#define redLight 14

colorPal *cpal;                              
int cpSIO = 0;  //Find exact number, check pins                            
int r, g, b;

void drive();
void checkCPal(); 
void followPattern(); 

int main()    
{  
  cpal = colorPal_open(cpSIO);
  drive_pins(leftMotor, rightMotor);  
  
  while(1)
  {
    colorPal_getRGB(cpal, &r, &g, &b);
    drive();
  }
}


void drive() 
{  
  int leftBumper = input(leftBump);
  int rightBumper = input(rightBump); 
  int distance = input(ultrasonic);
  
    print("left = %d right = %d; distance = %d\n", leftBumper, rightBumper, distance);  
    if(leftBumper == 1) 
    {
      print("leftBump pressed, turning right\n");
      drive_speeds(-25, -60); //reverse
      pause(1300);
      drive_speeds(100, -10); //turn right
      pause(400);   
    }
    else if(rightBumper == 1)
    {
      print("rightBump pressed, turning left\n"); 
      drive_speeds(-25, -60); //reverse
      pause(1300); 
      drive_speeds(-5, 100); //turn left
      pause(700); 
    }
    if(distance <= 5) 
    {
      drive_speeds(-25, -60); 
      pause(1200); 
      drive_speeds(-5, 100); 
      pause(700); 
    }
    //blue
    if((r > 12) && (r < 20) && (g > 9) && (g < 16) && (b > 30) && (b < 37))  
    {
      print("Blue!\n"); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }    
      //return 1;       
    }
    //red
    if((r > 41) && (r < 50) && (g > 1) && (g < 7) && (b > 0) && (b < 7))  
    {     
      print("Red!\n"); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }
      //return 1; 
    }
    //orange
    if((r > 60) && (r < 75) && (g > 20) && (g < 40) && (b > 25) && (b < 37))  
    {
      print("Orange!\n"); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }  
      //return 1;     
    }
    else 
    {
      followPattern();
    }
}
void checkCPal() 
{
    //blue

}
void followPattern() 
{
  int straightSpeed_Left = 90; 
  int straightSpeed_Right = 40;  
    if((r > 12) && (r < 20) && (g > 9) && (g < 16) && (b > 30) && (b < 37))  
    {
      print("Blue!\n"); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }    
      //return 1;       
    }
    //red
    if((r > 41) && (r < 50) && (g > 1) && (g < 7) && (b > 0) && (b < 7))  
    {     
      print("Red!\n"); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }
      //return 1; 
    }
    //orange
    if((r > 60) && (r < 75) && (g > 20) && (g < 40) && (b > 25) && (b < 37))  
    {
      print("Orange!\n"); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }  
      //return 1;     
    }
    else
    {
       print("moving straight\n");
       drive_speeds(straightSpeed_Left, straightSpeed_Right); //straight
       pause(18000); //10 [sec]
  
       print("turning left\n"); 
       drive_speeds(-5, 100); //90 degree left turn
       pause(1700); 
      
       print("moving straight (QUICK)\n");
       drive_speeds(straightSpeed_Left, straightSpeed_Right); //straight
       pause(1000); //move forward a bit
  
       print("turninig left\n");
       drive_speeds(-10, 100); //90 degree left turn
       pause(1700); 
  
       print("moving straight #2\n"); 
       drive_speeds(straightSpeed_Left, straightSpeed_Right); //straight
       pause(18000); //go back 
  
       print("turning right now\n");
       drive_speeds(100, -30); 
       pause(1600); 
  
       print("moving straight quick again\n");
       drive_speeds(straightSpeed_Left, straightSpeed_Right);
       pause(1000); 
  
       print("turning right again\n"); 
       drive_speeds(100, -30); 
       pause(1700);
  
       print("returning to original pos\n"); 
       drive_speeds(straightSpeed_Left, straightSpeed_Right); 
       pause(18000);    
     }        
}
