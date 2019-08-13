#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__
#include <thread>
#include "../Controller/valve.hpp"
#include "../../Hardware/Microproccesors/MCP3008/MCP3008.hpp"
class Controller
{
	private:
		bool			m_initialized;
		std::thread		m_thread;

		MCP3008			m_mcp3008;
		Valve			m_valve;


	public:
		Controller();
		~Controller();

		bool init();

		void run();
		void update();
};
#endif // !__CONTROLLER_HPP__
