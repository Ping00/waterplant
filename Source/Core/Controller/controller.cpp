#include "controller.hpp"
#include <iostream>
Controller::Controller()
{
	std::cout << "Constructor called for Controller :> (" << this << ")" << std::endl;
	m_initialized = false;
}

Controller::~Controller()
{
	//m_thread.join();
}

bool Controller::init()
{
	//Create thread
	m_mcp3008.init(0, 1000000);
	m_initialized = true;
	return false;
}

void Controller::run()
{

}

void Controller::update()
{

}
