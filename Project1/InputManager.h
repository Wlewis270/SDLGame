#pragma once
#include <vector>
#include <SDL.h>

class InputManager
{
public:
	InputManager();
	bool GetKeyUp(SDL_Keycode key);
	bool GetKeyHeld(SDL_Keycode key);
	bool GetKeyDown(SDL_Keycode key);
	void Update();

private:
	int KEYS[290];
	std::vector<SDL_Keycode> key_up;
	std::vector<SDL_Keycode> key_down;
};
