#include "valve.hpp"

Valve::Valve()
{
	m_initialized = false;
	m_valve_open = false;
}

Valve::~Valve()
{
}

bool Valve::init()
{
	m_initialized = true;
	return m_initialized;
}

bool Valve::get_initialized()
{
	return m_initialized;
}

bool Valve::get_valve_state()
{
	return m_valve_open;
}

void Valve::set_valve_state(bool state)
{
	m_valve_open = state;
}

void Valve::set_close_value(int value)
{
	m_close_threshold = value;
}

int Valve::get_close_value()
{
	//Mutex
	return m_close_threshold;
}

void Valve::set_open_value(int value)
{
	m_open_threshold = value;
}

int Valve::get_open_value()
{
	//Mutex
	return m_open_threshold;
}
