#pragma once

#include "Globals.h"
#include "RessourceManager.h"
#include "Vector.h"

class Scope
{
private:
	Vector2D<int> Size;

public:
	Scope() : Size(0, 0) {}

	Scope(int width, int height) : Size(width, height)
	{
		cout << "World constructed" << endl;
	}

	~Scope()
	{
		cout << "World destroyed" << endl;
	}

	Scope(const Scope& scope)
	{
		this->Size = scope.Size;
	}

	Scope& operator=(const Scope& scope)
	{
		this->Size = scope.Size;
	}


	void Render();

	void SetSize(const Vector2D<int>& size) {this->Size = size;}
	void SetSize(int width, int height) {this->Size.Set(width, height);}

	Vector2D<int>& GetSize() {return this->Size;}
};