#include "Sound.h"



void Sound::init()
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);
	// Setup audio mode
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	
	
	mus = Mix_LoadMUS("main.wav");

}

void Sound::play()
{
	Mix_PlayMusic(mus, 1); //Music loop=1
}

Sound::Sound()
{
}


Sound::~Sound()
{
}
