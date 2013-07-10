#include "UpdateManager.h"

UpdateManager * UpdateManager::Instance()
{
	static UpdateManager Instance;

	return &Instance;
}


void UpdateManager::InitializeProgramm()
{
	cout << "Initializing program..." << endl;

	srand(static_cast<unsigned>(time(NULL)));

	this->ProgramTimer.start();
	this->UpdateTimer.start();
	this->DeltaTimer.start();
	this->FPSTimer.start();
	this->PrintTimer.start();

	RM->LoadContent();

	EM->CreateScope(500, 500);
	RM->SetScreen(SDL_SetVideoMode(EM->GetScope().GetSize().X, EM->GetScope().GetSize().Y, 32, SDL_SWSURFACE | SDL_RESIZABLE));

	EM->CreateAgent(300.0, 300.0, Lydia, black);
	EM->CreateAgent(100.0, 100.0, Samuel, red);
}

void UpdateManager::ManageInput()
{
	while(SDL_PollEvent(&this->Event))
	{	
		if(this->Event.type == SDL_QUIT)
		{
			exit(NULL);
		}

		if(this->Event.type == SDL_VIDEORESIZE)
		{
			EM->GetScope().SetSize(Event.resize.w, Event.resize.h);
			RM->SetScreen(SDL_SetVideoMode(EM->GetScope().GetSize().X, EM->GetScope().GetSize().Y, 32, SDL_SWSURFACE | SDL_RESIZABLE));
		}

		IM->InputEvents(this->Event);
	}

	if(IM->GetUp())
		EM->GetAgent(0)->GetVelocity().Y = -100.0;
	else if(IM->GetDown())
		EM->GetAgent(0)->GetVelocity().Y = 100.0;
	else if(IM->GetLeft())
		EM->GetAgent(0)->GetVelocity().X = -100.0;
	else if(IM->GetRight())
		EM->GetAgent(0)->GetVelocity().X = 100.0;
	else EM->GetAgent(0)->SetVelocity(0);
}

void UpdateManager::UpdateFPS()
{
	this->FPS++;

	if(FPSTimer.Getticks() >= ONE_SECOND)
	{
		cout << "FPS: " << this->FPS << endl;

		this->FPSTimer.start();

		this->FPS = 0;
	}
}

template <typename temp>
void UpdateManager::Print(const temp& msg)
{
	this->PrintCounter++;

	if(this->PrintTimer.Getticks() >= ONE_SECOND)
	{
		cout << msg << endl;

		this->PrintTimer.start();

		this->PrintCounter = 0;
	}
}

void UpdateManager::UpdateAgents()
{
	MM->SendDelayedMessages();

	for(this->it = EM->GetAgents()->begin(); this->it != EM->GetAgents()->end(); this->it++)
	{
		(*this->it)->UpdateCondition();
		(*this->it)->UpdatePerception();
		(*this->it)->UpdateAI();
	}

	for(this->it = EM->GetAgents()->begin(); this->it != EM->GetAgents()->end(); this->it++)
	{
		(*this->it)->UpdatePosition(this->DeltaTimer.Getticks());
	}
	this->DeltaTimer.start();

	for(this->it = EM->GetAgents()->begin(); this->it != EM->GetAgents()->end(); this->it++)
	{
		(*this->it)->Render();
	}
}

void UpdateManager::UpdateWorld()
{
	EM->GetScope().Render();
}

void UpdateManager::Update()
{
	PM->CheckCollision();

	UpdateWorld();

	UpdateAgents();

	if(this->UpdateTimer.Getticks() >= X100)
	{
		assert(SDL_Flip(RM->GetScreen()) != -1 && "<GameManager::Update>: Error flipping screen");
		this->UpdateTimer.start();
	}
}

