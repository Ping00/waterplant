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

	std::vector<std::string> graphic;
	graphic.push_back("__          __   _                  _             _   ");
	graphic.push_back("\\\ \\\        / /  | |                | |           | |  ");
	graphic.push_back(" \\\ \\\  /\\\  / /_ _| |_ ___ _ __ _ __ | | __ _ _ __ | |_ ");
	graphic.push_back("  \\\ \\\/  \\\/ / _` | __/ _ \\\ '__| '_ \\\| |/ _` | '_ \\\| __|");
	graphic.push_back("   \\\  /\\\  / (_| | ||  __/ |  | |_) | | (_| | | | | |_ ");
	graphic.push_back("    \\\/  \\\/ \\\__,_|\\\__\\\___|_|  | .__/|_|\\\__,_|_| |_|\\\__|");
	graphic.push_back("                             | |                      ");
	graphic.push_back("                             |_|                      ");

	for (int i = 0; i < graphic.size(); i++)
	{
		Display_Component x;
		x.set_position(10, 10 + i);
		x.set_message_max_length(60);
		x.set_message(graphic[i]);
		m_titlecard.push_back(x);
	}

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
