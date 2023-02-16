
#include "TinyTimber.h"

#define initPortWriter {initObject()}

typedef struct {
    Object super;
} portWriter;


void write(portWriter* self, int arg);