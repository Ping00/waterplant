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
};
#endif // !__VALVE_HPP__
