
#include "Gui.h"

#include <avr/io.h>
#include "portWriter.h"
#include "TinyTimber.h"


int main(void)
{
    button_init();
    LCD_Init();
    portWriter writer = initPortWriter;
    //writer.write(writer, 4);
    int i;

    SYNC(&writer ,write,4);

    
	SYNC(&writer ,write,4);

	
	SYNC(&writer ,write,4);
    
	
    while (1) 
    {
      
    }
}

