
#include "run.h"



void run(runObj* self){
    INSTALL(self, interupts, IRQ_PCINT0);
    INSTALL(self, interupts, IRQ_PCINT1);

    ASYNC(self->pulse1, cycle, NULL);
    ASYNC(self->pulse2, cycle, NULL);
}


void interupts(runObj* self){
    ASYNC(self->gui, updateGui, NULL);
}
