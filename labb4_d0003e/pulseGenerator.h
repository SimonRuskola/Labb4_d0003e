
#include "TinyTimber.h"
#include "portWriter.h"

#define initPulseGenerator {initObject(),initObject(),0,0,0}

typedef struct {
    Object super;
    portWriter writer;
	int bit;
    int active;
    int freq;

} pulseGenerator;