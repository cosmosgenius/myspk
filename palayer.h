#ifndef PALAYER_H
#define PALAYER_H

class PaLayer
{
public:
    PaLayer();
    bool init();

private:
    int PaCallback(
        const void *input, void *output,
        unsigned long frameCount,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *userData );
};

#endif // PALAYER_H
