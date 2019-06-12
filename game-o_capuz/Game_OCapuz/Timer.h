#pragma once
#include "stdfx.h"
class Timer
{
private:
	bool _on;
	bool _paused;
	float _totalTime;
	float _currentTime;

	float *_deltaTime;

public:
	Timer(float *deltaTime, float totalTime = 0.0f);
	~Timer();

	bool isActive() const { return _on; }

	void set_totalTime(float totalTime) { _totalTime = totalTime; }
	float get_totalTime() const { return _totalTime; }

	float get_currentTime() const { return _currentTime; }

	void resetTimer();
	void reduceTime();
	void pause();
	void trigger();
	void reset_n_trigger()
	{
		resetTimer();
		trigger();
	}
};
