#pragma once

#include "RessourceManager.h"
#include "InputManager.h"
#include "Globals.h"
#include "Timer.h"


class Object
{
private:
	Vector2D * m_pvPosition;
	Vector2D * m_pvVelocity;
	Vector2D * m_pvAcceleration;
	Vector2D * m_pvSize;
	double m_nRadius;
	Shapes m_Shape;
	Materials m_Material;
	double m_dWeight;
	int m_ID;
	double m_k;
	Colors m_Color;

public:
	Object() : m_ID(0), m_Shape(other), m_Material(none), m_dWeight(0.0), m_nRadius(0.0), m_k(0.0), m_Color(black)
	{
		m_pvVelocity = new Vector2D(g_vNullVector2D); 
		m_pvAcceleration = new Vector2D(g_vNullVector2D);
		m_pvPosition = new Vector2D(g_vNullVector2D);
		m_pvSize = new Vector2D(g_vNullVector2D);

		cout << "Constructor Static Object: Initialize called" << endl;
	}
	Object(int nID) : m_ID(nID), m_Shape(other), m_Material(none), m_dWeight(0.0), m_nRadius(0.0), m_k(0.0), m_Color(black)
	{
		m_pvVelocity = new Vector2D(g_vNullVector2D); 
		m_pvAcceleration = new Vector2D(g_vNullVector2D);
		m_pvPosition = new Vector2D(g_vNullVector2D);
		m_pvSize = new Vector2D(g_vNullVector2D);

		cout << "Constructor Static Object: Default called" << endl;
	}

	Object(int nID, Shapes Shape, Vector2D vPosition, Vector2D vSize, Materials Material, Colors Color) : m_ID(nID), m_Shape(Shape), m_Material(Material), m_dWeight(999999999999999.9), m_nRadius(vSize.x), m_Color(Color)
	{ 
		m_pvVelocity = new Vector2D(g_vNullVector2D); 
		m_pvAcceleration = new Vector2D(g_vNullVector2D);
		m_pvPosition = new Vector2D(vPosition.x, vPosition.y);
		m_pvSize = new Vector2D(vSize.x, vSize.y);

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

		cout << "Constructor Static Object: Cuboid called" << endl;
	}

	Object(int nID, Shapes Shape, Vector2D vPosition, double dRadius, Materials Material, Colors Color) : m_ID(nID), m_Shape(Shape), m_Material(Material), m_dWeight(999999999999999.9), m_nRadius(dRadius), m_Color(Color)
	{ 
		m_pvVelocity = new Vector2D(g_vNullVector2D); 
		m_pvAcceleration = new Vector2D(g_vNullVector2D);
		m_pvPosition = new Vector2D(vPosition.x, vPosition.y);
		m_pvSize = new Vector2D(dRadius, dRadius);

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

		cout << "Constructor Static Object: Sphere called" << endl;
	}

	Object(int nID, Shapes Shape, Vector2D vPosition, Vector2D vVelocity, Vector2D vSize, Materials Material, Colors Color) : m_ID(nID), m_Shape(Shape), m_Material(Material), m_nRadius(vSize.x), m_Color(Color)
	{
		m_pvVelocity = new Vector2D(vVelocity.x, vVelocity.y); 
		m_pvAcceleration = new Vector2D(g_vNullVector2D);
		m_pvPosition = new Vector2D(vPosition.x, vPosition.y);
		m_pvSize = new Vector2D(vSize.x, vSize.y);

		switch(Material)
		{
		case glass:
			m_dWeight = GlassDensity * pow(vSize.x, 2) * vSize.y;
			m_k = 0.94;
			break;
		case steel:
			m_dWeight = SteelDensity * pow(vSize.x, 2) * vSize.y;
			m_k = 0.7;
			break;
		case wood:
			m_dWeight = OakDensity * pow(vSize.x, 2) * vSize.y;
			m_k = 0.5;
			break;
		case plastic:
			m_dWeight = PlasticDensity * pow(vSize.x, 2) * vSize.y;
			m_k = 0.1;
			break;
		}

		cout << "Constructor Object: Cuboid called" << endl;
	}

	Object(int nID, Shapes Shape, Vector2D vPosition, Vector2D vVelocity, double nRadius, Materials Material, Colors Color) : m_ID(nID), m_Shape(Shape), m_Material(Material), m_nRadius(nRadius), m_Color(Color)
	{
		m_pvVelocity = new Vector2D(vVelocity.x, vVelocity.y); 
		m_pvAcceleration = new Vector2D(g_vNullVector2D); 
		m_pvPosition = new Vector2D(vPosition.x, vPosition.y);
		m_pvSize = new Vector2D(nRadius, nRadius);

		switch(Material)
		{
		case glass:
			m_dWeight = GlassDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.94;
			break;
		case steel:
			m_dWeight = SteelDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.7;
			break;
		case wood:
			m_dWeight = OakDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.5;
			break;
		case plastic:
			m_dWeight = PlasticDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.1;
			break;
		}

		cout << "Constructor Object: Sphere called" << endl;
	}

	Object(int nID, Shapes Shape, double dPositionX, double dPositionY, double dVelocityX, double dVelocityY, double nRadius, Materials Material, Colors Color) : m_ID(nID), m_Shape(Shape), m_Material(Material), m_nRadius(nRadius), m_Color(Color)
	{
		m_pvVelocity = new Vector2D(dVelocityX, dVelocityY); 
		m_pvAcceleration = new Vector2D(g_vNullVector2D); 
		m_pvPosition = new Vector2D(dPositionX, dPositionY);
		m_pvSize = new Vector2D(nRadius, nRadius);

		switch(Material)
		{
		case glass:
			m_dWeight = GlassDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.94;
			break;
		case steel:
			m_dWeight = SteelDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.7;
			break;
		case wood:
			m_dWeight = OakDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.5;
			break;
		case plastic:
			m_dWeight = PlasticDensity * (4/3) * pi * pow(nRadius, 3);
			m_k = 0.1;
			break;
		}

		cout << "Constructor Object: Sphere called" << endl;
	}

	~Object()
	{
		delete m_pvPosition; 
		delete m_pvVelocity;
		delete m_pvAcceleration;
		delete m_pvSize;

		cout << "Destructor Object called" << endl;
	}


	Vector2D * GetVelocity() {return this->m_pvVelocity;}
	void SetVelocity(double dVelocityX, double dVelocityY) {this->m_pvVelocity->Set(dVelocityX, dVelocityY);}
	void SetVelocity(Vector2D v) {this->m_pvVelocity->Set(v);}
	void SetVelocity(Vector2D * v) {this->m_pvVelocity->Set(v);}

	Vector2D * GetAcceleration() {return this->m_pvAcceleration;}
	void SetAcceleration(double dAccelerationX, double dAccelerationY) {this->m_pvAcceleration->Set(dAccelerationX, dAccelerationY);}

	Vector2D * GetPosition() {return this->m_pvPosition;}
	void SetPosition(double dPositionX, double dPositionY) {this->m_pvPosition->Set(dPositionX, dPositionY);}
	void SetPosition(Vector2D p) {this->m_pvPosition->Set(p);}
	void SetPosition(Vector2D * p) {this->m_pvPosition->Set(p);}

	Vector2D * GetSize() {return this->m_pvSize;}
	void SetSize(int nWidth, int nHeight) {this->m_pvSize->Set(nWidth, nHeight);}

	double GetRadius() const {return this->m_nRadius;}
	void SetRadius(int nRadius) {this->m_nRadius = nRadius;}

	Shapes GetShape() const {return this->m_Shape;}
	void SetShape(Shapes Shape) {this->m_Shape = Shape;}

	Materials GetMaterial() const {return this->m_Material;}
	void SetMaterial(Materials Material) {this->m_Material = Material;}

	Colors GetColor() const {return this->m_Color;}
	void SetColor(Colors Color) {this->m_Color = Color;}

	double GetWeight() const {return this->m_dWeight;}
	void SetWeight(double Weight) {this->m_dWeight = Weight;}

	int GetID() const {return this->m_ID;}
	void SetID(int nID) {this->m_ID = nID;}

	double GetK() const {return this->m_k;}
	double SetK(double k) {this->m_k = k;}


	void Render();
	void UpdatePosition(double tTime);
};