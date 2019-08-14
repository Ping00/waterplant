#include "controller.hpp"
#include <iostream>
Controller::Controller()
{
	std::cout << "Constructor called for Controller :> (" << this << ")" << std::endl;
	m_initialized = false;
	m_tickrate = 100;
}

Controller::~Controller()
{
	if (m_initialized) 	m_thread.join();
}

bool Controller::init()
{
	//Create thread
	m_mcp3008.init(0, 1000000);
	m_thread = std::thread(&Controller::run, this);
	m_initialized = true;
	return false;
}

void Controller::run()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		check();
	}
}

void Controller::check()
{
	m_mcp3008.get_data();
}
