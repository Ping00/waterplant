#include "GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
GUI_Startup::GUI_Startup()
{
	std::cout << "Constructor called for GUI_Startup :> (" << this << ")" << std::endl;
	m_valve_status.set_message_max_length(10);
	m_valve_status.set_message_color(1);
	m_valve_status.set_position(2, 2);
	m_valve_status.set_message("TEST");
}

GUI_Startup::~GUI_Startup()
{
	//std::cout << "Destructor called for GUI_Startup :> (" << this << ")" << std::endl;
}

void GUI_Startup::handle()
{

}

void GUI_Startup::update()
{
	
}

void GUI_Startup::render()
{
	m_valve_status.render();
}
