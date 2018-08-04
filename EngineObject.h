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

class EngineObject 
{
public:
	
	SDL_Texture *texture;
	SDL_Surface *ss;
	SDL_Rect objectrect;
	SDL_Surface* surfaceMessage;
	SDL_Texture* Message;
	std::string fname;
	

	short tag;	
	bool inited;
	bool init(bool haveatexture, bool isasystem,SDL_Renderer* sr, bool npc);
	bool move(int x, int y);
	void render(SDL_Renderer *sr, double angle);
	void changetexture(SDL_Renderer *sr, const char* filename);
	void displaytext(const char * a, SDL_Renderer * sr, int x, int y);
	void displaytext(const char * b, short a, SDL_Renderer * sr, int x, int y);
	
	EngineObject();
	~EngineObject();
	
};

