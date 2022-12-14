#include "Game.h"
#include <iostream>
#include "Visualisation.h"
#include "InputManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Entity.h"
#include "Object.h"
#include <vector>
#include "StateManager.h"


Game* Game::s_instance = nullptr;

Game* Game::init(StateManager* stateManager)
{
	if (s_instance == nullptr)
	{
		s_instance = new Game(stateManager);
		return s_instance;
	}

	return s_instance;
}


void Game::Update()
{
	game_inputmanager->Update();
	game_player->Update();
	
	if (EnemyOnScreen() == false)
	{
		game_enemies.push_back(game_enemy);
		
		game_enemies.push_back(game_enemy2);

		SpawnEnemy(game_enemies[0]);
		SpawnEnemy(game_enemies[1]);
	}
	
	else
	{
		for (int i = 0; i < game_enemies.size(); i++)
		{
			game_enemies[i]->Update(game_player);
		}
	}

	if (enemies_dead == 20)
	{
		m_stateManager->SetState(GAMEWIN);
	}

	if (player_health == 3)
	{
		m_stateManager->SetState(GAMEOVER);
	}

	if (game_inputmanager->GetKeyDown(SDLK_ESCAPE))
	{
		Uninitialise();
		SDL_Quit();
	}

	Render();

}

void Game::Render()
{
	SDL_RenderClear(game_renderer);
	SDL_SetRenderDrawColor(game_renderer, 0, 0, 255, 255);
	game_player->Render();
	
	if (game_enemies.size() > 0)
	{
		for (int i = 0; i < game_enemies.size(); i++)
		{
			game_enemies[i]->Render();
		}

		SDL_RenderPresent(game_renderer);
		SDL_Delay(1000 / 60);

	}
}

bool Game::IsGameRunning()
{
	return true;
}

void Game::Initialise()
{
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL Init failed";
		return;
	}

	game_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
	enemies_dead = 0;
	player_health = 0;
	game_renderer = SDL_CreateRenderer(game_window, -1, 0);
	game_inputmanager = new InputManager;
	game_visualisation->Initialise(game_renderer);
	game_enemy = new Enemy("", 100, 5, 1000);
	game_enemy2 = new Enemy("", 100, 5, 0);
	game_player = new Player("Player",100, 5, game_inputmanager);
	game_player->Initialise();
}

void Game::Uninitialise()
{
	SDL_DestroyRenderer(game_renderer);
	SDL_DestroyWindow(game_window);
	delete game_visualisation;
}

Object* Game::CheckCollisions(Object* ent)
{
	bool collision_checked = false;
	
	while (collision_checked == false)
	{
		for (int i = 0; i < game_enemies.size(); i++) {
			if (TestBlockCollision(ent, game_enemies[i]))
			{
				if (ent != game_player)
				{
					Object* temp = game_enemies[i];
					game_enemies.erase(game_enemies.begin() + i);
					enemies_dead = enemies_dead + 1;
					return temp;
				}
				player_health = player_health + 1;
				return game_enemies[i];
			}

			if (ent == game_enemies[i])
			{
				if (TestBlockCollision(ent, game_player))
				{
					return game_player;
				}
				return nullptr;
			}
		}

		return nullptr;
	}
}

bool Game::TestBlockCollision(Object* ent, Object* ent2)
{
	Ent_rect = ent->GetLocation();
	Ent_rect2 = ent2->GetLocation();

	int EntminX = Ent_rect->x;
	int EntminY = Ent_rect->y;
	int EntmaxX = Ent_rect->x + Ent_rect->w;
	int EntmaxY = Ent_rect->y + Ent_rect->h;

	int Ent2minX = Ent_rect2->x;
	int Ent2minY = Ent_rect2->y;
	int Ent2maxX = Ent_rect2->x + Ent_rect2->w;
	int Ent2maxY = Ent_rect2->y + Ent_rect2->h;

	if (EntminY > Ent2maxY)
	{
		return false;
	}

	if (EntmaxY < Ent2minY)
	{
		return false;
	}

	if (Ent2minX > EntmaxX)
	{
		return false;
	}

	if (Ent2maxX < EntminX)
	{
		return false;
	}

	return true;
}

void Game::SpawnEnemy(Enemy* enemy)
{
	enemy->Initialise();
}

bool Game::EnemyOnScreen()
{
	if (game_enemies.size() == 0)
	{
		return false;
	}
	return true;
}

void Game::DeleteEnemy(Object* enemy)
{
	delete enemy;
}

Game::Game(StateManager* stateManager) :State(stateManager)
{
}

Game* Game::Get()
{
	return s_instance;
}