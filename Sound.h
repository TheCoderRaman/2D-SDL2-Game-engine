#pragma once
#include<SDL.h>
#include <sdl_mixer.h>
#include <iostream>
class Sound
{
public:
	void init(std::string str);
	void play();
	Mix_Music *mus, *mus2;  // Background Music
	Sound();
	~Sound();
};

