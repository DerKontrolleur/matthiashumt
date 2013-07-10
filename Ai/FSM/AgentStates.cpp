#include "AgentStates.h"
#include "UpdateManager.h"

Attack * Attack::Instance()
{
	static Attack instance;

	return &instance;
}

void Attack::Enter(Agent* agent)
{
	cout << agent->GetName() + " State: Attack" << endl;
}

void Attack::Execute(Agent* agent)
{
	
}

void Attack::Exit(Agent* agent)
{

}

bool Attack::OnMessage(Agent* agent, const Message& msg)
{
	return false;
}


Retreat * Retreat::Instance()
{
	static Retreat instance;

	return &instance;
}

void Retreat::Enter(Agent* agent)
{
	cout << agent->GetName() + " State: Retreat" << endl;
}

void Retreat::Execute(Agent* agent)
{
	
}

void Retreat::Exit(Agent* agent)
{

}

bool Retreat::OnMessage(Agent* agent, const Message& msg)
{
	return false;
}


Patrol * Patrol::Instance()
{
	static Patrol instance;

	return &instance;
}

void Patrol::Enter(Agent* agent)
{
	cout << agent->GetName() + " State: Patrol" << endl;
}

void Patrol::Execute(Agent* agent)
{

}

void Patrol::Exit(Agent* agent)
{

}

bool Patrol::OnMessage(Agent* agent, const Message& msg)
{
	return false;
}


Gather * Gather::Instance()
{
	static Gather instance;

	return &instance;
}

void Gather::Enter(Agent* agent)
{
	cout << agent->GetName() + " State: Gather" << endl;
}

void Gather::Execute(Agent* agent)
{
	
}

void Gather::Exit(Agent* agent)
{

}

bool Gather::OnMessage(Agent* agent, const Message& msg)
{
	return false;
}


Idle * Idle::Instance()
{
	static Idle instance;

	return &instance;
}

void Idle::Enter(Agent* agent)
{
	cout << agent->GetName() + " State: Idle" << endl;
}

void Idle::Execute(Agent* agent)
{
	
}

void Idle::Exit(Agent* agent)
{

}

bool Idle::OnMessage(Agent* agent, const Message& msg)
{
	return false;
}


Flee * Flee::Instance()
{
	static Flee instance;

	return &instance;
}

void Flee::Enter(Agent* agent)
{
	cout << agent->GetName() + " State: Flee" << endl;
}

void Flee::Execute(Agent* agent)
{
	
}

void Flee::Exit(Agent* agent)
{

}

bool Flee::OnMessage(Agent* agent, const Message& msg)
{
	return false;
}


Global * Global::Instance()
{
	static Global instance;

	return &instance;
}

void Global::Enter(Agent* agent)
{
	
}

void Global::Execute(Agent* agent)
{
	if(agent->GetDelay().Getticks() >= X1000)
	{
		for(this->it = EM->GetAgents()->begin(); this->it != EM->GetAgents()->end(); this->it++)
		{
			if(agent->GetID() != (*this->it)->GetID())
				MM->SendMessage(UM->GetTime(), agent->GetID(), (*this->it)->GetID(), msg_position, NULL);
		}
		agent->GetDelay().start();
	}
}

void Global::Exit(Agent* agent)
{

}

bool Global::OnMessage(Agent* agent, const Message& msg)
{
	switch(msg.Msg)
	{
	case msg_attack:
		if(!agent->GetAI()->GetState(*Attack::Instance()))
			agent->GetAI()->ChangeState(Attack::Instance());
		return true;
	case msg_patrol:
		if(!agent->GetAI()->GetState(*Patrol::Instance()))
			agent->GetAI()->ChangeState(Patrol::Instance());
		return true;
	case msg_retreat:
		if(!agent->GetAI()->GetState(*Retreat::Instance()))
			agent->GetAI()->ChangeState(Retreat::Instance());
		return true;
	case msg_idle:
		if(!agent->GetAI()->GetState(*Idle::Instance()))
			agent->GetAI()->ChangeState(Idle::Instance());
		return true;
	case msg_gather:
		if(!agent->GetAI()->GetState(*Gather::Instance()))
			agent->GetAI()->ChangeState(Gather::Instance());
		return true;
	case msg_flee:
		if(!agent->GetAI()->GetState(*Flee::Instance()))
			agent->GetAI()->ChangeState(Flee::Instance());
		return true;

	case msg_position:
		agent->Remember(msg.SenderID, agent->GetPosition());
		return true;
	default:
		return false;
	}
}