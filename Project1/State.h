#pragma once
 #include"StateManager.h"
class State
{
public:
	State(StateManager* statemanager) {
		m_stateManager = statemanager;
	}
	
	 void Update(){}
	 void Render(){}
	 void Initialise(){}
	 void Uninitialise() {}
protected:
	StateManager* m_stateManager;
};

