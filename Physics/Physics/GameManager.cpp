#include "GameManager.h"

GameManager * GameManager::Instance()
{
	static GameManager Instance;

	return &Instance;
}


void GameManager::InitializeGame()
{
	this->GameTime->start();
	this->DeltaTime->start();
	this->FPSTime->start();

	srand(static_cast<unsigned>(time(NULL)));

	this->GameWorld = new World(1600, 800, wood);

	assert(GameWorld);

	RessourceManager::Instance()->LoadContent();

	RessourceManager::Instance()->SetScreen(SDL_SetVideoMode(static_cast<int>(this->GameWorld->GetSize()->x), static_cast<int>(this->GameWorld->GetSize()->y), 32, SDL_SWSURFACE | SDL_RESIZABLE));

	//this->RootTree = new QuadTree(Rect(static_cast<int>(g_vNullVector2D.x), static_cast<int>(g_vNullVector2D.y), static_cast<int>(this->GameWorld->GetSize()->x), static_cast<int>(this->GameWorld->GetSize()->y)));
}

void GameManager::ManageInput()
{
	while(SDL_PollEvent(&pSDLEvent))
	{	
		if(pSDLEvent.type == SDL_QUIT)
		{
			exit(0);
		}

		if(pSDLEvent.type == SDL_VIDEORESIZE)
		{
			this->GameWorld->SetSize(pSDLEvent.resize.w, pSDLEvent.resize.h);
			RessourceManager::Instance()->SetScreen(SDL_SetVideoMode(static_cast<int>(this->GameWorld->GetSize()->x), static_cast<int>(this->GameWorld->GetSize()->y), 32, SDL_SWSURFACE | SDL_RESIZABLE));
		}
			
		InputManager::Instance()->InputEvents(&pSDLEvent);
	}

	InputManager::Instance()->ProcessInput();
}

void GameManager::UpdateFPS()
{
	m_nFPSCounter++;

	if(FPSTime->Getticks() >= 1000.0f)
	{
		FPS = m_nFPSCounter;
		cout << "FPS: " << m_nFPSCounter << endl;

		FPSTime->start();

		m_nFPSCounter = NULL;
	}
}

void GameManager::CreateObject(Materials Material, Shapes Shape, Colors Color)
{
	if(this->ID <= g_MaxObjects)
	{
		Objects[this->ID] = new Object(this->ID, sphere, *InputManager::Instance()->GetMousePosition(), g_vNullVector2D, this->RandomNumber(), Material, Color);

		assert(Objects[this->ID]);

		this->ID++;
	}
	else
		cout << "Max number of objects created" << endl;
}

void GameManager::DeleteObject(int nID)
{
	if(nID < this->ID)
	{
		delete Objects[nID];

		for(int i = nID+1; i < this->ID; i++)
		{
			Objects[i-1] = Objects[i];
			Objects[i]->SetID(Objects[i]->GetID() - 1);
		}

		this->ID--;
	}
}

void GameManager::RenderObjects()
{
	GameWorld->Render();

	if(this->ID > 0)
	{
		for(int i = 0; i < this->ID; i++)
		{
			this->Objects[i]->Render();
		}
	}

	if(this->GameTime->Getticks() >= 10.0f)
	{
		assert(SDL_Flip(RessourceManager::Instance()->GetScreen()) != -1);
		this->GameTime->start();
	}
}

void GameManager::ManageObjects()
{
	//this->RootTree->Generate(this->Objects, this->ID);
	

	MoveObjects(DeltaTime->Getticks());
	CheckCollision(this->ID, this->Objects, this->GameWorld, this->DeltaTime->Getticks());
	this->DeltaTime->start();

	RenderObjects();
	
}

void GameManager::MoveObjects(double tTime)
{
	if(this->ID > 0)
	{
		for(int i = 0; i < this->ID; i++)
		{
			UpdateVelocity(this->Objects[i], tTime);
			this->Objects[i]->UpdatePosition(tTime);
		}
	}
}

bool GameManager::DragObject(int nID)
{
	if(this->ID > nID)
	{
		this->Objects[nID]->SetVelocity(g_vNullVector2D);
		this->Objects[nID]->SetPosition(InputManager::Instance()->GetMousePosition()->x, InputManager::Instance()->GetMousePosition()->y);
		return true;
	}

	return false;
}

