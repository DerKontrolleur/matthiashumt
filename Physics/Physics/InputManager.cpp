#include "InputManager.h"

InputManager * InputManager::Instance()
{
	static InputManager Instance;

	return &Instance;
}

void InputManager::InputEvents(SDL_Event * pSDLEvent)
{
		switch(pSDLEvent->type)
		{
			case SDL_MOUSEMOTION:
				this->m_pvMousePosition->Set(pSDLEvent->motion.x, pSDLEvent->motion.y);
			break;

			case SDL_MOUSEBUTTONDOWN:
				if(pSDLEvent->button.button == SDL_BUTTON_LEFT)
					this->m_bLeftMousePressed = true;
				if(pSDLEvent->button.button == SDL_BUTTON_RIGHT)
					this->m_bRightMousePressed = true;

			break;

			case SDL_MOUSEBUTTONUP:
				if(pSDLEvent->button.button == SDL_BUTTON_LEFT)
					this->m_bLeftMousePressed = false;
				if(pSDLEvent->button.button == SDL_BUTTON_RIGHT)
					this->m_bRightMousePressed = false;
				if(pSDLEvent->button.button == SDL_BUTTON_WHEELUP)
					this->m_bMouseWheelUp = true;
				if(pSDLEvent->button.button == SDL_BUTTON_WHEELDOWN)
					this->m_bMouseWheelDown = true;
			break;
		}
}