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
	
	
	e.setup();
	
	while (e.eisrunning)
	{

		if (e.editoron == true)
		{
			e.editormode();
		}
		else if (e.editoron == false)
		{
			e.playmode();
		}
		
	
	}
	

	
	SDL_DestroyWindow(e.sw);
	SDL_DestroyRenderer(e.sr);
	SDL_Quit();
		return 0;
}





