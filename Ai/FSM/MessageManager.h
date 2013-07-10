#pragma once

#include "Message.h"
#include "EntityManager.h"
#include "Globals.h"
#include "Timer.h"
#include <set>

class MessageManager
{
private:
	set<const Message*> MessageBox;
	Timer MessageClock;

	MessageManager()
	{
		this->MessageClock.start();

		cout << "MessageManager constructed" << endl;
	}

	const Message RecordMessage(double time, int SenderID, int ReceiverID, Messages msg, void * ExtraInfo);
	void SendDelayedMessages();

public:
	~MessageManager()
	{
		this->MessageBox.clear();

		cout << "MessageManager destructed" << endl;
	}


	static MessageManager* Instance();


	void SendMessage(double time, int SenderID, int ReceiverID, Messages msg, void * ExtraInfo);
	void RecordDelayedMessage(Uint32 delay, int SenderID, int ReceiverID, Messages msg, void * ExtraInfo);

	friend class UpdateManager;
};