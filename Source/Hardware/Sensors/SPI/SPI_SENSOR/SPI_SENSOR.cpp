#include "SPI_SENSOR.hpp"
#include <iostream>
SPI_SENSOR::SPI_SENSOR()
{
	std::cout << "Constructor called for SPI_SENSOR :> (" << this << ")" << std::endl;

	//Sensor defaults to off
	m_initialized = false;

	//Default if no file exists
	m_tickrate = 100;

	//Set initial data to 0
	m_data = -1;

}

SPI_SENSOR::~SPI_SENSOR()
{
	//If sensor has been initialized it means the polling thread is running
	if (m_initialized) 	m_thread.join();
}

bool SPI_SENSOR::init(int channel)
{
	m_channel = channel;
	load_settings("waterplant_settings.data");

	m_thread = std::thread(&SPI_SENSOR::run, this);
	m_initialized = true;

	return m_initialized;
}

bool SPI_SENSOR::get_init()
{
	return m_initialized;
}

int SPI_SENSOR::get_tickrate()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_tickrate);
	return m_tickrate;
}

void SPI_SENSOR::set_tickrate(int ms)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_tickrate);
	m_tickrate = ms;
}

double SPI_SENSOR::poll_sensor()
{
	//Get data here
	/*We would replace this with our Wiringpi implemntation*/
	//TODO USE M_CHANNEL TO USE PROPER MCP3008 channel
	
	//PI
	/*
	if(m_initialized)
    {
        unsigned char buffer[3] = {1};
        buffer[1] = (8 + 0) << 4;
        wiringPiSPIDataRW(m_channel, buffer, 3);
        return ( (buffer[1] & 3) << 8 ) + buffer[2];
    }
    else
    {
      	return -1.0;
    }
	*/
	return 123.45;
}

void SPI_SENSOR::run()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	while (true)
	{
		//Tickrate determines how often do we try to wake the thread and get data from sensor
		std::this_thread::sleep_for(std::chrono::milliseconds(m_tickrate));

		//Read the sensor data
		double result = poll_sensor();

		//Format it to proper format
		double format_result = format(result);

		//Write it to our sensor variable
		write(format_result);
	}
}

void SPI_SENSOR::write(double data)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_data);
	m_data = data;
}

double SPI_SENSOR::read()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_data);
	return m_data;
}
