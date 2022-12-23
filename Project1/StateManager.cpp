#include "StateManager.h"
#include "StartState.h"
#include"Game.h"
#include "GameOverState.h"
#include "GameWinState.h"


StateManager::StateManager()
{
	


}

void StateManager::Initialise()
{
	m_States[START] = new StartState(this);
	m_States[GAME] =  Game::init(this);
	m_States[GAMEOVER] = new GameOverState(this);
	m_States[GAMEWIN] = new GameWinState(this);
	SetState(START);
}

void StateManager::SetState( States st)
{
	if (m_currentState != nullptr) {
		m_currentState->Uninitialise();
	}
	m_currentState = m_States[st];
	
	m_currentState->Initialise();
}

void StateManager::update()
{
	m_currentState->Update();
}

void StateManager::render()
{
	m_currentState->Render();
}
