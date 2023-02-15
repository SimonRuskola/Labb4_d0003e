

#include "portWriter.h"
#include <avr/io.h>

void write(portWriter* self, int arg){
    int temp = (PORTE>>arg)&1;
    if(temp){
        PORTE &= (0<<arg);
    }else{
        PORTE |= (1<<arg);
    }
    
}