#include "EngineObject.h"

#include <string>
#include <string.h>
#include <iostream>

std::string IntToString(short n)
{
	std::stringstream sstream;
	sstream << n;
	return sstream.str();
}


bool EngineObject::init(bool haveatexture, bool isasystem, SDL_Renderer*sr, bool npc)
{
	
	

	if (haveatexture)
	{
		if (TTF_Init() == -1)
		{
			printf("TTF_Init: %s\n", TTF_GetError());
			system("pause");
		}
		// set texture
		ss = IMG_Load(fname.c_str());
		if (!ss)
		{
			std::cout << "cannot" << IMG_GetError() << std::endl;
			system("pause");
		}
		texture = SDL_CreateTextureFromSurface(sr,ss);
		if (texture == NULL)
		{
			std::cout << SDL_GetError() << std::endl;
			system("pause");
		}
		inited = true;
		
	}
	else
	{
		texture = nullptr;
		ss = nullptr;
	}
	if (isasystem)
	{
		
	}
	return false;
}

bool EngineObject::move(int x, int y)
{
	objectrect.x += x;
	objectrect.y += y;


	return true;
}



void EngineObject::render(SDL_Renderer *sr, double angle)
{
	
	
//	SDL_RenderClear(sr);
	if (angle == 0)
	{
		SDL_RenderCopy(sr, texture, NULL, &objectrect);
	}
	
	//SDL_RenderFillRect(sr, &objectrect);
	


	SDL_RenderCopyEx(sr, texture, NULL, &objectrect,angle,NULL, SDL_FLIP_NONE);

	//SDL_RenderPresent(sr);

	

	
}

void EngineObject::changetexture(SDL_Renderer *sr,  const char * filename)
{
	// set texture
	ss = IMG_Load(filename);
	if (!ss)
	{
		std::cout << "cannot" << IMG_GetError() << std::endl;
		system("pause");
	}
	texture = SDL_CreateTextureFromSurface(sr, ss);
	if (texture == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		system("pause");
	}
	inited = true;
}

void EngineObject::displaytext(const char * a, SDL_Renderer * sr, int x, int y)
{
	if (TTF_Init() == -1)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		system("pause");
	}


	TTF_Font* Sans = TTF_OpenFont("FreeSans.ttf", 24); //this opens a font style and sets a size
	if (!Sans) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}

	SDL_Color White = { 255, 255, 255 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, a, White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(sr, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = x;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 70; // controls the height of the rect

						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(sr, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

														//Don't forget too free your surface and texture

}

void EngineObject::displaytext(const char * b,short a, SDL_Renderer * sr, int x, int y)
{
	


	TTF_Font* Sans = TTF_OpenFont("FreeSans.ttf", 24); //this opens a font style and sets a size
	if (!Sans) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	std::string text = b + IntToString(a);

	SDL_Color White = { 255, 255, 255 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color

	surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	Message = SDL_CreateTextureFromSurface(sr, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = x;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = surfaceMessage->h; // controls the width of the rect
	Message_rect.h = surfaceMessage->w; // controls the height of the rect

						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(sr, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

													  //Don't forget too free your surface and texture
}

EngineObject::EngineObject()
{
}


EngineObject::~EngineObject()
{
	
}
