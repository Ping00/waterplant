#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__
#include <thread>
#include "../Controller/valve.hpp"
#include "../../Hardware/Microproccesors/MCP3008/MCP3008.hpp"
class Controller
{
	private:
		//Has component been properly initialized
		bool			m_initialized;

		//Data models which the Controller watches over
		//Analog to Digital Converter
		MCP3008			m_mcp3008;

		//Valve controller mechanism
		Valve			m_valve;

		//The update rate of our controller
		int				m_tickrate;

		//Custom thread to handle status checking of waterplantation
		std::thread		m_thread;


	public:
		Controller();
		~Controller();

		//Initialize the controller and system threads
		bool init();

		//Activate t
		void run();
		void check();

		int		get_tickrate();
		void	set_tickrate_milliseconds(int ms);

		//----
		bool	get_controller_initlialized();
		bool	get_valve_initialized();
};
#endif // !__CONTROLLER_HPP__
