#ifndef __VALVE_HPP__
#define __VALVE_HPP__
class Valve
{
	private:
		bool	m_initialized;
		bool	m_valve_open;
		

	public:
		Valve();
		~Valve();

		bool init();
		bool get_initialized();
		bool get_valve_state();
		void set_valve_state(bool state);
};
#endif // !__VALVE_HPP__
