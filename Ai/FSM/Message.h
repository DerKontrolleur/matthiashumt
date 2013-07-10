#pragma once

#include "Globals.h"

struct Message
{
	int SenderID;
	int ReceiverID;
	int Msg;

	double TimeSend;

	void * ExtraInfo;

	Message() : TimeSend(-1), SenderID(-1), ReceiverID(-1), Msg(-1), ExtraInfo(NULL) {}

	Message(Uint32 t, int s, int r, int m, void * info) : TimeSend(t), SenderID(s), ReceiverID(r), Msg(m), ExtraInfo(info) {}
	Message(double t, int s, int r, int m, void * info) : TimeSend(t), SenderID(s), ReceiverID(r), Msg(m), ExtraInfo(info) {}
};


inline bool operator==(const Message& t1, const Message& t2)
{
	return  (fabs(t1.TimeSend-t2.TimeSend) < SmallestDelay) &&
			(t1.SenderID == t2.SenderID) &&
			(t1.ReceiverID == t2.ReceiverID) &&
			(t1.Msg == t2.Msg);
}

inline bool operator<(const Message& t1, const Message& t2)
{
	if (t1 == t2)
	{
		return false;
	}

	else
	{
		return  (t1.TimeSend < t2.TimeSend);
	}
}

inline const string MsgToStr(int msg)
{
	switch (msg)
	{
	case msg_attack:

		return "Attack";

	case msg_patrol:

		return "Patrol";

	case msg_retreat:

		return "Retreat";

	case msg_flee:

		return "Flee";

	case msg_gather:

		return "Gather";

	case msg_idle:

		return "Idle";

	case msg_position:

		return "Position";

	default:

		return "Error!";
	}
}

inline ostream& operator<<(ostream& os, const Message& t)
{
	os << "Time: " << t.TimeSend << "  Sender: " << t.SenderID
		<< "   Receiver: " << t.ReceiverID << "   Msg: " << MsgToStr(t.Msg);

	return os;
}

/*template <typename temp>
auto DereferenceToType(temp p) -> decltype(static_cast<temp*>(p))
{
	auto var = static_cast<temp*>(p);
	return var;
}*/