#pragma once
#include "StateManager.h"
class iState
{
public:
	iState() {

	}

	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Initialise() = 0;
	virtual void Uninitialise() = 0;
private:

};

