#include "Object.h"

void Object::Render()
{
	RessourceManager::Instance()->ApplySurface(this->m_pvPosition->x, this->m_pvPosition->y, this->m_Shape, this->m_nRadius, this->m_Color, RessourceManager::Instance()->GetScreen());
}


void Object::UpdatePosition(double tTime)
{
	this->SetPosition(this->GetPosition()->x + this->GetVelocity()->x * (tTime/1000.0f), this->GetPosition()->y + this->GetVelocity()->y * (tTime/1000.0f));
}