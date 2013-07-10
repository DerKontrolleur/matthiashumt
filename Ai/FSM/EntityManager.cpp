#include "EntityManager.h"

EntityManager * EntityManager::Instance()
{
	static EntityManager Instance;

	return &Instance;
}


void EntityManager::CreateAgent(double positionX, double positionY, AgentNames name, Colors color)
{
		Agent* agent = new Agent(this->EntityID, positionX, positionY, name, color);
		this->Agents.push_back(agent);
		this->EntityID++;
}

void EntityManager::DeleteAgent(int ID)
{
	this->Agents.erase(this->Agents.begin() + ID);

	int temp = 0;
	for(this->it = Agents.begin(); this->it != Agents.end(); this->it++)
	{
		(*this->it)->SetID(temp);
		temp++;
	}

	this->EntityID = temp;
}

void EntityManager::CreateScope(int widht, int height)
{
	this->ProgramScope.SetSize(widht, height);
}