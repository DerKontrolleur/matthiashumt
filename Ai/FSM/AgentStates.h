#pragma once

#include "State.h"
#include "Message.h"
#include <vector>

class Agent;

class Attack : public State<Agent>
{
private:
	Attack() {}

	Attack(const Attack&);
	Attack& operator=(const Attack&);

public:
	static Attack * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Retreat : public State<Agent>
{
private:
	Retreat() {}

	Retreat(const Retreat&);
	Retreat& operator=(const Retreat&);

public:
	static Retreat * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Patrol : public State<Agent>
{
private:
	Patrol() {}

	Patrol(const Patrol&);
	Patrol& operator=(const Patrol&);

public:
	static Patrol * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Gather : public State<Agent>
{
private:
	Gather() {}

	Gather(const Gather&);
	Gather& operator=(const Gather&);

public:
	static Gather * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Idle : public State<Agent>
{
private:
	Idle() {}

	Idle(const Idle&);
	Idle& operator=(const Idle&);

public:
	static Idle * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Flee : public State<Agent>
{
private:
	Flee() {}

	Flee(const Flee&);
	Flee& operator=(const Flee&);

public:
	static Flee * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Defend : public State<Agent>
{
private:
	Defend() {}

	Defend(const Defend&);
	Defend& operator=(const Defend&);

public:
	static Defend * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Follow : public State<Agent>
{
private:
	Follow() {}

	Follow(const Follow&);
	Follow& operator=(const Follow&);

public:
	static Follow * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};


class Search : public State<Agent>
{
private:
	Search() {}

	Search(const Search&);
	Search& operator=(const Search&);

public:
	static Search * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};

class Global : public State<Agent>
{
private:
	Global() {}

	Global(const Global&);
	Global& operator=(const Global&);

	vector<Agent*>::iterator it;

public:
	static Global * Instance();

	virtual void Enter(Agent* agent);
	virtual void Execute(Agent* agent);
	virtual void Exit(Agent* agent);

	virtual bool OnMessage(Agent* agent, const Message& msg);
};