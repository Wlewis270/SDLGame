#include <SDL.h>
#include "Game.h"


int main(int argc, char* argv[])
{
	Game* game = Game::Get();

	game->Initialise();
	while (game->IsGameRunning() == true)
	{
		game->Update();
	}
	if (game->IsGameRunning() == false)
	{
		return 1;
	}
}
}

