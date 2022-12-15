#include "StateManager.h"
#include "StartState.h"
#include"Game.h"


StateManager::StateManager()
{
	m_currentState = m_States[START];


}

void StateManager::Initialise()
{
	m_States[START] = new StartState;
	m_States[GAME] =  Game::Get();
	
}

void StateManager::SetState( States st)
{
	m_currentState->Uninitialise();
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
