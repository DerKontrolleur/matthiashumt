#pragma once

#include <SDL.h>

#include "Globals.h"


class InputManager
{
private:
	bool m_bRightMousePressed;
	bool m_bLeftMousePressed;
	bool m_bMouseWheelUp;
	bool m_bMouseWheelDown;

	Vector2D * m_pvMousePosition;
	Vector2D * m_pvMouseVelocity;

public:
	InputManager() : m_bRightMousePressed(false), m_bLeftMousePressed(false), m_bMouseWheelUp(false), m_bMouseWheelDown(false)
	{
		m_pvMousePosition = new Vector2D(g_vNullVector2D);
		m_pvMouseVelocity = new Vector2D(g_vNullVector2D);

		cout << "Constructor InputManager called" << endl;
	}

	~InputManager()
	{
		delete m_pvMousePosition; 
		delete m_pvMouseVelocity;

		cout << "Destructor KeyListener called" << endl;
	}

	static InputManager * Instance();

	bool GetRightMousePressed() const {return this->m_bRightMousePressed;}
	bool GetLeftMousePressed() const {return this->m_bLeftMousePressed;}
	bool GetMouseWheelDown() const {return this->m_bMouseWheelDown;}
	bool GetMouseWheelUp() const {return this->m_bMouseWheelUp;}

	Vector2D * GetMousePosition() {return this->m_pvMousePosition;}

	void SetRightMousePressed(bool bRightMouse) {this->m_bRightMousePressed = bRightMouse;}
	void SetLeftMousePressed(bool bLeftMouse) {this->m_bLeftMousePressed = bLeftMouse;}
	void SetMouseWheelDown(bool bWheelDown) {this->m_bMouseWheelDown = bWheelDown;}
	void SetMouseWheelUp(bool bWheelUp) {this->m_bMouseWheelUp = bWheelUp;}

	void SetMousePosition(int dMousePositionX, int dMousePositionY) {this->m_pvMousePosition = m_pvMousePosition;}


	void InputEvents(SDL_Event * pSDLEvent);


	bool CheckMouseOver(int nID);
	int CheckMouseOver();

	void ProcessInput();
};