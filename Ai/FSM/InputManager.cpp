#include "InputManager.h"

InputManager * InputManager::Instance()
{
	static InputManager Instance;

	return &Instance;
}

void InputManager::InputEvents(SDL_Event& Event)
{
	if(Event.type == SDL_MOUSEMOTION)
		this->MousePosition.Set(Event.motion.x, Event.motion.y);

	if(Event.type == SDL_MOUSEBUTTONDOWN)
	{
		switch(Event.button.button)
		{
		case SDL_BUTTON_LEFT:
			this->LeftMouseButton = true;
			break;
		case SDL_BUTTON_RIGHT:
			this->RightMouseButton = true;
			break;
		}
	}

	if(Event.type == SDL_MOUSEBUTTONUP)
	{
		switch(Event.button.button)
		{
		case SDL_BUTTON_LEFT:
			this->LeftMouseButton = false;
			break;
		case SDL_BUTTON_RIGHT:
			this->RightMouseButton = false;
			break;
		case SDL_BUTTON_WHEELUP:
			this->MouseWheelUp = true;
			break;
		case SDL_BUTTON_WHEELDOWN:
			this->MouseWheelDown = true;
			break;
		}
	}

	if(Event.type == SDL_KEYDOWN)
	{
		switch(Event.key.keysym.sym)
		{
		case SDLK_UP:
			this->Up = true;
			break;
		case SDLK_DOWN:
			this->Down = true;
			break;
		case SDLK_LEFT:
			this->Left = true;
			break;
		case SDLK_RIGHT:
			this->Right = true;
			break;
		}
	}


	if(Event.type == SDL_KEYUP)
	{
		switch(Event.key.keysym.sym)
		{
		case SDLK_UP:
			this->Up = false;
			break;
		case SDLK_DOWN:
			this->Down = false;
			break;
		case SDLK_LEFT:
			this->Left = false;
			break;
		case SDLK_RIGHT:
			this->Right = false;
			break;
		}
	}
}