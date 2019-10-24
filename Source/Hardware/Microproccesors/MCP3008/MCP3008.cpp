#include "MCP3008.hpp"
#include <iostream>
//#include <wiringPi.h>
//#include <wiringPiSPI.h>
MCP3008::MCP3008()
{
	std::cout << "Constructor called for MCP3008 :> (" << this << ")" << std::endl;
	m_initialized	= false;
	m_file_descriptor = -1;
}

MCP3008::~MCP3008()
{

}

bool MCP3008::init(int channel, int clock)
{
	/*
	//PI
    //Start MCP3008 connection with wiringpi
    m_file_descriptor = wiringPiSPISetup(spi_channel, 1000000);
    if(m_file_descriptor < 0)
    {
        std::cout << "Failed to open SPI BUS" << std::endl;
        m_initialized = false;
        return m_initialized;
    }

    wiringPiSetup();
	*/

	//Init all our sensors,
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

bool MCP3008::get_channel_sensor_initialized(int channel)
{
	switch (channel)
	{
		case 0:
			return m_tmp36.get_init();
			break;

		case 1:
			return m_smsm.get_init();
			break;

		default:
			return false;
			break;
	}
}

int MCP3008::get_channel_sensor_tickrate(int channel)
{
	switch (channel)
	{
		case 0:
			return m_tmp36.get_tickrate();
			break;

		case 1:
			return m_smsm.get_tickrate();
			break;

		default:
			return 0;
			break;
	}
}

void MCP3008::set_channel_sensor_tickrate(int channel, int tickrate)
{
	switch (channel)
	{
		case 0:
			m_tmp36.set_tickrate(tickrate);
			break;

		case 1:
			m_smsm.set_tickrate(tickrate);
			break;

		default:
			break;
	}
	return;
}
