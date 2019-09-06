#include "timer.hpp"
#include <chrono>
Timer::Timer()
{
	std::chrono::high_resolution_clock::time_point start;
}

Timer::~Timer()
{

}

void Timer::set_timer_seconds(int time)
{
	m_time_limit = time;
}

void Timer::start_timer()
{
	m_active = true;
	m_start = std::chrono::high_resolution_clock::now();
}

void Timer::stop_timer()
{
	m_active = false;
}

void Timer::reset_timer()
{
	m_start = std::chrono::high_resolution_clock::now();
}

bool Timer::check_time()
{
	if (m_active)
	{
		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(now - m_start);

		if (time_span.count() >= m_time_limit)
		{
			return true;
		}
	}
	return false;
}
