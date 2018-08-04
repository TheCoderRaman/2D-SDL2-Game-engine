/*******************************************************************
   Copyright 2018 Mehmet ÖZGÜN

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
***********************************************************************/
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



