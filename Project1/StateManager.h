#pragma once
#include"State.h"

enum States { START, GAME };
class StateManager{

public:
	StateManager();

	void Initialise();
	void SetState(States st);
	void update();
	void render();

private:

	State* m_States[2];
	State* m_currentState;
};
