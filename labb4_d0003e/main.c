

#include "run.h"

portWriter writer = initPortWriter;
pulseGenerator pulse = initPulseGenerator(&writer, 4, 0);
pulseGenerator pulse2 = initPulseGenerator(&writer, 6, 0);
guiObj  gui = initGui(&pulse, &pulse2, 0);
runObj mainObject = initRun(&writer, &pulse, &pulse2, &gui);




int main(void)
{

    Gui__init();
    return TINYTIMBER(&mainObject, run, NULL);
    
}


