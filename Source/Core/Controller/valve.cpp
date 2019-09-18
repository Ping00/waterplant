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
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_valve_status);
	return m_valve_open;
}

void Valve::set_valve_state(bool state)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_valve_status);
	m_valve_open = state;
}

void Valve::set_close_value(int value)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_upper_value);
	m_close_threshold = value;
}

int Valve::get_close_value()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_upper_value);
	return m_close_threshold;
}

void Valve::set_open_value(int value)
{
	//Lock when writing to one user (This sensor)
	std::unique_lock<std::shared_mutex> writer_lock(m_mutex_lower_value);
	m_open_threshold = value;
}

int Valve::get_open_value()
{
	//No limit on readers with shared_lock
	std::shared_lock<std::shared_mutex> reader_lock(m_mutex_lower_value);
	return m_open_threshold;
}
