#pragma once

#include "Globals.h"
#include "Vector.h"
#include "Matrix.h"
#include "Message.h"
#include "Timer.h"

class BaseGameEntity
{
protected:
	int ID;
	Vector2D<int> Size;
	Vector2D<double> Position;

	Timer Delay;

	BaseGameEntity(): ID(0), Size(NULL), Position(NULL) {}

	BaseGameEntity(int ID, double positionX, double positionY, int sizeX, int sizeY): ID(ID), Size(sizeX, sizeY), Position(positionX, positionY)
	{
		this->Delay.start();

		cout << "BaseGameEntity constructed" << endl;
	}

public:
	virtual ~BaseGameEntity()
	{
		cout << "BaseGameEntity destroyed" << endl;
	}


	int GetID() const {return this->ID;}
	void SetID(int ID) {this->ID = ID;}

	Vector2D<double>& GetPosition() {return this->Position;}
	void SetPosition(double positionX, double positionY) {this->Position.Set(positionX, positionY);}
	void SetPosition(const Vector2D<double>& position) {this->Position = position;}

	Vector2D<int>& GetSize() {return this->Size;}
	void SetSize(int width, int height) {this->Size.Set(width, height);}
	void SetSize(const Vector2D<int>& size) {this->Size = size;}

	Timer& GetDelay() {return this->Delay;}

	virtual void HandleMessage(const Message& msg) = 0;
};