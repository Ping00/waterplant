#include "TMP36.hpp"
#include <iostream>
#include "../../../Microproccesors/MCP3008/MCP3008.hpp"
TMP36::TMP36()
{
	std::cout << "Constructor called for TMP36 :> (" << this << ")" << std::endl;
	m_initialized = false;
	m_tickrate = 100;
}

TMP36::~TMP36()
{

}

bool TMP36::init(int channel, MCP3008* master)
{
	m_channel = channel;
	m_master = master;
	m_thread = std::thread(&TMP36::run, this);
	m_initialized = true;

	return m_initialized;
}

void TMP36::run()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		write();
	}
}

void TMP36::write()
{
	int num = rand();
	m_master->write(num);
}
