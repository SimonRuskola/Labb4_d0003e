


#include "TinyTimber.h"
#include "portWriter.h"

#define initPulseGenerator(writer, bit, freq) {initObject(), writer, bit, freq}

typedef struct {
    Object super;
    portWriter* writer;
	int bit;
    int freq;

} pulseGenerator;


void cycle(pulseGenerator* self);
void incFreq(pulseGenerator* self);
void decFreq(pulseGenerator* self);
int getFreq(pulseGenerator* self);
void setFreq(pulseGenerator* self, int freq);