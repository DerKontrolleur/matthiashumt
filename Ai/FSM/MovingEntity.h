#pragma once

#include "RessourceManager.h"
#include "BaseGameEntity.h"

class MovingEntity: public BaseGameEntity
{
protected:
	Vector2D<double> Velocity;
	double MaxVelocity;

	MovingEntity(): Velocity(NULL), MaxVelocity(NULL){}

	MovingEntity(int ID, double positionX, double positionY, double velocityX, double velocityY, double velocityM, int sizeX, int sizeY): BaseGameEntity(ID, positionX, positionY, sizeX, sizeY), Velocity(velocityX, velocityY), MaxVelocity(velocityM)
	{
		cout << "MovingEntity constructed" << endl;
	}

public:
	virtual ~MovingEntity()
	{
		cout << "MovingEntity destroyed" << endl;
	}


	Vector2D<double>& GetVelocity() {return this->Velocity;}
	void SetVelocity(double velocityX, double velocityY) {this->Velocity.Set(velocityX, velocityY);}
	void SetVelocity(const Vector2D<double>& velocity) {this->Velocity = velocity;}
	void SetMaxVelocity(double velocityM) {this->MaxVelocity = velocityM;}


	virtual void UpdatePosition(Uint32 time) = 0;
	virtual void Render() = 0;
};