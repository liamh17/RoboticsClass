/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
  double x;
  double degC; 
  
  high(3); 
  shift_out(5, 4, LSBFIRST, 8, 9); //check numbers
  low(3);
  
  while(1) 
  {
    high(3);
    shift_out(5, 4, LSBFIRST, 8, 9); //check numbers
    shift_in(5, 4, LSBPRE, x); 
    
    degC = x / 2; 
    print("Celsius = %d\n", degC); 
    pause(1000);    
  }
}
