#include <SDL.h>
#include <stdio.h>


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[])
{
    int i;
    int num_of_audio_drivers = SDL_GetNumAudioDrivers();
    printf("Number of audio drivers:- %d", num_of_audio_drivers);
    for (i = 0; i < num_of_audio_drivers; ++i)
    {
        const char* driver_name = SDL_GetAudioDriver(i);
//        if(SDL_AudioInit(driver_name))
//        {
//            printf("Audio driver failed to initialize: %s\n", driver_name);
//            continue;
//        }
//        SDL_AudioQuit();
        printf("\nAudio Driver %d is %s\n", i , driver_name);
    }
    return 0;
}
