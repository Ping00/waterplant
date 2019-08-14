#include "MCP3008.hpp"
#include <iostream>
MCP3008::MCP3008()
{
	std::cout << "Constructor called for MCP3008 :> (" << this << ")" << std::endl;
	m_initialized	= false;
	m_spi_data[8]	= { 0 };
	m_spi_active[8] = { false };
}

MCP3008::~MCP3008()
{

}

bool MCP3008::init(int channel, int clock)
{
	//Init all our sensors, give them
	m_tmp36.init(0,this);
	return false;
}

double MCP3008::get_data(int channel)
{
	//Shared lock as GUI and controller may want to access it at the same time (For View and System valve etc)
	std::shared_lock<std::shared_mutex> lock(m_mutex);
	return m_spi_data[channel];
}

void MCP3008::write(int channel, double data)
{
	//Although we cant have race conditions when writing since it's an array, we need to make sure we dont
	//write during a read (Potentially could be faster) TODO
	std::unique_lock<std::shared_mutex> lock(m_mutex);
	m_spi_data[channel] = data;
}

