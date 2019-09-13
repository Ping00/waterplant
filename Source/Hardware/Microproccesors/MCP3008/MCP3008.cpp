#include "MCP3008.hpp"
#include <iostream>
MCP3008::MCP3008()
{
	std::cout << "Constructor called for MCP3008 :> (" << this << ")" << std::endl;
	m_initialized	= false;
	m_spi_active[8] = { false };
}

MCP3008::~MCP3008()
{

}

bool MCP3008::init(int channel, int clock)
{
	//Init all our sensors, give them
	m_tmp36.init(0);
	m_smsm.init(1);

	m_initialized = true;
	return m_initialized;
}

double MCP3008::get_data(int channel)
{
	switch (channel)
	{
		case 0:
			return m_tmp36.read();
			break;

		case 1:
			return m_smsm.read();
			break;

		default:
			return 0;
			break;
	}
	return 0;
}

bool MCP3008::get_initialized()
{
	return m_initialized;
}
