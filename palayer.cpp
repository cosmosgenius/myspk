#include "palayer.h"
#include "stdio.h"

typedef struct
{
    float left_phase;
    float right_phase;
}
paTestData;

static paTestData data;

static int PaCallback(
        const void *input, void *output,
        unsigned long frameCount,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *userData );

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
    PaStream *stream;
    PaError err;
    data.left_phase = data.right_phase = 0.0;
    err = Pa_OpenDefaultStream( &stream,
                                0,
                                2,
                                paFloat32,
                                SAMPLE_RATE,
                                256,
                                PaCallback,
                                &data );
    if( err != paNoError ) goto error;

    err = Pa_StartStream( stream );
    if( err != paNoError ) goto error;

    /* Sleep for several seconds. */
    Pa_Sleep(10*1000);

    err = Pa_StopStream( stream );
    if( err != paNoError ) goto error;
    err = Pa_CloseStream( stream );
    if( err != paNoError ) goto error;
    Pa_Terminate();
    printf("Test finished.\n");
    return err;
error:
    Pa_Terminate();
    fprintf( stderr, "An error occured while using the portaudio stream\n" );
    fprintf( stderr, "Error number: %d\n", err );
    fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( err ) );
    return err;

    return true;
}

bool PaLayer::stop()
{
    return true;
}

static int PaCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
    paTestData *data = (paTestData*)userData;
    float *out = (float*)output;
    unsigned int i;
    (void) input; /* Prevent unused variable warning. */
    for( i=0; i<frameCount; i++ )
    {
        *out++ = data->left_phase; /* left */
        *out++ = data->right_phase; /* right */
        /* Generate simple sawtooth phaser that ranges between -1.0 and 1.0. */
        data->left_phase += 0.01f;
        /* When signal reaches top, drop back down. */
        if( data->left_phase >= 1.0f ) data->left_phase -= 2.0f;
        /* higher pitch so we can distinguish left and right. */
        data->right_phase += 0.03f;
        if( data->right_phase >= 1.0f ) data->right_phase -= 2.0f;
    }
    return 0;
}
