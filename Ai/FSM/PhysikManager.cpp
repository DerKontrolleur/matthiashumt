#include "PhysicsManager.h"

PhysicsManager * PhysicsManager::Instance()
{
	static PhysicsManager Instance;

	return &Instance;
}

void PhysicsManager::CheckCollision()
{
	if(EM->GetEntityID() > 1)
	{
		for(this->it = EM->GetAgents()->begin(); this->it != EM->GetAgents()->end(); this->it++)
		{
			Vector2D<int> Position(static_cast<int>((*this->it)->GetPosition().X), static_cast<int>((*this->it)->GetPosition().Y));

			Vector2D<int> Top(EM->GetScope().GetSize().X, 0);
			Vector2D<int> Left(0, EM->GetScope().GetSize().Y);
			Vector2D<int> Bottom(EM->GetScope().GetSize() - Left);
			Vector2D<int> Right(EM->GetScope().GetSize() - Top);

			
			Top.Normalize();
			

			Vector2D<int> Projection = (Position * Top);

			if((*this->it)->GetID() == 0)
				cout << Projection.GetSquareLength() << endl;
			

			if(Projection.GetSquareLength() <= 0)
			{
				(*this->it)->GetVelocity().X *= 0;
				(*this->it)->GetPosition().X = 1;
			}
		}
	}
}