#pragma once


#include "Include.h"
#include "Sound.h"
#include "Character.h"

using namespace std;


class Engine
{
public:

	SDL_Renderer * sr;
	SDL_Window *sw;
	bool eisrunning;
	//----------------
	vector<EngineObject> obv;
	vector<Character> chv;
	bool editoron = true;
	
	SDL_Event se;

	Sound s;
	short a = 0;
	Character player;

	double angle = 0;
	double angle1 = 0;

	Engine();
	~Engine();

	bool init();
	bool render();
	bool handleevent();
	void playmode();
	void editormode();
	bool initgui();
};



