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

Engine e;


using namespace std;




int main(int argc, char* args[])
{
	
	// if not enough mem, than welcome e to heap ;)
	e.eisrunning = e.init();
	
	e.initgui();


	/*
	player.init(true, false,e.sr,true, "Untitled.png");
	sword.init(true, false, e.sr, false, "mythicalsword.png");*/
	/*
	player.initcharacter();
	player.objectrect.x = 12;
	player.objectrect.y = -12;*/
	
	e.s.init();
	e.s.play();
	while (e.eisrunning)
	{

		if (e.editoron)
		{
			e.editormode();
		}
		else
		{
			e.playmode();
		}
		
	
	}
	

	
	SDL_DestroyWindow(e.sw);
	SDL_DestroyRenderer(e.sr);
	SDL_Quit();
		return 0;
}





