#include "controller.hpp"
#include <iostream>
#include <chrono>
#include "../../Utilities/WATERPLANT_FILE.hpp"
#include "../../Utilities/FILE_DATA_POSITIONS.hpp"
#include <wiringPi.h>
#define GPIO_RED_LED 17
#define GPIO_YELLOW_LED 27
#define GPIO_GREEN_LED 22
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

	//Set Pinmodes for all pins

	//RED LED = ERROR IN SYSTEM
	pinMode(GPIO_RED_LED, OUTPUT);

	//YELLOW LED = CONTROLLER ACTIVE
	pinMode(GPIO_YELLOW_LED, OUTPUT);

	//GREEN LED = VALVE OPEN
	pinMode(GPIO_GREEN_LED, OUTPUT);


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
	//Turn on Operation LED to indicate activity,
	digitalWrite(GPIO_YELLOW_LED, HIGH);

	//Get current sensor values and related data
	int moisture_rating = (int)m_mcp3008.get_data(1);
	int value_to_open_valve = m_valve.get_open_value();
	int value_to_close_valve = m_valve.get_close_value();

	//Check if the value is below the threshold
	if (moisture_rating < value_to_open_valve)
	{
		//Turn on VALVE LED
		digitalWrite(GPIO_GREEN_LED, HIGH);

		//Open the valve
		m_valve.set_valve_state(true);

		//Loop while valve is open to see if it needs to be closed
		while (m_valve.get_valve_state() == true)
		{
			//Alternate Indicator (OFF/ON) To show that system is thinking while watering
			digitalWrite(GPIO_YELLOW_LED, LOW);

			//Sleep for periodic check
			std::this_thread::sleep_for(std::chrono::milliseconds(500));

			digitalWrite(GPIO_YELLOW_LED, HIGH);
			
			//Update our periodic values if they have been changed in settings
			moisture_rating = (int)m_mcp3008.get_data(1);
			value_to_open_valve = m_valve.get_open_value();
			value_to_close_valve = m_valve.get_close_value();

			if (moisture_rating >= value_to_close_valve)
			{
				m_valve.set_valve_state(false);
				//Turn off VALVE LED
				digitalWrite(GPIO_GREEN_LED, LOW);

			}
		}
	}

	//Turn off Operations Led
	digitalWrite(GPIO_YELLOW_LED, LOW);
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
