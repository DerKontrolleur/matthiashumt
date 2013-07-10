#pragma once

#include <SDL.h>
#include "Vector.h"

class InputManager
{
private:
	bool RightMouseButton;
	bool LeftMouseButton;
	bool MouseWheelUp;
	bool MouseWheelDown;

	bool Up;
	bool Down;
	bool Left;
	bool Right;

	Vector2D<int> MousePosition;


	InputManager() : RightMouseButton(false), LeftMouseButton(false), MouseWheelUp(false), MouseWheelDown(false), Up(false), Down(false), Left(false), Right(false), MousePosition(NULL)
	{
		cout << "InputManager constructed" << endl;
	}

public:
	~InputManager()
	{
		cout << "KeyListener destroyed" << endl;
	}

	static InputManager* Instance();

	bool GetRightMousePressed() const {return this->RightMouseButton;}
	bool GetLeftMousePressed() const {return this->LeftMouseButton;}
	bool GetMouseWheelDown() const {return this->MouseWheelDown;}
	bool GetMouseWheelUp() const {return this->MouseWheelUp;}

	const Vector2D<int>& GetMousePosition() const {return this->MousePosition;}

	void SetRightMousePressed(bool bRightMouse) {this->RightMouseButton = bRightMouse;}
	void SetLeftMousePressed(bool bLeftMouse) {this->LeftMouseButton = bLeftMouse;}
	void SetMouseWheelDown(bool bWheelDown) {this->MouseWheelDown = bWheelDown;}
	void SetMouseWheelUp(bool bWheelUp) {this->MouseWheelUp = bWheelUp;}

	void SetMousePosition(int mousePositionX, int mousePositionY) {this->MousePosition.Set(mousePositionX, mousePositionY);}


	void SetUp(bool up) {this->Up = up;}
	void SetDown(bool down) {this->Down = down;}
	void SetLeft(bool left) {this->Left = left;}
	void SetRight(bool right) {this->Right = right;}

	bool GetUp() {return this->Up;}
	bool GetDown() {return this->Down;}
	bool GetLeft() {return this->Left;}
	bool GetRight() {return this->Right;}

	void InputEvents(SDL_Event& pSDLEvent);
};