#include "MCP3008.hpp"
#include <iostream>
MCP3008::MCP3008()
{
	std::cout << "Constructor called for Engine :> (" << this << ")" << std::endl;
	m_initialized = false;
}

MCP3008::~MCP3008()
{

}

bool MCP3008::init(int channel, int clock)
{
	return false;
}

int MCP3008::get_data()
{
	std::lock_guard<std::mutex> guard(m_mutex);
	return m_data;
}

void MCP3008::write(int data)
{
	std::lock_guard<std::mutex> guard(m_mutex);
	m_data = data;
}

