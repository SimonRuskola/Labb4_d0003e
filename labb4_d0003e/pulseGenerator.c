
#include "pulseGenerator.h"
#include "TinyTimber.h"


void pulseGenerator__init(pulseGenerator* self, int bit, portWriter writer, int freq) {
    self->bit = bit;
    self->active = 0;
    self->writer = writer;
    self->freq = freq;
 }


void cycle(pulseGenerator* self){

    //self->active = !(self->active);


    if(self->freq != 0){
        SYNC(&self->writer ,write, self->bit);
    }

    

    AFTER(MSEC( (1000)/(self->freq) /2 ) , self, cycle, NULL);
   // SEND( MSEC( (1000)/(self->freq) ) , MSEC(10)  , self, cycle, NULL);
    //SEND( MSEC( 1000 ) , 10  , self, cycle, NULL);


}

void incFreq(pulseGenerator* self){
    self->freq++;
}

void decFreq(pulseGenerator* self){
    self->freq--;
}


