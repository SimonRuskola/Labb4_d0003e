
#include "Gui.h"

#include <avr/io.h>
//#include "TinyTimber.h"
//#include "pulseGenerator.h"


typedef struct{
	Object super;
    portWriter* writer;
    pulseGenerator* pulse1;
    pulseGenerator* pulse2;
    guiObj* gui;
} mainObj;

void run(mainObj* self);






int main(void)
{
    Gui__init();
    portWriter writer = initPortWriter;
    pulseGenerator pulse = initPulseGenerator(&writer, 4, 1);
    pulseGenerator pulse2 = initPulseGenerator(&writer, 6, 0);
    guiObj  gui = initGui(&pulse, &pulse2, 0);
    mainObj mainObject = {initObject(), &writer, &pulse, &pulse2, &gui};

    for(int i; i<1000; i++){
        printAt(i,2);
    }


    //SYNC(&pulse,cycle, 4);
    return TINYTIMBER(&mainObject, run, NULL);
    //TINYTIMBER(&pulse, cycle, NULL);
    
	
    while (1) 
    {

    }
}

void interupts(mainObj* self){
    ASYNC(&self->gui, updateGui, NULL);
}

void run(mainObj* self){
    INSTALL(&self, interupts, IRQ_PCINT0);
    INSTALL(&self, interupts, IRQ_PCINT1);


    ASYNC(&self->pulse1, cycle, NULL);
    ASYNC(&self->pulse2, cycle, NULL);


}

