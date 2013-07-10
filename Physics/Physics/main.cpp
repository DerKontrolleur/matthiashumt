#include "GameManager.h"

int main(int argc, char ** argv)
{
	GameManager::Instance()->InitializeGame();

	while(1)
	{
		GameManager::Instance()->UpdateFPS();

		GameManager::Instance()->ManageInput();
	}

	return 0;
}