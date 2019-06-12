#include "Timer.h"
#include "Stage.h"


Timer::Timer(float* deltaTime, float totalTime)
{
	_totalTime = totalTime;
	_deltaTime = deltaTime;
	resetTimer();
}


Timer::~Timer()
{
}

void Timer::resetTimer()
{
	_currentTime = _totalTime;
	_paused = true;
	_on = false;
}


void Timer::reduceTime()
{
	if (!_paused || _on)
	{
		_currentTime -= *_deltaTime;
		{
			if (_currentTime < 0)
			{
				_on = false;
				_paused = true;
			}
		}
	}
}

void Timer::pause()
{
	if (_on)
		_paused = true;
}

void Timer::trigger()
{
	_paused = false;
	_on = true;
}