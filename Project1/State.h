#pragma once
#ifndef STATE_H
#define STATE_H

 #include"StateManager.h"
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
	static State* current;
	static State* start, *game;
protected:
	StateManager* m_stateManager;
};

#endif 