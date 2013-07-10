#pragma once

#include "InputManager.h"
#include "RessourceManager.h"
#include "PhysicsManager.h"
#include "MessageManager.h"
#include "StateMachine.h"
#include "Timer.h"

class UpdateManager
{
private:
	int FPS;
	Timer FPSTimer;
	Timer DeltaTimer;
	Timer UpdateTimer;
	Timer ProgramTimer;

	int PrintCounter;
	Timer PrintTimer;

	SDL_Event Event;

	StateMachine<UpdateManager> Menu;

	vector<Agent*>::iterator it;


	UpdateManager() : FPS(NULL), PrintCounter(NULL), Menu(this)
	{
		this->it = EM->GetAgents()->begin();

		cout << "Program start" << endl;
	}

public:
	~UpdateManager()
	{
		cout << "Program end" << endl;
	}

	static UpdateManager* Instance();

	void InitializeProgramm();
	void ManageInput();
	void UpdateFPS();
	void Update();

	void UpdateAgents();
	void UpdateWorld();

	template <typename temp>
	void Print(const temp& msg);

	Timer& GetDeltaTimer() {return this->DeltaTimer;}
	double GetTime() {return this->ProgramTimer.Getticks()/ONE_SECOND;}
};