#pragma once

#include "Message.h"

template <class EntityType>
class State
{
public:
	virtual ~State() {}

	virtual void Enter(EntityType*) = 0;

	virtual void Execute(EntityType*) = 0;

	virtual void Exit(EntityType*) = 0;

	//this executes if the agent receives a message from the 
	//message dispatcher
	virtual bool OnMessage(EntityType*, const Message&) = 0;
};