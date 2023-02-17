
#include "Gui.h"

#include <avr/io.h>
#include "TinyTimber.h"
//#include "pulseGenerator.h"


typedef struct{
	Object super;
} mainObj;

void run(mainObj self);

mainObj mainObject = {initObject()};
guiObj  gui = initGui;
portWriter writer = initPortWriter;
pulseGenerator pulse = initPulseGenerator;
pulseGenerator pulse2 = initPulseGenerator;





int main(void)
{
    pulseGenerator__init(&pulse, 4 , writer, 2); 
    pulseGenerator__init(&pulse2, 6 , writer, 1);
    gui.pulse1 = pulse;
    gui.pulse2= pulse2;
    gui.currentPulse = pulse;
    Gui__init(&gui);
   

    //ASYNC(&pulse, cycle, NULL);
   
    TINYTIMBER(&mainObject, run, NULL);
    //TINYTIMBER(&pulse, cycle, NULL);
    
	
    while (1) 
    {

    }
}

void run(mainObj self){
    INSTALL(&gui, updateGui, IRQ_PCINT0);
    INSTALL(&gui, updateGui, IRQ_PCINT1);


    SYNC(&pulse, cycle, NULL);
    SYNC(&pulse2, cycle, NULL);


}

