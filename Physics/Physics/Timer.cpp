#include "Timer.h"

Timer::Timer()
{
	//Initialize the variables
	m_tStartTicks = 0;
	m_tPausedTicks = 0;
	m_bTimerPaused = false;
	m_bTimerStarted = false;
}

void Timer::start()
{
	//Start the timer
	m_bTimerStarted = true;

	//Unpause the timer
	m_bTimerPaused = false;

	//Get the current clock time
	m_tStartTicks = SDL_GetTicks();
}

void Timer::stop()
{
	//Stop the timer
	m_bTimerStarted = false;

	//Unpause the timer
	m_bTimerPaused = false;
}

void Timer::pause()
{
	//If the timer is running and isn't already m_bTimerPaused
	if( ( m_bTimerStarted == true ) && ( m_bTimerPaused == false ) )
	{
		//Pause the timer
		m_bTimerPaused = true;

		//Calculate the m_bTimerPaused ticks
		m_tPausedTicks = SDL_GetTicks() - m_tStartTicks;
	}
}

void Timer::unpause()
{
	//If the timer is m_bTimerPaused
	if( m_bTimerPaused == true )
	{
		//Unpause the timer
		m_bTimerPaused = false;

		//Reset the starting ticks
		m_tStartTicks = SDL_GetTicks() - m_tPausedTicks;

		//Reset the m_bTimerPaused ticks
		m_tPausedTicks = 0;
	}
}

double Timer::Getticks()
{
	//If the timer is running
	if( m_bTimerStarted == true )
	{
		//If the timer is m_bTimerPaused
		if( m_bTimerPaused == true )
		{
			//Return the number of ticks when the timer was m_bTimerPaused
			return m_tPausedTicks;
		}
		else
		{
			//Return the current time minus the start time
			return SDL_GetTicks() - m_tStartTicks;
		}
	}

	//If the timer isn't running
	return 0;
}

bool Timer::IsTimerStarted()
{
	return m_bTimerStarted;
}

bool Timer::IsTimerPaused()
{
	return m_bTimerPaused;
}
