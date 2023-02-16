
#include "pulseGenerator.h"
#include "TinyTimber.h"


void pulseGenerator__init(pulseGenerator* self, int bit, portWriter writer) {
    self->bit = bit;
    self->active = 0;
    self->writer = writer;
    self->freq = 1;
 }


void cycle(pulseGenerator* self){

    //self->active = !(self->active);


    //if(self->freq != 0){


    //}

    SYNC(&self->writer ,write, self->bit);

    //SEND( MSEC( (1000)-(self->freq) ) , MSEC( (1000)-(self->freq) + 100)  , self, cycle, NULL);
    SEND( MSEC( 1000 ) , 10  , self, cycle, NULL);

    

}


