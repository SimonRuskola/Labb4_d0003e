
#include "pulseGenerator.h"




void cycle(pulseGenerator* self){

    //self->active = !(self->active);


    if(self->freq != 0){
        ASYNC(self->writer ,write, self->bit);
        AFTER(MSEC( ((1000)/(self->freq)) / 2 ) , self, cycle, NULL);
    }else{
        AFTER(MSEC((500)) , self, cycle, NULL);
    }

}

void incFreq(pulseGenerator* self){
    self->freq++;
}

void decFreq(pulseGenerator* self){
    self->freq--;
}
int getFreq(pulseGenerator* self){
    return self->freq;
}
void setFreq(pulseGenerator* self, int freq){
    self->freq = freq;
}
void saveFreq(pulseGenerator* self, int freq){
    self->savedFreq = freq;
}
void setSaveFreq(pulseGenerator* self){
    self->freq = self->savedFreq;
}



