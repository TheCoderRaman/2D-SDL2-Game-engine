#pragma once
#include<SDL.h>
#include <sdl_mixer.h>
class Sound
{
public:
	void init();
	void play();
	Mix_Music *mus, *mus2;  // Background Music
	Sound();
	~Sound();
};

