#include "InputManager.h"

InputManager::InputManager()
{
	for (int i = 0; i < 290; i++)
	{
		KEYS[i] = 0;
	}
}

bool InputManager::GetKeyUp(SDL_Keycode key)
{
	return std::find(key_up.begin(), key_up.end(), key) != key_up.end();
}

bool InputManager::GetKeyHeld(SDL_Keycode key)
{
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key);

	return KEYS[scancode] == 1;
}

bool InputManager::GetKeyDown(SDL_Keycode key)
{
	return std::find(key_down.begin(), key_down.end(), key) != key_down.end();
}

void InputManager::Update()
{
	SDL_Event temp_event;

	key_up.clear();
	key_down.clear();

	while (SDL_PollEvent(&temp_event))
	{
		switch (temp_event.type)
		{
		case SDL_KEYDOWN:
		{
			KEYS[temp_event.key.keysym.scancode] = 1;
			key_down.push_back(temp_event.key.keysym.sym);
		}
		case SDL_KEYUP:
		{
			KEYS[temp_event.key.keysym.scancode] = 0;
			key_up.push_back(temp_event.key.keysym.sym);
		}
		}
	}
}
