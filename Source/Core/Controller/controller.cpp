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
	set_tickrate_seconds(WATERPLANT_FILE::read("waterplant_settings.data", FILE_DATA_CONTROLLER_TICKRATE));

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
		std::this_thread::sleep_for(std::chrono::seconds(m_tickrate));
		check();
	}
}

void Controller::check()
{
	//STEPS
	//Turn on Operation LED to indicate activity,


	//Get current sensor values and related data
	int moisture_rating = (int)m_mcp3008.get_data(1);
	int valve_open = m_valve.get_open_value();
	int valve_close = m_valve.get_close_value();

	//Open the valve if value is below the open threshold
	if (moisture_rating < valve_open)
	{
		m_valve.set_valve_state(true);
	}

	//While the valve is opened, keep checking if water level OK
	while(m_valve.get_valve_state())
    {
        moisture_rating = (int)m_mcp3008.get_data(1);
        if(moisture_rating >= valve_close)
        {
            m_valve.set_valve_state(false);
        }

        std::this_thread::sleep_for(std::chrono::millliseconds(500));
    }

	/*
	//If the value is less, we open the valve
	if (moisture_rating <= valve_open)
	{
		//Power the Node which gives power to solenoid
		m_valve.set_valve_state(true);
	}
	//If it is greater we close it
	else if (moisture_rating > valve_close)
	{
		//Close the node which gives power to solenoid
		m_valve.set_valve_state(false);
	}
	*/

	//Turn of Operation LED
}

int Controller::get_tickrate()
{
	return m_tickrate;
}

void Controller::set_tickrate_seconds(int tickrate_sec)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_tickrate);
	m_tickrate = tickrate_sec;
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

int Controller::get_valve_open_value()
{
	return m_valve.get_open_value();
}

int Controller::get_valve_close_value()
{
	return m_valve.get_close_value();
}

void Controller::set_valve_open_value(int value)
{
	m_valve.set_open_value(value);
}

void Controller::set_valve_close_value(int value)
{
	m_valve.set_close_value(value);
}

void Controller::set_mcp3008_channel_tickrate(int channel, int tickrate)
{
	m_mcp3008.set_channel_sensor_tickrate(channel, tickrate);
}

std::chrono::high_resolution_clock::time_point Controller::get_system_start()
{
	return m_start;
}
