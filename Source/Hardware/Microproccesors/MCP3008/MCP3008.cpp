#include "MCP3008.hpp"
#include <iostream>
MCP3008::MCP3008()
{
	std::cout << "Constructor called for MCP3008 :> (" << this << ")" << std::endl;
	m_initialized = false;
}

MCP3008::~MCP3008()
{

}

bool MCP3008::init(int channel, int clock)
{
	m_tmp36.init(0,this);
	return false;
}

int MCP3008::get_data()
{
	std::shared_lock<std::shared_mutex> lock(m_mutex);
	std::cout << "Getting data" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(4000));
	return m_data;
}

void MCP3008::write(int data)
{
	std::unique_lock<std::shared_mutex> lock(m_mutex);
	std::cout << "Writing data" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	m_data = data;
}

