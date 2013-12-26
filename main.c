#include<stdio.h>
#include<portaudio.h>


int main(int argc, char* argv[])
{
    PaError err;
    int numDevices;
    int i;

    printf("Port Audio version number %d\n",Pa_GetVersion());

    err = Pa_Initialize();
    if( err !=paNoError )
    {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
    }

    numDevices = Pa_GetDeviceCount();

    if(numDevices < 0)
    {
         printf( "ERROR: Pa_CountDevices returned 0x%x\n", numDevices );
    }
    else
    {
        PaDeviceInfo *deviceInfo;
        for(i = 0; i < numDevices; i++)
        {
            deviceInfo = Pa_GetDeviceInfo(i);
            printf("\n%d %s",i,deviceInfo->name);
        }
    }

    err = Pa_Terminate();
    if( err != paNoError )
        printf( "PortAudio error: %s\n", Pa_GetErrorText( err ) );

    return 0;
}
