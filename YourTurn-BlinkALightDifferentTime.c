/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
  int led = 15;
  int led2 = 14; 
  
  while(1)
  {
    high(15);
    low(14);  
    pause(500); 
    low(15);
    high(14); 
    pause(500);   
  }  
}
