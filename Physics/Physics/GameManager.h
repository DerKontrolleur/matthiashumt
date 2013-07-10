#pragma once

#include "Physic.h"
#include "InputManager.h"
#include "RessourceManager.h"
#include "Object.h"
#include "World.h"
#include "Quadtree.h"
#include "Globals.h"
#include "Timer.h"

class GameManager
{
private:
	int ID;

	int m_nFPSCounter;
	int FPS;
	Timer * FPSTime;

	Timer * DeltaTime;

	World * GameWorld;
	Timer * GameTime;

	Object * Objects[g_MaxObjects];
	QuadTree * RootTree;

	SDL_Event pSDLEvent;

	Colors TempColor;
	Materials TempMaterial;
	Shapes TempShape;


	GameManager() : DeltaTime(NULL), GameTime(NULL), FPSTime(NULL), GameWorld(NULL), RootTree(NULL), ID(0), m_nFPSCounter(0), TempColor(black), TempMaterial(steel), TempShape(sphere), FPS(1000)
	{
		this->FPSTime  = new Timer();  
		this->GameTime = new Timer();
		this->DeltaTime = new Timer();

		cout << "Constructor GameManager called" << endl;
	}

public:
	~GameManager() 
	{
		delete FPSTime;
		delete GameWorld;
		delete GameTime;
		delete DeltaTime;
		delete RootTree;
		for(int i = 0; i < this->ID; i++) {delete Objects[i];}
		//delete[] Objects;

		cout << "Destructor GameManager called" << endl;
	}

	static GameManager * Instance();


	void InitializeGame();

	void ManageInput();

	void UpdateFPS();

	void CreateObject(Materials Material, Shapes Shape, Colors Color);

	void DeleteObject(int nID);

	void RenderObjects();

	void MoveObjects(double tTime);

	bool DragObject(int nID);

	void ManageObjects();


	int GetID() const {return this->ID;}
	void SetID(int nID) {this->ID = nID;}

	Materials GetTempMaterial() const {return this->TempMaterial;}
	Shapes GetTempShape() const {return this->TempShape;}
	Colors GetTempColor() const {return this->TempColor;}

	void SetTempMaterial(Materials Material) {this->TempMaterial = Material;}
	void SetTempShape(Shapes Shape) {this->TempShape = Shape;}
	void SetTempColor(Colors Color) {this->TempColor = Color;}


	Timer * GetDeltaTime() const {return this->DeltaTime;}

	Timer * GetGameTime() const {return this->GameTime;}

	Object * GetObject(int nID) const
	{
		assert(nID < this->ID);
		return this->Objects[nID];
	}

	int RandomNumber()
	{
		if((rand() % 9) + 1 > 9)
			return 76 + (rand() % 24);
		else if((rand() % 9) + 1 > 7)
			return 26 + (rand() % 50);
		else
			return 3 + (rand() % 23);
	}
};