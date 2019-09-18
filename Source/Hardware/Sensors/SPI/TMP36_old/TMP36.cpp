#include "TMP36.hpp"
#include <iostream>
TMP36::TMP36()
{
	std::cout << "Constructor called for TMP36 :> (" << this << ")" << std::endl;
	m_initialized = false;
	m_tickrate = 100;

	m_data = 0;
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

bool TMP36::get_init()
{
	return m_initialized;
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

double TMP36::poll_sensor()
{
	//Get data here
	/*We would replace this with our Wiringpi implemntation*/
	double data_poll = 123.45;

	return data_poll;
}

void TMP36::run()
{
	while (true)
	{
		//Tickrate determines how often do we try to wake the thread and get data from sensor
		std::this_thread::sleep_for(std::chrono::milliseconds(m_tickrate));

		//Read the sensor data
		double result = poll_sensor();

		//Format it to proper format
		result = format(result);

		//Write it to our sensor data
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
