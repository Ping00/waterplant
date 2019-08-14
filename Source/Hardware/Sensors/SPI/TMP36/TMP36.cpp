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
	if(m_initialized) 	m_thread.join();
}

bool TMP36::init(int channel)
{
	m_channel = channel;
	m_thread = std::thread(&TMP36::run, this);
	m_initialized = true;

	return m_initialized;
}

double TMP36::format(double data)
{
	//Converts our ADC results into the proper format to be read (Depending on device)
	double result = data * 12.2;
	return result;
}

double TMP36::poll_sensor()
{
	//Get data here
	double data_result = 123.45;
	return data_result;
}

void TMP36::run()
{
	while (true)
	{
		//Tickrate determines how often do we try to wake the thread and get data from sensor
		std::this_thread::sleep_for(std::chrono::milliseconds(m_tickrate));
		double result = poll_sensor();
		result = format(result);
		write(result);
	}
}

void TMP36::write(double data)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex);
	m_data = data;
}

double TMP36::read()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex);
	return m_data;
}
