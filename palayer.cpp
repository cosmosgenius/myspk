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

bool PaLayer::start()
{
    return true;
}

bool PaLayer::stop()
{
    return true;
}

int PaLayer::PaCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    return 0;
}
