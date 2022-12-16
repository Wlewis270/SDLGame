#pragma once
#ifndef STATE_H
#define STATE_H

class StateManager;

class State
{
public:
	State() {
		
	}
	 ~State(){}
	 virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Initialise() = 0;
	virtual void Uninitialise() = 0;
protected:
	StateManager* m_stateManager;
};

#endif 