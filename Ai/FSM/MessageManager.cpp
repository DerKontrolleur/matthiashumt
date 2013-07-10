#include "MessageManager.h"

MessageManager * MessageManager::Instance()
{
	static MessageManager Instance;

	return &Instance;
}

void MessageManager::SendMessage(double time, int SenderID, int ReceiverID, Messages msg, void * ExtraInfo)
{
	const Message Msg = RecordMessage(time, SenderID, ReceiverID, msg, ExtraInfo);
	if(Msg.ReceiverID != -1)
		EM->GetAgent(ReceiverID)->HandleMessage(Msg);
}

void MessageManager::SendDelayedMessages()
{
	while(!this->MessageBox.empty() && ((*this->MessageBox.begin())->TimeSend > 0) && ((*this->MessageBox.begin())->TimeSend < this->MessageClock.Getticks()))
	{
		const Message Msg = *(*this->MessageBox.begin());

		EM->GetAgent(Msg.ReceiverID)->HandleMessage(Msg);

		MessageBox.erase(MessageBox.begin());
	}
}

void MessageManager::RecordDelayedMessage(Uint32 delay, int SenderID, int ReceiverID, Messages msg, void * ExtraInfo)
{
	if(ReceiverID < EM->GetEntityID() && ReceiverID != SenderID)
	{
		if(delay >= 0)
		{
			const Message* Msg = new Message(this->MessageClock.Getticks() + delay, SenderID, ReceiverID, msg, ExtraInfo);
			this->MessageBox.insert(Msg);
		}
	}
	else
		cout << "Invalid receiver" << endl;
}

const Message MessageManager::RecordMessage(double time, int SenderID, int ReceiverID, Messages msg, void * ExtraInfo)
{
	if(ReceiverID < EM->GetEntityID() && ReceiverID != SenderID)
	{
		const Message Msg(time, SenderID, ReceiverID, msg, ExtraInfo);
		return Msg;
	}
	else
	{
		const Message Msg(time, SenderID, -1, msg, ExtraInfo);
		cout << "Invalid receiver" << endl;
		return Msg;
	}
}