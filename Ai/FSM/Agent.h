#pragma once

#include "MovingEntity.h"
#include "StateMachine.h"
#include "AgentStates.h"
#include <unordered_map>

class Agent: public MovingEntity
{
private:
	unordered_map<int, const Vector2D<double>*> Memory;
	StateMachine<Agent> AI;
	Colors Color;
	AgentNames Name;
	int Strength;
	int Stamina;
	int Health;
	int Moral;
	int ViewDistance;
	int HearRadius;

public:
	Agent(): MovingEntity(0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0), Color(black), Name(Stranger), AI(this), Strength(0), Health(0), Moral(0), ViewDistance(0), HearRadius(0)
	{
		this->AI.SetCurrentState(Idle::Instance());
		this->AI.SetGlobalState(Global::Instance());
	}

	Agent(int ID, double positionX, double positionY, AgentNames name, Colors color): MovingEntity(ID, positionX, positionY, 0.0, 0.0, 0.0, 0, 0), Color(color), Name(name), AI(this)
	{
		switch(name)
		{
		case Samuel:
			this->SetSize(10, 100);
			this->SetMaxVelocity(100);

			this->Strength = 100;
			this->Stamina = 100;
			this->Health = 100;
			this->Moral = 100;
			this->ViewDistance = 100;
			this->HearRadius = 100;
			break;
		case Leonard:
			this->SetSize(10, 100);
			this->SetMaxVelocity(100);

			this->Strength = 100;
			this->Stamina = 100;
			this->Health = 100;
			this->Moral = 100;
			this->ViewDistance = 100;
			this->HearRadius = 100;
			break;
		case Lydia:
			this->SetSize(10, 100);
			this->SetMaxVelocity(100);

			this->Strength = 100;
			this->Stamina = 100;
			this->Health = 100;
			this->Moral = 100;
			this->ViewDistance = 100;
			this->HearRadius = 100;
			break;
		case Karl:
			this->SetSize(10, 100);
			this->SetMaxVelocity(100);

			this->Strength = 100;
			this->Stamina = 100;
			this->Health = 100;
			this->Moral = 100;
			this->ViewDistance = 100;
			this->HearRadius = 100;
			break;
		default:
			this->SetSize(10, 100);
			this->SetMaxVelocity(100);

			this->Strength = 100;
			this->Stamina = 100;
			this->Health = 100;
			this->Moral = 100;
			this->ViewDistance = 100;
			this->HearRadius = 100;
			break;
		}

		this->AI.SetCurrentState(Idle::Instance());
		this->AI.SetGlobalState(Global::Instance());

		cout << "Agent constructed" << endl;
	}

	virtual ~Agent()
	{
		this->Memory.clear();

		cout << "Agent destroyed" << endl;
	}


	void UpdateAI();
	void HandleMessage(const Message& msg);

	void Remember(int key, const Vector2D<double>& information);
	void Forget(int key);
	const Vector2D<double>& Tell(int key);

	void UpdatePosition(Uint32 time);
	void Render();

	void View() {}
	void Hear() {}

	void UpdatePerception() {}
	void UpdateCondition() {}

	inline const string GetStringName()
	{
		switch(this->Name)
		{
		case Samuel:
			return "Samuel";
		case Karl:
			return "Karl";
		case Leonard:
			return "Leonard";
		case Lydia:
			return "Lydia";
		default:
			return "Stranger";
		}
	}

	inline AgentNames GetName() {return this->Name;}

	void SetAI() {}
	StateMachine<Agent>* GetAI() {return &this->AI;}

	void SetHealth(int health) {this->Health = health;}
	int GetHealth() const {return this->Health;}

	void SetStrength(int strength) {this->Strength = strength;}
	int GetStrength() const {return this->Strength;}

	void SetStamina(int stamina) {this->Stamina = stamina;}
	int GetStamina() const {return this->Stamina;}

	void SetViewDistance(int view) {this->ViewDistance = view;}
	int GetViewDistance() const {return this->ViewDistance;}

	void SetHearRadius(int hear) {this->HearRadius = hear;}
	int GetHearRadius() const {return this->HearRadius;}

	void SetMoral(int moral) {this->Moral = moral;}
	int GetMoral() const {return this->Moral;}
};