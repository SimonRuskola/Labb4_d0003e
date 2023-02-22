

#include "portWriter.h"
#include <avr/io.h>

int write(portWriter* self, int arg){
    if((PORTE>>arg)&1){
        PORTE &= ~(1<<arg);
    }else{
        PORTE |= (1<<arg);
    }

    return 0;
    
}