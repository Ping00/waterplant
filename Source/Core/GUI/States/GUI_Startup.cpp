#include "GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
#include "../States/GUI_BASE.hpp"
#include "../States/GUI_Overview.hpp"
#include "../Widgets/graphic.hpp"
GUI_Startup::GUI_Startup()
{
	//std::cout << "Constructor called for GUI_Startup :> (" << this << ")" << std::endl;
	//Could potentially read and build from .config file (TODO?)

	m_version.set_message_max_length(30);
	m_version.set_message("Waterplant v0.3");
	m_version.set_message_color(2);
	m_version.set_position(2, 1);

	m_build.set_message_max_length(30);
	m_build.set_message("Build (0012)");
	m_build.set_message_color(2);
	m_build.set_position(2, 2);

	/*
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
		x.set_position(30, 10 + i);
		x.set_message_max_length(60);
		x.set_message(graphic[i]);
		m_titlecard.push_back(x);
	}
	*/
}

GUI_Startup::~GUI_Startup()
{
	//std::cout << "Destructor called for GUI_Startup :> (" << this << ")" << std::endl;
}

void GUI_Startup::handle()
{
	//m_input = getch();
}

void GUI_Startup::update()
{

}

void GUI_Startup::render()
{
	m_version.render();
	m_build.render();
	m_titlecard.render();
}
