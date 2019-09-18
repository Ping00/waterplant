#include "controller.hpp"
#include <iostream>
#include <chrono>
#include "../../Utilities/WATERPLANT_FILE.hpp"
#include "../../Utilities/FILE_DATA_POSITIONS.hpp"
Controller::Controller()
{
	std::cout << "Constructor called for Controller :> (" << this << ")" << std::endl;
	m_initialized = false;

}

Controller::~Controller()
{
	//Join the threads if the system properly started on shutdown
	if (m_initialized) 	
		m_thread.join();
}

bool Controller::init()
{
	//Get timestamp of initialization
	m_start = std::chrono::high_resolution_clock::now();

	//Load from settings
	set_tickrate_milliseconds(WATERPLANT_FILE::read("waterplant_settings.data", 0));

	//Initialize the Analog Digital Converter (MCP3008)
	m_mcp3008.init(0, 1000000);
	m_valve.init();

	//Start the thread to run valve control loop
	m_thread = std::thread(&Controller::run, this);

	m_initialized = true;
	return m_initialized;
}

void Controller::run()
{
	//TODO, change true to use engine on/off to see if system is active?
	while (true)
	{
		//Sleep thread until tickrate for check
		std::this_thread::sleep_for(std::chrono::milliseconds(m_tickrate));
		check();
	}
}

void Controller::check()
{
	//m_mcp3008.get_data(0);
	
	//STEPS
	//Turn on LED to indicate activity,
	//Check Sensors for data,
	//Examine if data allows for valve to be opened/closed
	//Open or Close valve
	//Turn of LED
}

int Controller::get_tickrate()
{
	return m_tickrate;
}

void Controller::set_tickrate_milliseconds(int tickrate_ms)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_tickrate);
	m_tickrate = tickrate_ms;
}

bool Controller::get_controller_initlialized()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_tickrate);
	return m_initialized;
}

bool Controller::get_valve_initialized()
{
	return m_valve.get_initialized();
}

bool Controller::get_mcp3008_initialized()
{
	return m_mcp3008.get_initialized();
}

bool Controller::get_valve_open_state()
{
	return m_valve.get_valve_state();
}

double Controller::get_mcp3008_reading(int channel)
{
	return m_mcp3008.get_data(channel);
}

bool Controller::get_mcp3008_channel_init_status(int channel)
{
	return m_mcp3008.get_channel_sensor_initialized(channel);
}

int Controller::get_mcp3008_channel_tickrate(int channel)
{
	return m_mcp3008.get_channel_sensor_tickrate(channel);
}

std::chrono::high_resolution_clock::time_point Controller::get_system_start()
{
	return m_start;
}
