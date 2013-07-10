#pragma once

#include <SDL.h>

#include <iostream>
using namespace std;

class Timer
{
private:
	//The clock time when the timer started
	Uint32 StartTicks;

	//The ticks stored when the timer was paused
	Uint32 PausedTicks;

	//The timer status
	bool TimerPaused;
	bool TimerStarted;

public:
	Timer::Timer()
	{
		//Initialize the variables
		StartTicks = 0;
		PausedTicks = 0;
		TimerPaused = false;
		TimerStarted = false;
	}

	void Timer::start()
	{
		//Start the timer
		TimerStarted = true;

		//Unpause the timer
		TimerPaused = false;

		//Get the current clock time
		StartTicks = SDL_GetTicks();
	}

	void Timer::stop()
	{
		//Stop the timer
		TimerStarted = false;

		//Unpause the timer
		TimerPaused = false;
	}

	void Timer::pause()
	{
		//If the timer is running and isn't already m_bTimerPaused
		if(TimerStarted == true && TimerPaused == false)
		{
			//Pause the timer
			TimerPaused = true;

			//Calculate the m_bTimerPaused ticks
			PausedTicks = SDL_GetTicks() - StartTicks;
		}
	}

	void Timer::unpause()
	{
		//If the timer is m_bTimerPaused
		if(TimerPaused == true)
		{
			//Unpause the timer
			TimerPaused = false;

			//Reset the starting ticks
			StartTicks = SDL_GetTicks() - PausedTicks;

			//Reset the m_bTimerPaused ticks
			PausedTicks = 0;
		}
	}

	Uint32 Timer::Getticks()
	{
		//If the timer is running
		if(TimerStarted == true)
		{
			//If the timer is m_bTimerPaused
			if(TimerPaused == true)
			{
				//Return the number of ticks when the timer was m_bTimerPaused
				return PausedTicks;
			}
			else
			{
				//Return the current time minus the start time
				return SDL_GetTicks() - StartTicks;
			}
		}

		//If the timer isn't running
		return 0;
	}

	bool Timer::IsTimerStarted()
	{
		return TimerStarted;
	}

	bool Timer::IsTimerPaused()
	{
		return TimerPaused;
	}


	inline Timer(const Timer& t)
	{
		this->StartTicks = t.StartTicks;
		this->PausedTicks = t.PausedTicks;
		this->TimerStarted = t.TimerStarted;
		this->TimerPaused = t.TimerPaused;
	}

	inline Timer& operator=(const Timer& t)
	{
		this->StartTicks = t.StartTicks;
		this->PausedTicks = t.PausedTicks;
		this->TimerStarted = t.TimerStarted;
		this->TimerPaused = t.TimerPaused;
	}
};