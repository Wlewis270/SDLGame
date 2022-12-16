#include <SDL.h>
#include "Game.h"
#include"StartState.h"
#include"StateManager.h"
int main(int argc, char* argv[])
{
	StateManager statestuf;
	
	statestuf.Initialise();
	
	
	while (1)
	{
		statestuf.update();
		statestuf.render();
	}
	
	/*if (game->IsGameRunning() == false)
	{
		return 1;
	}*/
}


