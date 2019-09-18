#ifndef __VALVE_HPP__
#define __VALVE_HPP__
#include <mutex>
#include <shared_mutex>
class Valve
{
	private:
		bool	m_initialized;

		bool	m_valve_open;
		int		m_close_threshold;
		int		m_open_threshold;

		//Mutex for sharing data for other sources so we dont corrupt it
		std::shared_mutex		m_mutex_lower_value;
		std::shared_mutex		m_mutex_upper_value;
		std::shared_mutex		m_mutex_valve_status;
		

	public:
		Valve();
		~Valve();

		bool init();
		bool get_initialized();
		bool get_valve_state();
		void set_valve_state(bool state);

		void set_close_value(int value);
		int get_close_value();

		void set_open_value(int value);
		int get_open_value();
};
#endif // !__VALVE_HPP__
