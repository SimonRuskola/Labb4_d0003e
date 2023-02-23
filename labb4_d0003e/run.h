#include "Gui.h"

#include <avr/io.h>

typedef struct{
	Object super;
    portWriter* writer;
    pulseGenerator* pulse1;
    pulseGenerator* pulse2;
    guiObj* gui;
} runObj;