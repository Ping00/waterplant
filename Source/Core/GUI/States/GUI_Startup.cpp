#include "GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
GUI_Startup::GUI_Startup()
{
	std::cout << "Constructor called for GUI_Startup :> (" << this << ")" << std::endl;
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
	m_engine_online_status = "ENGINE : [ OK ]";
}

void GUI_Startup::render()
{
	move(1, 2);
	printw(m_engine_online_status.c_str());
}
