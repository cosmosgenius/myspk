#include "palayer.h"
#include <portaudio.h>
#include "stdio.h"

PaLayer::PaLayer()
{
}

bool PaLayer::init()
{
    PaError err;
    err = Pa_Initialize();
    if (err == paNoError){
        return true;
    }
    return false;
}
