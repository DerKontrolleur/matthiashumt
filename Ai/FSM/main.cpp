#include "UpdateManager.h"

int main(int argc, char ** argv)
{
	UM->InitializeProgramm();

	while(1)
	{
		UM->UpdateFPS();

		UM->ManageInput();

		UM->Update();
	}
	return 0;
}