
#include "pulseGenerator.h"
#include "TinyTimber.h"


void pulseGenerator__init(pulseGenerator* self, int bit, portWriter writer) {
    self->bit = bit;
    self->active = 0;
    self->writer = writer;
    self->freq = 0;
 }


void cycle(pulseGenerator* self){
    if(self->active){

        SYNC(&self->writer ,write, self->bit);

        SEND()

    }
}


