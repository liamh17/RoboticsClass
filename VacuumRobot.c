/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "colorpal.h"
#include "ping.h"  
#include "servodiffdrive.h" 

colorPal *cpal;                              
int cpSIO = 0;  //Find exact number, check pins                            
int r, g, b;

int main()                                    // Main function
{
  cpal = colorPal_open(cpSIO);  
  drive_pins(16, 17); 
   
  while(1)
  {    
    colorPal_getRGB(cpal, &r, &g, &b);  
    
    print("r = %04d g = %04d b = %04d\n", r, g, b); 
     
    checkInput(); 
    
    //blue
    if((r > 12) && (r < 20) && (g > 9) && (g < 16) && (b > 30) && (b < 37))  
    {
      print("Blue!\n"); 
      drive_sleep(); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }
      drive_speeds(90, 45); 
      pause(1000);     
      //return 1;       
    }
    //red
    if((r > 41) && (r < 50) && (g > 1) && (g < 7) && (b > 0) && (b < 7))  
    {     
      print("Red!\n");
      drive_sleep();  
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }
      drive_speeds(90, 45);
      pause(1000); 
      //return 1; 
    }
    //orange
    if((r > 51) && (r < 66) && (g > 16) && (g < 26) && (b > 20) && (b < 31))  
    {
      print("Orange!\n"); 
      drive_sleep(); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }  
      drive_speeds(90, 45);
      pause(1000); 
      //return 1;     
    }    
    else
    {
      drive_speeds(90, 45); 
    } 
    pause(100); 
  }  
}
void checkInput() 
{
  int leftBump = input(1); 
  int rightBump = input(15);
  int distance = ping_cm(3); 
  
    if(leftBump == 1) 
    {
      print("leftBump pressed, turning right\n");
      drive_speeds(-25, -60); //reverse
      pause(1300);
      drive_speeds(100, -10); //turn right
      pause(1000);   
    }
    else if(rightBump == 1)
    {
      print("rightBump pressed, turning left\n"); 
      drive_speeds(-25, -60); //reverseq
      pause(1300); 
      drive_speeds(-5, 100); //turn left
      pause(1000); 
    }
    else if(leftBump == 1 && rightBump == 1) 
    {
      print("both are pressed, rotating 180\n");
      drive_speeds(-25, -60); 
      pause(1300); 
      drive_speeds(-5, 100); 
      pause(1500);   
    }
    if(distance <= 13) 
    {
      drive_speeds(-25, -60); 
      pause(1200); 
      drive_speeds(-5, 100); 
      pause(1500); 
    } 
    else 
    {
      drive_speeds(90, 45);   
    }
}
void followPattern() 
{
  int straightSpeed_Left = 90;
  int straightSpeed_Right = 45; 
  
  /*print("moving straight\n");
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
  pause(18000); */
  
    //blue
    if((r > 12) && (r < 20) && (g > 9) && (g < 16) && (b > 30) && (b < 37))  
    {
      print("Blue!\n"); 
      drive_sleep(); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }
      drive_speeds(90, 45); 
      pause(1000);     
      //return 1;       
    }
    //red
    if((r > 41) && (r < 50) && (g > 1) && (g < 7) && (b > 0) && (b < 7))  
    {     
      print("Red!\n");
      drive_sleep();  
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }
      drive_speeds(90, 45);
      pause(1000); 
      //return 1; 
    }
    //orange
    if((r > 60) && (r < 75) && (g > 20) && (g < 40) && (b > 25) && (b < 37))  
    {
      print("Orange!\n"); 
      drive_sleep(); 
      for(int i = 0; i < 5; i++) 
      {
        high(14); 
        pause(500);
        low(14); 
        pause(500);   
      }  
      drive_speeds(90, 45);
      pause(1000); 
      //return 1;     
    }  
}
