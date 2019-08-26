#include "GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
GUI_Startup::GUI_Startup()
{
	std::cout << "Constructor called for GUI_Startup :> (" << this << ")" << std::endl;

	m_version.set_message_max_length(30);
	m_version.set_message("Waterplant v0.2");
	m_version.set_message_color(2);
	m_version.set_position(2, 1);



/*
 __          __   _                  _             _   
 \ \        / /  | |                | |           | |  
  \ \  /\  / /_ _| |_ ___ _ __ _ __ | | __ _ _ __ | |_ 
   \ \/  \/ / _` | __/ _ \ '__| '_ \| |/ _` | '_ \| __|
    \  /\  / (_| | ||  __/ |  | |_) | | (_| | | | | |_ 
     \/  \/ \__,_|\__\___|_|  | .__/|_|\__,_|_| |_|\__|
                              | |                      
                              |_|                      

							  */
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
	m_version.render();
	for (int i = 0; i < m_titlecard.size(); i++)
	{
		m_titlecard[i].render();
	}
}
