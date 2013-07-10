#pragma once

#include <iostream>
using namespace std;

#include <SDL.h>

class Timer
{
private:
	//The clock time when the timer m_bTimerStarted
	double m_tStartTicks;

	//The ticks stored when the timer was m_bTimerPaused
	double m_tPausedTicks;

	//The timer status
	bool m_bTimerPaused;
	bool m_bTimerStarted;

public:
	//Initializes variables
	Timer();
	~Timer() {}

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	double Getticks();

	//Checks the status of the timer
	bool IsTimerStarted();
	bool IsTimerPaused();
};