/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "ping.h" 
#define TB_PIN 15
#define BB_PIN 11
#define LED 26
#define LED2 27
#define PIEZO 0

int main()                                    // Main function
{
  // Add startup code here.

 
  while(1)
  {
    int topButton = input(TB_PIN);
    int bottomButton = input(BB_PIN);

    if(input(15) == 1 && input(11) == 0) 
    {
      freqout(PIEZO, 50, 1000); 
      //pause(500);
      //freqout(PIEZO, 50, 0); 
      
      high(26);
    }
    else if(input(11) == 1 && input(15) == 0) 
    {
      freqout(PIEZO, 50, 500);
      high(27);  
    }
    // THIS IS FOR TESTING PURPOSES ONLY, DO NOT INCLUDE
    else if(input(11) == 1 && input(15) == 1) 
    {
      high(27);
      high(26);
      pause(50);
      low(27);
      low(26);
      pause(50);
    }
    else  
    {
      //freqout(PIEZO, 50, 500); 
      
      // this is our standby blinking  
      high(26);
      low(27);
      pause(50);
      low(26);
      high(27);
      pause(50);   
    } 
    //pause(65); 
    
    print("%c", HOME);
    print("Little Flower: %d \n", topButton); 
    print("Father Judge: %d \n", bottomButton);
    print("%c", CLREOL); 
    pause(100);

  }  
}
