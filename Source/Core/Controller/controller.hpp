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

		//Controller startup time
		std::chrono::high_resolution_clock::time_point m_start;

		//Our tickrate mutex
		std::shared_mutex		m_mutex_tickrate;

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
		void	set_tickrate_seconds(int sec);

		//----
		bool	get_controller_initlialized();
		bool	get_valve_initialized();
		bool	get_mcp3008_initialized();

		bool	get_valve_open_state();

		double	get_mcp3008_reading(int channel);
		bool	get_mcp3008_channel_init_status(int channel);
		int		get_mcp3008_channel_tickrate(int channel);

		int		get_valve_open_value();
		int		get_valve_close_value();

		void	set_valve_open_value(int value);
		void	set_valve_close_value(int value);

		void	set_mcp3008_channel_tickrate(int channel, int tickrate);

		std::chrono::high_resolution_clock::time_point get_system_start();
};
#endif // !__CONTROLLER_HPP__
