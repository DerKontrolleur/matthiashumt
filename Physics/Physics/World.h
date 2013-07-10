#pragma once

#include "Globals.h"
#include "RessourceManager.h"

class World
{
private:
	Vector2D * m_pvSize;
	Vector2D * m_pvVelocity;
	double m_dWeight;
	double m_k;

public:
	World(Vector2D * vSize, Materials Material) : m_dWeight(999999999999999.9)
	{
		m_pvSize = new Vector2D(vSize->x, vSize->y); 
		m_pvVelocity = new Vector2D(g_vNullVector2D);

		switch(Material)
		{
		case glass:
			m_k = 0.94;
			break;
		case steel:
			m_k = 0.7;
			break;
		case wood:
			m_k = 0.5;
			break;
		case plastic:
			m_k = 0.1;
			break;
		}

		cout << "Constructor World called" << endl;
	}

	World(double dWidth, double dHeight, Materials Material) : m_dWeight(999999999999999.9)
	{
		m_pvSize = new Vector2D(dWidth, dHeight);
		m_pvVelocity = new Vector2D(g_vNullVector2D); 

		switch(Material)
		{
		case glass:
			m_k = 0.94;
			break;
		case steel:
			m_k = 0.7;
			break;
		case wood:
			m_k = 0.5;
			break;
		case plastic:
			m_k = 0.1;
			break;
		}
		
		cout << "Constructor World called" << endl;
	}

	~World() {delete m_pvSize; delete m_pvVelocity; cout << "Destructor World called" << endl;}

	void Render();

	void SetSize(Vector2D * vSize) {this->m_pvSize->Set(vSize);}
	void SetSize(Vector2D vSize) {this->m_pvSize->Set(vSize);}
	void SetSize(double dWidth, double dHeight) {this->m_pvSize->Set(dWidth, dHeight);}

	void SetVelocity(double dVelocityX, double dVelocityY) {this->m_pvVelocity->Set(dVelocityX, dVelocityY);}
	void SetVelocity(Vector2D v) {this->m_pvVelocity->Set(v);}
	void SetVelocity(Vector2D * v) {this->m_pvVelocity->Set(v);}

	void SetMaterial(Materials Material) 
	{
		switch(Material)
		{
		case glass:
			m_k = 0.94;
			break;
		case steel:
			m_k = 0.7;
			break;
		case wood:
			m_k = 0.5;
			break;
		case plastic:
			m_k = 0.1;
			break;
		}
	}

	double GetWeight() const {return this->m_dWeight;}
	Vector2D * GetSize() {return this->m_pvSize;}
	Vector2D * GetVelocity() {return this->m_pvVelocity;}
	double GetK() const {return this->m_k;}
};