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

bool Valve::get_valve_open_state()
{
	return m_valve_open;
}
