

#include "portWriter.h"
#include <avr/io.h>

void write(portWriter* self, int arg){
    if((PORTE>>arg)&1){
        PORTE &= ~(1<<arg);
    }else{
        PORTE |= (1<<arg);
    }
    
}