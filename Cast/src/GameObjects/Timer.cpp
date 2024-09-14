#include "Timer.h"

#include <raylib.h>
#include <sstream>
#include <iomanip>

Timer::Timer() : StartTime(0.0f), PassedTime(0.0f), isActive(false) 
{ }

void Timer::Start() 
{
	this->StartTime = GetTime();
	this->isActive = true;
}

void Timer::Stop() 
{
	if(this->isActive)
	{
		this->PassedTime = GetTime() - this->StartTime;
		this->isActive = false;
	}
}

void Timer::Reset()
{
	this->StartTime = 0.0f;
	this->PassedTime = 0.0f;
	this->isActive = false;
}

bool Timer::IsActive() const
{
	return this->isActive;
}

float Timer::GetElapsedTime() const
{
	if (this->isActive)
		return GetTime() - this->StartTime;
	else
		return this->PassedTime;
}

std::string Timer::GetElapsedTimeString() const
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << GetElapsedTime();
	return oss.str();
}