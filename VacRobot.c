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
  
  /*drive_speeds(90,45);
  pause(2000);
  drive_sleep();
  pause(600); 
  drive_speeds(115, 40); 
  pause(3000); */
   
  while(1)
  {    
    colorPal_getRGB(cpal, &r, &g, &b);  
    
    print("r = %04d g = %04d b = %04d\n", r, g, b); 
     
    checkInput(); 
    
    //blue
    //floor, ignore it
    if((r > 10) && (r < 37) && (g > 4) && (g < 25) && (b > 34) && (b < 56)) 
    {
      print("trash found! - blue\n"); 
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
    if((r > 45) && (r < 75) && (g > 0) && (g < 9) && (b > 0) && (b < 11))  
    {     
      print("trash found! - red\n");
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
    if((r > 46) && (r < 68) && (g > 11) && (g < 29) && (b > 22) && (b < 32))  
    {
      print("trash found! - orange\n"); 
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
  
    if(distance <= 14 || leftBump == 1 || rightBump == 1) 
    {
    if(leftBump == 1) 
    {
      print("leftBump pressed, turning right\n");
      drive_speeds(-25, -60); //reverse
      pause(1300);
      drive_speeds(100, -20); //turn right
      pause(2000);   
    }
    else if(rightBump == 1)
    {
      print("rightBump pressed, turning left\n"); 
      drive_speeds(-25, -60); //reverseq
      pause(1300); 
      drive_speeds(-20, 100); //turn left
      pause(2000); 
    }
    else if(leftBump == 1 && rightBump == 1) 
    {
      print("both are pressed, rotating 180\n");
      drive_speeds(-25, -60); 
      pause(1300); 
      drive_speeds(100, -60); 
      pause(2200);    
    }
    if(distance <= 12) 
    {
      print("too close\n");
      drive_speeds(-25, -60); 
      pause(1400); 
      drive_speeds(100, -60); 
      pause(2000); 
    }
  }     
    else 
    {
      print("moving straight\n");
      drive_speeds(90, 45); 
      //followPattern();    
    }
}
void followPattern() 
{
  int straightSpeed_Left = 90;
  int straightSpeed_Right = 45; 
  
  /*print("moving straight\n");
  drive_speeds(straightSpeed_Left, straightSpeed_Right); //straight
  pause(18000); //10 [sec]
  
  checkInput(); 
  
  print("turning left\n"); 
  drive_speeds(-5, 100); //90 degree left turn
  pause(1700); 
  
  checkInput(); 
     
  print("moving straight (QUICK)\n");
  drive_speeds(straightSpeed_Left, straightSpeed_Right); //straight
  pause(1000); //move forward a bit
  
  checkInput(); 
 
  print("turninig left\n");
  drive_speeds(-10, 100); //90 degree left turn
  pause(1700); 
  
  checkInput(); 
  
  print("moving straight #2\n"); 
  drive_speeds(straightSpeed_Left, straightSpeed_Right); //straight
  pause(18000); //go back 
  
  checkInput(); 
  
  print("turning right now\n");
  drive_speeds(100, -30); 
  pause(1600); 
  
  checkInput(); 
  
  print("moving straight quick again\n");
  drive_speeds(straightSpeed_Left, straightSpeed_Right);
  pause(1000); 
  
  checkInput(); 
  
  print("turning right again\n"); 
  drive_speeds(100, -30); 
  pause(1700);
  
  checkInput(); 
  
  print("returning to original pos\n"); 
  drive_speeds(straightSpeed_Left, straightSpeed_Right); 
  pause(18000); 
  
  checkInput(); */  
}
