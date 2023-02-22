
#include "TinyTimber.h"

#define initPortWriter {initObject()}

typedef struct {
    Object super;
} portWriter;


int write(portWriter* self, int arg);