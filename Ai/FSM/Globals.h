#pragma once

#include <string>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <SDL.h>
using namespace std;


//Definitions
#define EM EntityManager::Instance()
#define IM InputManager::Instance()
#define MM MessageManager::Instance()
#define UM UpdateManager::Instance()
#define RM RessourceManager::Instance()
#define PM PhysicsManager::Instance()

//Enums
enum Colors
{
	black,
	white,
	red,
	green,
	blue
};

enum PictureNames
{
	pct_background
};

enum Messages
{
	msg_attack,
	msg_patrol,
	msg_retreat,
	msg_gather,
	msg_flee,
	msg_idle,

	msg_position
};

enum AgentNames
{
	Stranger,
	Samuel,
	Karl,
	Leonard,
	Lydia
};

//Functions
template <typename temp> 
inline int sgn(const temp val)
{
    return (temp(0) < val) - (val < temp(0));
}

//Constants
static const int MAX = 10;
static const double ONE_SECOND = 1000.0;
static const int X100 = 10;
static const int X1000 = 1;
static const int X10 = 100;
static const double SmallestDelay = 0.01;
static const int NO_MESSAGE = -1;

static const double pi = 3.14159265359;