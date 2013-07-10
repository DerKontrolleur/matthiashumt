#pragma once

#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;


//Structs
struct Vector2D
{
	double x;
	double y;

	Vector2D() : x(NULL), y(NULL) {}
	Vector2D(double d) : x(d), y(d) {}
	Vector2D(double dX, double dY) : x(dX), y(dY) {}

	inline void Set(double dX, double dY) {this->x = dX; this->y = dY;}
	inline void Set(Vector2D * v) {this->x = v->x; this->y = v->y;}
	inline void Set(Vector2D v) {this->x = v.x; this->y = v.y;}


	inline double GetLength()
	{
		return sqrt(pow(this->x, 2) + pow(this->y, 2));
	}

	inline void Normalize()
	{
		this->Set(this->Mult(1/this->GetLength()));
	}

	inline double DotProduct(const Vector2D v)
	{
		return (this->x * v.x + this->y * v.y);
	}

	inline double DotProduct(const Vector2D * v)
	{
		return (this->x * v->x + this->y * v->y);
	}


	inline Vector2D Sub(const Vector2D v)
	{
		Vector2D result;

		result.Set(this->x - v.x, this->y - v.y);

		return result;
	}

	inline Vector2D Sub(const Vector2D * v)
	{
		Vector2D result;

		result.Set(this->x - v->x, this->y - v->y);

		return result;
	}

	inline Vector2D Add(const Vector2D v)
	{
		Vector2D result;

		result.Set(this->x + v.x, this->y + v.y);

		return result;
	}

	inline Vector2D Add(const Vector2D * v)
	{
		Vector2D result;

		result.Set(this->x + v->x, this->y + v->y);

		return result;
	}

	template <typename temp> 
	inline Vector2D Mult(const temp val)
	{
		Vector2D result;

		result.Set(this->x * val, this->y * val);

		return result;
	}

	inline Vector2D Mult(const Vector2D v)
	{
		Vector2D result;

		result.Set(this->x * v.x, this->y * v.y);

		return result;
	}

	inline Vector2D Mult(const Vector2D * v)
	{
		Vector2D result;

		result.Set(this->x * v->x, this->y * v->y);

		return result;
	}
};

struct Matrix2X2
{
	double A[2][2];

	Matrix2X2() {A[0][0] = NULL; A[0][1] = NULL; A[1][0] = NULL; A[1][1] = NULL;}
	Matrix2X2(double value) {A[0][0] = value; A[0][1] = value; A[1][0] = value; A[1][1] = value;}
	Matrix2X2(double a11, double a12, double a21, double a22) {A[0][0] = a11; A[0][1] = a12; A[1][0] = a21; A[1][1] = a22;}
	Matrix2X2(double B[2][2]) {A[0][0] = B[0][0]; A[0][1] = B[0][0]; A[1][0] = B[0][0]; A[1][1] = B[0][0];}
	Matrix2X2(double * B[2][2]) {A[0][0] = *B[0][0]; A[0][1] = *B[0][0]; A[1][0] = *B[0][0]; A[1][1] = *B[0][0];}
	Matrix2X2(Vector2D v1, Vector2D v2) {A[0][0] = v1.x; A[0][1] = v2.x; A[1][0] = v1.y; A[1][1] = v2.y;}
	Matrix2X2(Vector2D * v1, Vector2D * v2) {A[0][0] = v1->x; A[0][1] = v2->x; A[1][0] = v1->y; A[1][1] = v2->y;}

	inline void Set(double value) {A[0][0] = value; A[0][1] = value; A[1][0] = value; A[1][1] = value;}
	inline void Set(double a11, double a12, double a21, double a22) {A[0][0] = a11; A[0][1] = a12; A[1][0] = a21; A[1][1] = a22;}
	inline void Set(double B[2][2]) {A[0][0] = B[0][0]; A[0][1] = B[0][0]; A[1][0] = B[0][0]; A[1][1] = B[0][0];}
	inline void Set(double * B[2][2]) {A[0][0] = *B[0][0]; A[0][1] = *B[0][0]; A[1][0] = *B[0][0]; A[1][1] = *B[0][0];}
	inline void Set(Vector2D v1, Vector2D v2) {A[0][0] = v1.x; A[0][1] = v2.x; A[1][0] = v1.y; A[1][1] = v2.y;}
	inline void Set(Vector2D * v1, Vector2D * v2) {A[0][0] = v1->x; A[0][1] = v2->x; A[1][0] = v1->y; A[1][1] = v2->y;}
	inline void Set(Matrix2X2 B) {A[0][0] = B.A[0][0]; A[0][1] = B.A[0][1]; A[1][0] = B.A[1][0]; A[1][1] = B.A[1][1];}
	inline void Set(Matrix2X2 * B) {A[0][0] = B->A[0][0]; A[0][1] = B->A[0][1]; A[1][0] = B->A[1][0]; A[1][1] = B->A[1][1];}


	inline void Transpose()
	{
		Matrix2X2 temp;
		temp.Set(this);

		this->A[0][1] = this->A[1][0];
		this->A[1][0] = temp.A[0][1];
	}

	inline void Inverse()
	{
		Matrix2X2 temp;
		temp.Set(this);

		this->A[0][1] = this->A[1][0];
		this->A[1][0] = temp.A[0][1];

		this->Set(this->Mult((1/this->GetDeterminant())));
	}

	inline double GetDeterminant()
	{
		return this->A[0][0] * this->A[1][1] - this->A[0][1] * this->A[1][0];
	}


	template <typename temp>
	inline Matrix2X2 Mult(temp val)
	{
		Matrix2X2 result;

		result.Set(this->A[0][0] * val, this->A[0][1] * val, this->A[1][0] * val, this->A[1][1] * val);

		return result;
	}

	inline Vector2D Mult(Vector2D v)
	{
		Vector2D result;

		result.Set(this->A[0][0] * v.x + this->A[0][1] * v.y, this->A[1][0] * v.x + this->A[1][1] * v.y);

		return result;
	}

	inline Vector2D Mult(Vector2D * v)
	{
		Vector2D result;

		result.Set(this->A[0][0] * v->x + this->A[0][1] * v->y, this->A[1][0] * v->x + this->A[1][1] * v->y);

		return result;
	}

	inline Matrix2X2 Mult(Matrix2X2 B)
	{
		Matrix2X2 result;

		result.Set
		(
			this->A[0][0] * B.A[0][0] + this->A[0][1] * B.A[1][0],
			this->A[0][0] * B.A[0][1] + this->A[0][1] * B.A[1][1],
			this->A[1][0] * B.A[0][0] + this->A[1][1] * B.A[1][0],
			this->A[1][0] * B.A[0][1] + this->A[1][1] * B.A[1][1]
		);

		return result;
	}
};


//Functions
template <typename temp> 
int sgn(const temp val)
{
    return (temp(0) < val) - (val < temp(0));
}


//Enums
enum Materials
{
	none,
	glass,
	wood,
	steel,
	plastic
};

enum Shapes
{
	other,
	sphere,
	cuboid
};

enum Colors
{
	black,
	white,
	red,
	green,
	blue
};


//Physical constants
static const double PixelSize = 0.0002522799; //m/pixel
static const double PixelPerMeter = 3964.0; //pixel/m
static const double g_dSmall = 0.000000001;

static const double AirDensity = 1.184 * pow(PixelSize, 3); //kg/m^3 * m^3/pixel^3 = kg/pixel^3 
static const double Gravity = 9.80665 / PixelSize;

static const double CwCuboid = 1.15;
static const double CwSphere = 0.45;

static const double pi = 3.14159265359;

static const double GlassDensity = 2500.0 * pow(PixelSize, 3); //kg/m^3 * m^3/pixel^3 = kg/pixel^3 
static const double SteelDensity = 8000.0 * pow(PixelSize, 3); //kg/m^3 * m^3/pixel^3 = kg/pixel^3 
static const double OakDensity = 700.0 * pow(PixelSize, 3); //kg/m^3 * m^3/pixel^3 = kg/pixel^3 
static const double PlasticDensity = 1.45 * pow(PixelSize, 3); //kg/m^3 * m^3/pixel^3 = kg/pixel^3 


//Misc
static const Vector2D g_vNullVector2D(0.0, 0.0);
static const int g_MaxObjects = 1000;