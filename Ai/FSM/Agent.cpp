#include "UpdateManager.h"

void Agent::UpdatePosition(Uint32 time)
{
	this->Position.Set(this->Position.X + this->Velocity.X * (time/ONE_SECOND), this->Position.Y + this->Velocity.Y * (time/ONE_SECOND));
}

void Agent::Render()
{
	RM->ApplyCuboid(this->Position, this->Size, this->Color, RessourceManager::Instance()->GetScreen());
}

void Agent::UpdateAI()
{
	this->AI.Update();
}

void Agent::HandleMessage(const Message& msg)
{
	if(!this->AI.HandleMessage(msg))
		cout << this->GetName() + ": Message could not be handled" << endl;
}

void Agent::Remember(int key, const Vector2D<double>& information)
{
	this->Memory.insert(make_pair(key, &information));
}

void Agent::Forget(int key)
{
	this->Memory.erase(key);
}

const Vector2D<double>& Agent::Tell(int key)
{
	if(this->Memory.at(key))
		return *this->Memory.at(key);
	else
	{
		return NullVector;
		cout << "No memory entry for this key" << endl;
	}
}