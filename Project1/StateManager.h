#pragma once
#include"iState.h"
#include"StartState.h" 
enum States { START, GAME };
class StateManager
{

public:
	StateManager();

	void Initialise();
	void SetState(States st);
	void update();
	void render();

private:

	iState* m_States[2];
	iState* m_currentState;
};

