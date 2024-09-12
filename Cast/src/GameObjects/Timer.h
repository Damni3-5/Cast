#pragma once

#include <string>

class Timer
{
public:
	Timer();
	void Start();
	void Stop();
	void Reset();
	bool IsActive() const;
	float GetElapsedTime() const;
	std::string GetElapsedTimeString() const;

private:
	float StartTime;
	float PassedTime;
	bool isActive;
};