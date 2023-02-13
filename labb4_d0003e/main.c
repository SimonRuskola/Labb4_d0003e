
#include "Gui.h"

#include <avr/io.h>


int main(void)
{
    button_init();
    LCD_Init();
    while (1) 
    {
        if(readJoystick()==3){
            printAt(0,0);
        }
    }
}

