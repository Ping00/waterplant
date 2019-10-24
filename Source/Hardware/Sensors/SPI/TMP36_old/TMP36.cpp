#include "TMP36.hpp"
#include <iostream>
#include "../../../../Utilities/WATERPLANT_FILE.hpp"
#include "../../../../Utilities/FILE_DATA_POSITIONS.hpp"
TMP36::TMP36()
{
	std::cout << "Constructor called for SPI_SENSOR :> (" << this << ")" << std::endl;

	//Sensor defaults to off
	m_initialized = false;

	//Default if no file exists
	m_tickrate = 100;

	//Set initial data to 0
	m_data = -1;

}

TMP36::~TMP36()
{
	//If sensor has been initialized it means the polling thread is running
	if (m_initialized) 	m_thread.join();
}

bool TMP36::init(int channel)
{
	m_channel = channel;
	load_settings("waterplant_settings.data");

	m_thread = std::thread(&TMP36::run, this);
	m_initialized = true;

	return m_initialized;
}

bool TMP36::get_init()
{
	return m_initialized;
}

int TMP36::get_tickrate()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_tickrate);
	return m_tickrate;
}

void TMP36::set_tickrate(int ms)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_tickrate);
	m_tickrate = ms;
}

double TMP36::poll_sensor()
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

void TMP36::run()
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

void TMP36::write(double data)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_data);
	m_data = data;
}

double TMP36::read()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_data);
	return m_data;
}

double TMP36::format(double data)
{
	//Converts our ADC results into the proper format to be read (Depending on device)

	//the current schematic uses a 3.3v pin for the voltage so it needs to be converted from
	//a range of 0-1023 to 0-3.3v
	double voltage = data * 3.3;
	voltage /= 1024.0;

	//Convert voltage to temperature
	double temperature = (voltage - 0.5) * 100.0;
	return temperature;
}

void TMP36::load_settings(std::string path)
{
	set_tickrate(WATERPLANT_FILE::read(path, FILE_DATA_TMP36_TICKRATE));
}