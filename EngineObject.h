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

