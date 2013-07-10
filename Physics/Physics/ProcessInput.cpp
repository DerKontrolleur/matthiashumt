#include "GameManager.h"

bool InputManager::CheckMouseOver(int nID)
{
	if(GameManager::Instance()->GetID() > nID)
	{
		if(
			static_cast<int>(InputManager::Instance()->GetMousePosition()->x) >= static_cast<int>(GameManager::Instance()->GetObject(nID)->GetPosition()->x - GameManager::Instance()->GetObject(nID)->GetRadius()) &&
			static_cast<int>(InputManager::Instance()->GetMousePosition()->x) <= static_cast<int>(GameManager::Instance()->GetObject(nID)->GetPosition()->x + GameManager::Instance()->GetObject(nID)->GetRadius()) &&
			static_cast<int>(InputManager::Instance()->GetMousePosition()->y) >= static_cast<int>(GameManager::Instance()->GetObject(nID)->GetPosition()->y - GameManager::Instance()->GetObject(nID)->GetRadius()) &&
			static_cast<int>(InputManager::Instance()->GetMousePosition()->y) <= static_cast<int>(GameManager::Instance()->GetObject(nID)->GetPosition()->y + GameManager::Instance()->GetObject(nID)->GetRadius())
			)
				return true;
	}

	return false;
}

int InputManager::CheckMouseOver()
{
	if(GameManager::Instance()->GetID() > 0)
	{
		for(int i = 0; i < GameManager::Instance()->GetID(); i++)
		{
		if(
			static_cast<int>(InputManager::Instance()->GetMousePosition()->x) >= static_cast<int>(GameManager::Instance()->GetObject(i)->GetPosition()->x - GameManager::Instance()->GetObject(i)->GetRadius()) &&
			static_cast<int>(InputManager::Instance()->GetMousePosition()->x) <= static_cast<int>(GameManager::Instance()->GetObject(i)->GetPosition()->x + GameManager::Instance()->GetObject(i)->GetRadius()) &&
			static_cast<int>(InputManager::Instance()->GetMousePosition()->y) >= static_cast<int>(GameManager::Instance()->GetObject(i)->GetPosition()->y - GameManager::Instance()->GetObject(i)->GetRadius()) &&
			static_cast<int>(InputManager::Instance()->GetMousePosition()->y) <= static_cast<int>(GameManager::Instance()->GetObject(i)->GetPosition()->y + GameManager::Instance()->GetObject(i)->GetRadius())
			)
				return i;
		}
	}

	return g_MaxObjects;
}

void InputManager::ProcessInput()
{
	if(1)
		GameManager::Instance()->ManageObjects();

	if(InputManager::Instance()->GetLeftMousePressed() && CheckMouseOver() == g_MaxObjects)
	{
		GameManager::Instance()->CreateObject(GameManager::Instance()->GetTempMaterial(), GameManager::Instance()->GetTempShape(), GameManager::Instance()->GetTempColor());
	}

	else if(InputManager::Instance()->GetLeftMousePressed() && CheckMouseOver() < g_MaxObjects)
	{
		GameManager::Instance()->DragObject(CheckMouseOver());
	}

	if(InputManager::Instance()->GetRightMousePressed())
	{
		GameManager::Instance()->DeleteObject(InputManager::Instance()->CheckMouseOver());
	}

	if(InputManager::Instance()->GetMouseWheelDown())
	{
		switch(GameManager::Instance()->GetTempColor())
		{
		case red:
			GameManager::Instance()->SetTempColor(green);
		break;
		case green:
			GameManager::Instance()->SetTempColor(blue);
		break;
		case blue:
			GameManager::Instance()->SetTempColor(black);
		break;
		case black:
			GameManager::Instance()->SetTempColor(red);
		break;
		default:
			GameManager::Instance()->SetTempColor(black);
		break;
		}
		
		InputManager::Instance()->SetMouseWheelDown(false);
	}

	if(InputManager::Instance()->GetMouseWheelUp())
	{
		switch(GameManager::Instance()->GetTempColor())
		{
		case red:
			GameManager::Instance()->SetTempColor(black);
		break;
		case green:
			GameManager::Instance()->SetTempColor(red);
		break;
		case blue:
			GameManager::Instance()->SetTempColor(green);
		break;
		case black:
			GameManager::Instance()->SetTempColor(blue);
		break;
		default:
			GameManager::Instance()->SetTempColor(black);
		break;
		}
		
		InputManager::Instance()->SetMouseWheelUp(false);
	}
}