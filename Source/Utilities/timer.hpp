#ifndef __TIMER_HPP__
#define __TIMER_HPP__
#include <chrono>
class Timer
{
	private:
		std::chrono::high_resolution_clock::time_point m_start;
		
		int		m_time_limit;
		bool	m_active;
		

	public:
		Timer();
		~Timer();

		void set_timer_seconds(int time);
		void start_timer();
		void stop_timer();
		void reset_timer();
		bool check_time();
};
#endif // !__TIMER_HPP__
