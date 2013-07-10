#pragma once

#include "Globals.h"
#include "Scope.h"
#include "Agent.h"
#include <vector>

class EntityManager
{
private:
	int EntityID;

	vector<Agent*> Agents;
	vector<Agent*>::iterator it;

	Scope ProgramScope;

	EntityManager() : ProgramScope(0,0), EntityID(0)
	{
		cout << "EntityManager constructed" << endl;
	}

public:
	~EntityManager()
	{
		Agents.clear();

		cout << "EntityManager destroyed" << endl;
	}

	static EntityManager* Instance();


	void CreateAgent(double positionX, double positionY, AgentNames name, Colors color);
	void DeleteAgent(int ID);
	void CreateScope(int widht, int height);

	int GetEntityID() const {return this->EntityID;}

	Scope& GetScope() {return this->ProgramScope;}
	Agent* GetAgent(int ID) {return this->Agents.at(ID);}

	Agent* GetAgent(AgentNames name)
	{
		for(this->it = Agents.begin(); this->it != Agents.end(); this->it++)
		{
			if((*this->it)->GetName() == name)
				return *this->it;
		}
	}

	vector<Agent*>* GetAgents() {return &this->Agents;}
};