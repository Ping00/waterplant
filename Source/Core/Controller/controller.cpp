#include "controller.hpp"

Controller::Controller()
{
}

Controller::~Controller()
{
	//m_thread.join();
}

bool Controller::init()
{
	//Create thread
	m_initialized = true;
	return false;
}

void Controller::run()
{

}

void Controller::update()
{

}
