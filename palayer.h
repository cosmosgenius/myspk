#ifndef PALAYER_H
#define PALAYER_H

#include <portaudio.h>

#define SAMPLE_RATE (44100)

class PaLayer
{
public:
    PaLayer();
    bool init();
    bool start();
    bool stop();
};

#endif // PALAYER_H
