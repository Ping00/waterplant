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
	return false;
}

double MCP3008::get_data(int channel)
{
	return m_tmp36.read();
}
