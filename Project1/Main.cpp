#include <SDL.h>
#include "Game.h"
#include"StartState.h"
#include"StateManager.h"
#include"Score.h"
int main(int argc, char* argv[])
{
	StateManager statestuf;
	
	statestuf.Initialise();
	Score* score = score->Get();

	score->SetScore(9);
	score->Initialise();
	
	while (1)
	{
		score->Update();
		statestuf.update();
		statestuf.render();
		
	}
	
	/*if (game->IsGameRunning() == false)
	{
		return 1;
	}*/
}


