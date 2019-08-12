#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__
#include "../../Hardware/Microproccesors/MCP3008/MCP3008.hpp"
class Controller
{
	private:
		bool		m_initialized;
		MCP3008		m_mcp3008;

	public:
		Controller();
		~Controller();

		bool init();
};
#endif // !__CONTROLLER_HPP__
