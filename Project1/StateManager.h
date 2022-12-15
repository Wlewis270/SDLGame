#pragma once
#include"iState.h"

class StateManager
{
public:
	enum States { START, GAME,  };
	void Initialise();
	void SetState( States st );
	void update();
	void render();

private:
	
	
	iState* m_States[2];
	iState* m_currentState;
};

