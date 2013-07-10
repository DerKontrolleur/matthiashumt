#pragma once

#include "Globals.h"
#include "Timer.h"
#include "Object.h"
#include "World.h"

void UpdateVelocity(Object * Object1, double tTime);

void DetermineForce(Object * Object);
void DetermineVelocity(Object * Object, double tTime);
void DetermineAcceleration(Object * Object, double Fg, double FwX, double FwY);

void CheckCollision(int nID, Object * Objects[], World * GameWorld, double tTime);
void Splice(const double weight1, const double weight2, double& v1, double& v2, const double k1, const double k2);

double DetermineDistance(Object * Object1, Object * Object2, double tTime);
bool CollisionCourse(Object * Object1, Object * Object2);
Vector2D DetermineCollisionPoint(Object * Object1, Object * Object2);
double TimeToCollision(Object * Objects[], int nID);