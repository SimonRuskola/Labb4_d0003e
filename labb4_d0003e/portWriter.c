

#include "portWriter.h"
#include <avr/io.h>

int write(portWriter* self, int arg){
    if(PORTE &(1<<arg)){
        PORTE &= ~(1<<arg);
    }else{
        PORTE |= (1<<arg);
    }

    return 0;
    
}