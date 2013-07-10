#pragma once

#include "Globals.h"
#include "State.h"
#include "Message.h"

template <class EntityType>
class StateMachine
{
private:
	//a pointer to the agent that owns this instance
	EntityType* Owner;

	State<EntityType>* CurrentState;

	//a record of the last state the agent was in
	State<EntityType>* PreviousState;

	//this is called every time the FSM is updated
	State<EntityType>* GlobalState;

public:
	StateMachine() : Owner(NULL), CurrentState(NULL), PreviousState(NULL), GlobalState(NULL) {}

	StateMachine(EntityType* owner) : Owner(owner), CurrentState(NULL), PreviousState(NULL), GlobalState(NULL)
	{
		cout << "StateMachine constructed" << endl;
	}

	~StateMachine()
	{
		cout << "StateMachine destroyed" << endl;
	}


	//use these methods to initialize the FSM
	void SetCurrentState(State<EntityType>* state) {this->CurrentState = state;}
	void SetGlobalState(State<EntityType>* state) {this->GlobalState = state;}
	void SetPreviousState(State<EntityType>* state) {this->PreviousState = state;}

	//use these methods to access the states
	State<EntityType>* GetCurrentState() const {return this->CurrentState;}
	State<EntityType>* GetGlobalState() const {return this->GlobalState;}
	State<EntityType>* GetPreviousState() const {return this->PreviousState;}

	//call this to update the FSM
	void Update() const
	{
		//if a global state exists, call its execute method, else do nothing
		if(GlobalState)  
			GlobalState->Execute(Owner);

		//same for the current state
		if(CurrentState) 
			CurrentState->Execute(Owner);
	}

	bool HandleMessage(const Message& msg) const
	{
		//first see if the current state is valid and that it can handle
		//the message
		if(CurrentState && CurrentState->OnMessage(Owner, msg)) {return true;}

		//if not, and if a global state has been implemented, send 
		//the message to the global state
		if(GlobalState && GlobalState->OnMessage(Owner, msg)) {return true;}

		return false;
	}

	//change to a new state
	void ChangeState(State<EntityType>* NewState)
	{
		//see if new state is valid
		assert(NewState && "<StateMachine::ChangeState>: trying to change to NULL state");

		//keep a record of the previous state
		PreviousState = CurrentState;

		//call the exit method of the existing state
		CurrentState->Exit(Owner);

		//change state to the new state
		CurrentState = NewState;

		//call the entry method of the new state
		CurrentState->Enter(Owner);
	}

	//change state back to the previous state
	void RevertToPreviousState() {ChangeState(PreviousState);}

	//returns true if the current state's type is equal to the type of the
	//class passed as a parameter. 
	bool GetState(const State<EntityType>& state) const {return typeid(*CurrentState) == typeid(state);}

	inline StateMachine(const StateMachine&) {}
	inline StateMachine& operator=(const StateMachine&) {}
};


