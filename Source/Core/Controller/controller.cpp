#include "controller.hpp"
#include <iostream>
#include <chrono>
Controller::Controller()
{
	std::cout << "Constructor called for Controller :> (" << this << ")" << std::endl;
	m_initialized = false;

	//Default tickrate (TODO, load from .settings file)
	m_tickrate = 100;
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
	m_tickrate = tickrate_ms;
}

bool Controller::get_controller_initlialized()
{
	return m_initialized;
}

bool Controller::get_valve_initialized()
{
	return m_valve.get_initialized();
}

std::chrono::high_resolution_clock::time_point Controller::get_system_start()
{
	return m_start;
}
