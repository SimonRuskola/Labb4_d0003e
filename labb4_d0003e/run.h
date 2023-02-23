#include "Gui.h"

#include <avr/io.h>

typedef struct{
	Object super;
    portWriter* writer;
    pulseGenerator* pulse1;
    pulseGenerator* pulse2;
    guiObj* gui;
} runObj;


#define initRun(writer ,pulse1 ,pulse2, gui) {initObject(), writer ,pulse1 ,pulse2, gui}

void run(runObj* self);
void interupts(runObj* self);