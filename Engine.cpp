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
#include "Engine.h"
SDL_Surface* surfaceMessage;
TTF_Font* Sans;
SDL_Texture* Message;
SDL_Rect test;
std::string IntToStringa(short n)
{
	std::stringstream sstream;
	sstream << n;
	return sstream.str();
}
void displaytext(const char * b, short a, SDL_Renderer * sr, int x, int y)
{
	 Sans = TTF_OpenFont("FreeSans.ttf", 18); //this opens a font style and sets a size
	if (!Sans) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	std::string text = b + IntToStringa(a);

	SDL_Color White = { 255, 255, 255 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
      surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	 Message = SDL_CreateTextureFromSurface(sr, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = x;  //controls the rect's x coordinate 
	Message_rect.y = y; // controls the rect's y coordinte
	Message_rect.w = surfaceMessage->w; // controls the width of the rect
	Message_rect.h = surfaceMessage->h; // controls the height of the rect
						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance
						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes
	SDL_RenderCopy(sr, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

	TTF_CloseFont(Sans);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);													  //Don't forget too free your surface and texture
}

void displaytext(const char * a, SDL_Renderer * sr, int x, int y)
{
	if (TTF_Init() == -1)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		system("pause");
	}
	TTF_Font* Sans = TTF_OpenFont("FreeSans.ttf", 18); //this opens a font style and sets a size
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
	Message_rect.w = surfaceMessage->w; // controls the width of the rect
	Message_rect.h = surfaceMessage->h; // controls the height of the rect
						 //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance
						 //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(sr, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
													  //Don't forget too free your surface and texture
	 /// memory leak problemc !!!!!!!!!
	TTF_CloseFont(Sans);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}
short answer;
short a;
short b;
void Engine::editormode()
{
	int xmouse;
	int ymouse;
	bool showins = true;
	bool showcol = true;
start:
	SDL_PollEvent(&se);
	switch (se.type)
	{
	case SDL_QUIT:
	{
		eisrunning = false;
	}
	break;
	case SDL_KEYDOWN:
		switch (se.key.keysym.sym)
		{
		case SDLK_e:
		{
			log("3-create new object\n1-create player\n2- crete npc\n5-Save objects\n6-Load objects\n7-Load characters\n8-Save Characters\n10-Save player\n11-Load player\n12-change object pos\n13-Change player pos\n14-Change object size");
			get(answer);
			switch (answer)
			{
			case 3: // object 
			{
				EngineObject new_object;
				log("Texture name");
				get(new_object.fname);
				log("x");
				get(new_object.objectrect.x);
				log("y");
				get(new_object.objectrect.y);
				log("w");
				get(new_object.objectrect.w);
				log("h");
				get(new_object.objectrect.h);
				log("angle (0 if not)");
				get(angle);
				log("tag");
				get(new_object.tag);
				log("finised !")
					new_object.init(true, false, sr, true);
				obv.push_back(new_object);
			
			} break;
			case 2: // npc
			{
				Character new_object;
				log("Texture name");
				get(new_object.fname);
				log("x");
				get(new_object.objectrect.x);
				log("y");
				get(new_object.objectrect.y);
				log("angle (0 if not)");
				get(angle1);
				log("tag");
				get(new_object.tag);
				system("cls");
				log("finised !")
					new_object.objectrect.w = 256;
				new_object.objectrect.h = 256;

					new_object.init(true, false, sr, true);
				new_object.initcharacter();

				chv.push_back(new_object);
			} break;
			case 1: // player
			{
				log("Texture name");
				get(player.fname);
				log("x");
				get(player.objectrect.x);
				log("y");
				get(player.objectrect.y);
				log("angle (0 if not)");
				get(angle1);
				log("tag");
				get(player.tag);
				system("cls");
				log("finised !")
					player.objectrect.w = 256;
				player.objectrect.h = 256;
					player.init(true, false, sr, true);
				player.initcharacter();
				player.inited = true;
				//chv.push_back(player);
			} break;
			case 9: // exit
			{
				goto start;
			}break;
			case 5: // saveo
			{
				 a = obv.size();
				ofstream kayit;
				kayit.open("objects.fceobject");
				kayit << a << endl;
				for (int i = 0; i < obv.size(); i++)
				{
					
					kayit << obv[i].fname<< endl;
					kayit << obv[i].objectrect.x << endl;
					kayit << obv[i].objectrect.y << endl;
					kayit << obv[i].objectrect.w << endl;
					kayit << obv[i].objectrect.h << endl;
					kayit << obv[i].tag << endl;
				}

				kayit.close();

				goto start;
			} break;
			case 6: // loado
			{
				
				ifstream yukle;
				yukle.open("objects.fceobject");
				yukle >> a;
				obv.resize(a);

				for (int i = 0; i < obv.size(); i++)
				{

					yukle >> obv[i].fname >> obv[i].objectrect.x >> obv[i].objectrect.y >> obv[i].objectrect.w >> obv[i].objectrect.h >> obv[i].tag;
					obv[i].init(true,false,sr,true);
				}

				yukle.close();

				goto start;
			}break;
			case 7: // loadc
			{

				ifstream yukle;
				yukle.open("characters.fceobject");
				yukle >> b;
				chv.resize(b);
				for (int i = 0; i < chv.size(); i++)
				{

					yukle >> chv[i].fname >> chv[i].objectrect.x >> chv[i].objectrect.y >> chv[i].tag;
					chv[i].init(true, false, sr, true);
				}

				yukle.close();

				goto start;
			}break;
			case 8: // savec
			{
				b = chv.size();
				
				ofstream kayit;
				kayit.open("characters.fcechr");
				kayit << a << endl;
				for (int i = 0; i < chv.size(); i++)
				{

					kayit << chv[i].fname << endl;
					kayit << chv[i].objectrect.x << endl;
					kayit << chv[i].objectrect.y << endl;
					kayit << chv[i].tag << endl;

				}




				kayit.close();

				goto start;
			} break;
			case 10: // save player
			{

				ofstream kayit;
				kayit.open("player.fceplr");
				kayit << player.fname << endl;
				kayit << player.objectrect.x << endl;
				kayit << player.objectrect.y << endl;
				kayit << player.tag << endl;
				kayit.close();
			} break;
			case 11: // load player
			{
				ifstream yukle;
				yukle.open("player.fceplr");
				yukle >> player.fname >> player.objectrect.x >> player.objectrect.y >> player.tag;
				player.init(true, false, sr, false);
				player.initcharacter();
				yukle.close();

			} break;
			case 12: // change object position
			{
				short gtag;
				log("object tag")
					get(gtag);

				for (int i = 0; i < obv.size(); i++)
				{

					if (obv[i].tag == gtag)
					{
						log(" new object x")
							get(obv[i].objectrect.x);
						log(" new object y")
							get(obv[i].objectrect.y);
						break;


					}

				}
			} break;
			case 13: // change player position
			{
						
						log(" new player x")
							get(player.objectrect.x);
						log(" new player y")
							get(player.objectrect.y);
			
			} break;
			case 14: // change object wh
			{
				short vtag;
				log("object tag")
					get(vtag);

				for (int i = 0; i < obv.size(); i++)
				{

					if (obv[i].tag == vtag)
					{
						log(" new object w")
							get(obv[i].objectrect.w);
						log(" new object h")
							get(obv[i].objectrect.h);
						break;

						


					}

				}

			} break;
			default:
				break;
			}

		} break;
		case SDLK_p:
		{
			editoron = false;


		}break;
		case SDLK_h:
		{
			showcol = false;

		}break;
		case SDLK_j:
		{
			
				showcol = true;
		}break;


		}
		break;
	default:
		break;
	}
	
	SDL_RenderClear(sr); /// render
	for (int i = 0; i < obv.size(); i++)
	{
		if (showcol)
		{
			SDL_SetRenderDrawColor(sr, 0, 0, 255, 255);

			// Render our "player"
			SDL_RenderFillRect(sr, &obv[i].objectrect);

			// Change color to green
			SDL_SetRenderDrawColor(sr, 60, 90, 34, 1);
		}
		obv[i].render(sr,  angle);

	}
	for (int i = 0; i < chv.size(); i++)
	{
		chv[i].render(sr, angle);
	}
	if (player.inited == true)
	{

		player.render(sr, 0);
	}
	SDL_GetMouseState(&xmouse, &ymouse);
	 
	/// cordinate is where top left starts
	displaytext("current inited object count :", obv.size(), sr, 10, 10);
	displaytext("current inited character count :", chv.size(), sr, 10, 30);
	displaytext("mouse x :", xmouse, sr, 500, 30);
	displaytext("mouse y :", ymouse, sr, 500, 70);
	if (showins)
	{
		/// show ins here
		displaytext("Press E key to open edtior mode", sr, 600, 150);	
	}
	SDL_RenderPresent(sr); /// render end
}

void Engine::playmode()
{
	
	SDL_PollEvent(&se);
	switch (se.type)
	{
	case SDL_QUIT:
	{
		eisrunning = false;
	}
	break;
	case SDLK_f:
	{
		editoron = true;
	} break;

	case SDL_KEYDOWN:
		switch (se.key.keysym.sym)
		{


		case SDLK_w:
		{
			if (player.alive == true)
			{
				player.move(0, -20);
			}
		}  break;

		case SDLK_a:
		{
			if (player.alive == true)
			{
				player.move(-20, 0);
			}
		}  break;
		case SDLK_d:
		{
			if (player.alive == true)
			{
				player.move(20, 0);
			}
		}    break;
		case SDLK_s:
		{
			if (player.alive == true)
			{
				player.move(0, 20);
			}
		}  break;
		case SDLK_k:
		{
			player.alive = false;

		} break;
		case SDLK_SPACE:
		{
			if (player.alive == true)
			{
				player.attack(20);
			}

		} break;
		}
		break;
	default:
		break;
	}

	//sword.objectrect.x = player.objectrect.x + 115;
	//	sword.objectrect.y = player.objectrect.y + 85;

	SDL_RenderClear(sr); /// render jobs

	player.displaytext("Stamina", player.stamina, sr, 128, 128);
	player.displaytext("Health", player.health, sr, 128, 30);
	if (player.alive)
	{
		player.render(sr, 0);
		//sword.render(sr, 256, 256, 90);
	}
	if (!player.alive && a == 0)
	{
		player.changetexture(sr, "dedplayer.png");
		a++;
	}
	if (!player.alive)
	{
		player.render(sr, 0);
	}
	for (int i = 0; i < obv.size(); i++)
	{
		obv[i].render(sr,  angle);
	}
	for (int i = 0; i < chv.size(); i++)
	{
		chv[i].render(sr,  angle);
	}

	SDL_RenderPresent(sr); /// render jobs ends


}
//---------------------------------------------------------------------
bool Engine::initgui()
{
	if (TTF_Init() == -1)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
		system("pause");
	}
	return 1;
}

Engine::Engine()
{
}


Engine::~Engine()
{	
}

bool Engine::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	sw = SDL_CreateWindow("Staby Stab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 700, SDL_WINDOW_SHOWN);
	sr = SDL_CreateRenderer(sw, -1, 0);
	SDL_SetRenderDrawColor(sr, 60, 90, 34, 1);

	

	if (sw == NULL && sr == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
	

}

bool Engine::render()
{

	// render





	SDL_RenderClear(sr);

	

	SDL_RenderPresent(sr);


	return false;
}

bool Engine::handleevent()
{

	/*SDL_PollEvent(&se);
	switch (se.type)
	{
	case SDL_QUIT:
	{

		eisrunning = false;
	}
	break;
	case SDLK_c:
	{
		return true;

	}
	break;
	default:
		break;
	}*/
	return true;
}
