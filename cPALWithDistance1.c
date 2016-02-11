/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"
#include "colorpal.h"
#include "ping.h"  

colorPal *cpal;                              
int cpSIO = 15;  //Find exact number, check pins                            
int r, g, b;

int main()                                    
{
  cpal = colorPal_open(cpSIO);     
  
  //Numbers not even close to being correct.
  int r_scale = 3/*insert data*/;
  int g_scale = 2/*insert data*/;
  int b_scale = 1/*insert data*/;

  //Numbers not even close to being correct.
  int x = 5; 
  int y = 5;

  int dist_CM = ping_cm(14);           

  while(1)                                 
  {
    colorPal_getRGB(cpal, &r, &g, &b);       

    print("r = %04d g = %04d b = %04d\n", r, g, b);
    
    /* Replace numbers from research project!
     * This is just a template/base program for
     * research project numbers. 
     * Data is set for the colored paper placed 
     * 15.7mm away from the sensor.
     * Needs to be updated to encompass 20mm data.
     */
    
    if((r > 12) && (r < 17) && (g > 16) && (g < 22) && (b > 18) && (b < 24)) 
    {
       print("The color is green!\n"); 
      
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is green!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is green!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is green!\n");  
         }  
       }
    }    
    else if((r > 42) && (r < 50) && (g > 23) && (g < 29) && (b > 15) && (b < 20)) 
    {
       print("The color is yellow!\n");   
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is yellow!\n");   
         }  
       }
       else if(dist_CM <= 30) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is yellow!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is yellow!\n");  
         }  
       }
    }  
    else if((r > 32) && (r < 39) && (g > 1) && (g < 7) && (b > 1) && (b < 7))
    {
       print("The color is red!\n");   
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is red!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is red!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is red!\n");  
         }  
       }
    }   
    else if((r > 47) && (r < 55) && (g > 18) && (g < 28) && (b > 20) && (b < 29))
    {
       print("The color is orange!\n"); 
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is orange!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is orange!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is orange!\n");  
         }  
       }   
    } 
    else if((r > 14) && (r < 20) && (g > 10) && (g < 19) && (b > 29) && (b < 38))
    {
       print("The color is blue!\n");
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is blue!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is blue!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is blue!\n");  
         }  
       }    
    } 
    else if((r > 10) && (r < 15) && (g > 5) && (g < 10) && (b > 9) && (b < 15))
    {
       print("The color is black!\n");
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is black!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is black!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is black!\n");  
         }  
       }    
    } 
    else if((r > 44) && (r < 50) && (g > 30) && (g < 36) && (b > 51) && (b < 56)) 
    {
       print("The color is white!\n");   
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is white!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is white!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is white!\n");  
         }  
       } 
    } 
    else if((r > 42) && (r < 51) && (g > 19) && (g < 26) && (b > 31) && (b < 40)) 
    {
       print("The color is pink!\n");   
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is pink!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is pink!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is pink!\n");  
         }  
       }
    } 
    else if((r > 34) && (r < 45) && (g > 9) && (g < 16) && (b > 18) && (b < 25)) 
    {
       print("The color is magenta!\n");   
       
       if(dist_CM <= 20)
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y))
         {
            print("The color is magenta!\n");   
         }  
       }
       else if(dist_CM <= 20) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is magenta!\n");   
         }         
       }  
       else if(dist_CM <= 40) 
       {
         if(r > x) && (r < y) && (g > x) && (g < y) && (b > x) && (b < y)) 
         {
            print("The color is magenta!\n");  
         }  
       }
    } 

    pause(1000);                             
  }
}
