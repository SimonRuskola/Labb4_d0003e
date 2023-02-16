
#include "Gui.h"

#include <avr/io.h>
#include "TinyTimber.h"
#include "pulseGenerator.h"



int main(void)
{
    button_init();
    LCD_Init();
    portWriter writer = {initObject()};
    pulseGenerator pulse = {initObject(),initObject(),0,0};
    pulseGenerator pulse2 = {initObject(),initObject(),0,0};
    
    pulseGenerator__init(&pulse, 4 , writer);
    pulseGenerator__init(&pulse2, 6 , writer);


    //ASYNC(&pulse, cycle, NULL);
    //SYNC(&pulse, cycle, NULL);
    //SYNC(&pulse2, cycle, NULL);
    TINYTIMBER(&pulse2, cycle, NULL);
    

    

    
	
    while (1) 
    {

    }
}

