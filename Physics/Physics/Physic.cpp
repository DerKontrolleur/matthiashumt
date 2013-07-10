#include "Physic.h"


void DetermineVelocity(Object * Object, double tTime)
{
	assert(Object);

	Object->SetVelocity
	(
		Object->GetVelocity()->x - (sgn(Object->GetVelocity()->x) * Object->GetAcceleration()->x * (tTime/1000.0f)),
		Object->GetVelocity()->y + Object->GetAcceleration()->y * (tTime/1000.0f)
	);
}

void DetermineAcceleration(Object * Object, double Fg, double FwX, double FwY)
{
	assert(Object);
	assert(Object->GetWeight() > 0.0);

	Object->GetAcceleration()->y = ((Fg - FwY) / Object->GetWeight());
	Object->GetAcceleration()->x = (FwX / Object->GetWeight());
}

void DetermineForce(Object * Object)
{
	assert(Object);

	double FwX = NULL;
	double FwY = NULL;

	if(Object->GetShape() == sphere)
	{
		FwY = (AirDensity * CwSphere * (2.0 * pi * pow(Object->GetRadius(), 2)) * pow(Object->GetVelocity()->y, 2)) / 2.0;
		FwX = (AirDensity * CwSphere * (2.0 * pi * pow(Object->GetRadius(), 2)) * pow(Object->GetVelocity()->x, 2)) / 2.0;
	}
	else
	{
		FwY = (AirDensity * CwCuboid * (Object->GetSize()->x * Object->GetSize()->y) * pow(Object->GetVelocity()->y, 2)) / 2.0;
		FwY = (AirDensity * CwCuboid * (Object->GetSize()->x * Object->GetSize()->y) * pow(Object->GetVelocity()->x, 2)) / 2.0;
	}

	double Fg = Object->GetWeight() * Gravity;

	DetermineAcceleration(Object, Fg, FwX, FwY);
}


void UpdateVelocity(Object * Object, double tTime)
{
	DetermineForce(Object);
	DetermineVelocity(Object, tTime);
}


void CheckCollision(int nID, Object * Objects[], World * GameWorld, double tTime)
{
	for(int j = 0; j < nID; j++)
	{
		if(Objects[j]->GetPosition()->x + Objects[j]->GetRadius() > GameWorld->GetSize()->x)
		{
			Objects[j]->GetPosition()->x = GameWorld->GetSize()->x - Objects[j]->GetRadius() - g_dSmall;
		}

		if(Objects[j]->GetPosition()->x - Objects[j]->GetRadius() < 0.0)
		{
			Objects[j]->GetPosition()->x = Objects[j]->GetRadius() + g_dSmall;
		}

		if(Objects[j]->GetPosition()->y + Objects[j]->GetRadius() > GameWorld->GetSize()->y)
		{
			Objects[j]->GetPosition()->y = GameWorld->GetSize()->y - Objects[j]->GetRadius() - g_dSmall;
		}

		if(Objects[j]->GetPosition()->y - Objects[j]->GetRadius() < 0.0)
		{
			Objects[j]->GetPosition()->y = Objects[j]->GetRadius() + g_dSmall;
		}


		if(Objects[j]->GetVelocity()->x >= 0.0)
		{
			if(Objects[j]->GetPosition()->x + Objects[j]->GetRadius() + Objects[j]->GetVelocity()->x * (tTime/1000.0f) >= GameWorld->GetSize()->x)
				Splice(Objects[j]->GetWeight(), GameWorld->GetWeight(), Objects[j]->GetVelocity()->x, GameWorld->GetVelocity()->x, Objects[j]->GetK(), GameWorld->GetK());
		}
		else
		{
			if(Objects[j]->GetPosition()->x - Objects[j]->GetRadius() + Objects[j]->GetVelocity()->x * (tTime/1000.0f) <= 0.0)
				Splice(Objects[j]->GetWeight(), GameWorld->GetWeight(), Objects[j]->GetVelocity()->x, GameWorld->GetVelocity()->x, Objects[j]->GetK(), GameWorld->GetK());
		}


		if(Objects[j]->GetVelocity()->y >= 0.0)
		{
			if(Objects[j]->GetPosition()->y + Objects[j]->GetRadius() + Objects[j]->GetVelocity()->y * (tTime/1000.0f) >= GameWorld->GetSize()->y)
				Splice(Objects[j]->GetWeight(), GameWorld->GetWeight(), Objects[j]->GetVelocity()->y, GameWorld->GetVelocity()->x, Objects[j]->GetK(), GameWorld->GetK());
		}
		else
		{
			if( Objects[j]->GetPosition()->y - Objects[j]->GetRadius() + Objects[j]->GetVelocity()->y * (tTime/1000.0f) <= 0.0)
				Splice(Objects[j]->GetWeight(), GameWorld->GetWeight(), Objects[j]->GetVelocity()->y, GameWorld->GetVelocity()->y, Objects[j]->GetK(), GameWorld->GetK());
		}

		GameWorld->SetVelocity(g_vNullVector2D);

		for(int i = j+1; i < nID; i++)
		{
			if(CollisionCourse(Objects[j], Objects[i]))
			{
				if(DetermineDistance(Objects[j], Objects[i], tTime) <= pow(Objects[j]->GetRadius() + Objects[i]->GetRadius() + g_dSmall, 2))
				{
					Vector2D DistanceX(g_vNullVector2D);
					Vector2D DistanceY(g_vNullVector2D);
					Matrix2X2 Transform(g_vNullVector2D, g_vNullVector2D);
					Vector2D Velocity1(g_vNullVector2D);
					Vector2D Velocity2(g_vNullVector2D);
					Vector2D Position1(g_vNullVector2D);
					Vector2D Position2(g_vNullVector2D);

					double Distance = (pow(Objects[j]->GetPosition()->x - Objects[i]->GetPosition()->x, 2) + pow(Objects[j]->GetPosition()->y - Objects[i]->GetPosition()->y, 2) - pow(Objects[j]->GetRadius() + Objects[i]->GetRadius(), 2));
	
					DistanceX.Set(Objects[j]->GetPosition()->Sub(Objects[i]->GetPosition()));
					DistanceX.Normalize();

					DistanceY.Set(DistanceX.y, -DistanceX.x);

					Transform.Set(DistanceX.x, DistanceX.y, -DistanceX.y, DistanceX.x);

					Position1.Set(Transform.Mult(Objects[j]->GetPosition()));
					Position2.Set(Transform.Mult(Objects[i]->GetPosition()));

					Velocity1.Set(Transform.Mult(Objects[j]->GetVelocity()));
					Velocity2.Set(Transform.Mult(Objects[i]->GetVelocity()));

					Transform.Inverse();


					/*if(Distance < 0.0)
					{
						Distance = sqrt(abs(Distance));

						Position1.x -= sgn(Position1.x) * (Distance/2);
						Position2.x -= sgn(Position2.x) * (Distance/2);

						Position1 = Transform.Mult(Position1);
						Position2 = Transform.Mult(Position2);

						Objects[j]->SetPosition(Position1);
						Objects[i]->SetPosition(Position2);
					}*/

					Splice(Objects[j]->GetWeight(), Objects[i]->GetWeight(), Velocity1.x, Velocity2.x, Objects[j]->GetK(), Objects[i]->GetK());

					Velocity1 = Transform.Mult(Velocity1);
					Velocity2 = Transform.Mult(Velocity2);

					Objects[j]->SetVelocity(Velocity1);
					Objects[i]->SetVelocity(Velocity2);
				}
			}
		}
	}
}


void Splice(const double weight1, const double weight2, double& v1, double& v2, const double k1, const double k2)
{
	assert(weight1 + weight2 > 0.0);

	double m_v1 = v1;

	v1 = (weight1 * v1 + weight2 * v2 - weight2 * (v1 - v2) * ((k1 + k2) / 2.0)) / (weight1 + weight2);
	v2 = (weight1 * m_v1 + weight2 * v2 - weight1 * (v2 - m_v1) * ((k1 + k2) / 2.0)) / (weight1 + weight2);
}


double DetermineDistance(Object * Object1, Object * Object2, double tTime)
{
	assert(Object1 && Object2);

	return (pow((Object1->GetPosition()->x + Object1->GetVelocity()->x * tTime/1000.0f) - (Object2->GetPosition()->x + Object2->GetVelocity()->x * tTime/1000.0f), 2) + pow((Object1->GetPosition()->y + Object1->GetVelocity()->y * tTime/1000.0f) - (Object2->GetPosition()->y + Object2->GetVelocity()->y * tTime/1000.0f), 2));
}


bool CollisionCourse(Object * Object1, Object * Object2)
{
	assert(Object1 && Object2);

	Vector2D v1;
	Vector2D v2;

	v1.Set(Object2->GetPosition()->Sub(Object1->GetPosition()));
	v2.Set(Object1->GetVelocity()->Sub(Object2->GetVelocity()));

	if(v1.DotProduct(v2) > 0.0)
		return true;

	return false;
}


Vector2D DetermineCollisionPoint(Object * Object1, Object * Object2)
{
	assert(Object1 && Object2);

	double CollisionPointX = 
		((Object1->GetPosition()->x * Object2->GetRadius()) + (Object1->GetPosition()->x* Object1->GetRadius() )) 
		/ (Object1->GetRadius() + Object2->GetRadius());

	double CollisionPointY = 
		((Object1->GetPosition()->y * Object2->GetRadius()) + (Object1->GetPosition()->y* Object1->GetRadius() )) 
		/ (Object1->GetRadius() + Object2->GetRadius());

	Vector2D CollisionPoint(CollisionPointX, CollisionPointY);

	return CollisionPoint;
}

double TimeToCollision(Object * Objects[], int nID)
{
	double A = 0.0;
	double B = 0.0;
	double C = 0.0;
	double D = 0.0;
	double t = 99999999.9;
	double DISC = 0.0;

	for(int j = 0; j < nID; j++)
	{
		for(int i = j+1; i < nID; i++)
		{
			if(CollisionCourse(Objects[j], Objects[i]))
			{
				A = pow(Objects[j]->GetVelocity()->x, 2) + pow(Objects[j]->GetVelocity()->y, 2) - 2 * Objects[j]->GetVelocity()->x * Objects[i]->GetVelocity()->x+ pow(Objects[i]->GetVelocity()->x, 2) - 2 * Objects[j]->GetVelocity()->y * Objects[i]->GetVelocity()->y + pow(Objects[i]->GetVelocity()->y, 2);
				B = -Objects[j]->GetPosition()->x * Objects[j]->GetVelocity()->x - Objects[j]->GetPosition()->y * Objects[j]->GetVelocity()->y + Objects[j]->GetVelocity()->x * Objects[i]->GetPosition()->x + Objects[j]->GetVelocity()->y * Objects[i]->GetPosition()->y + Objects[j]->GetPosition()->x * Objects[i]->GetVelocity()->x- 
					Objects[i]->GetPosition()->x * Objects[i]->GetVelocity()->x+ Objects[j]->GetPosition()->y * Objects[i]->GetVelocity()->y - Objects[i]->GetPosition()->y * Objects[i]->GetVelocity()->y;
				C = pow(Objects[j]->GetVelocity()->x, 2) + pow(Objects[j]->GetVelocity()->y, 2) - 2 * Objects[j]->GetVelocity()->x * Objects[i]->GetVelocity()->x+ pow(Objects[i]->GetVelocity()->x, 2) - 2 * Objects[j]->GetVelocity()->y * Objects[i]->GetVelocity()->y + pow(Objects[i]->GetVelocity()->y, 2);
				D = pow(Objects[j]->GetPosition()->x, 2) + pow(Objects[j]->GetPosition()->y, 2) - pow(Objects[j]->GetRadius(), 2) - 2 * Objects[j]->GetPosition()->x * Objects[i]->GetPosition()->x + pow(Objects[i]->GetPosition()->x, 2) - 2 * Objects[j]->GetPosition()->y * Objects[i]->GetPosition()->y + 
					pow(Objects[i]->GetPosition()->y, 2) - 2 * Objects[j]->GetRadius() * Objects[i]->GetRadius() - pow(Objects[i]->GetRadius(), 2);
				DISC = pow((-2 * B), 2) - 4 * C * D;

				if(DISC >= 0)
					t = min(min(t, 0.5 * (2 * B - sqrt (DISC)) / A), 0.5 * (2 * B + sqrt (DISC)) / A);
			}
		}
	}

	return t;
}
