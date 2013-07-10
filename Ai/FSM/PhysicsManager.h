#pragma once

#include "Globals.h"
#include "Vector.h"
#include "EntityManager.h"

class PhysicsManager
{
private:
	vector<Agent*>::iterator it;

	PhysicsManager()
	{
		cout << "PhysicsManager constructed" << endl;
	}

public:
	~PhysicsManager()
	{
		cout << "PhysicsManager destroyed" << endl;
	}

	static PhysicsManager* Instance();


	void CheckCollision();
};
