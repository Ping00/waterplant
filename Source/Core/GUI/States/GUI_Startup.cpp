#include "GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
#include "../States/GUI_BASE.hpp"
#include "../States/GUI_Overview.hpp"
#include "../Widgets/graphic.hpp"
#include "../Enums/GUI_COLORS.hpp"
GUI_Startup::GUI_Startup()
{
	//std::cout << "Constructor called for GUI_Startup :> (" << this << ")" << std::endl;
	//Could potentially read and build from .config file (TODO?)

	m_version.set_message_max_length(30);
	m_version.set_message("Waterplant v0.7a");
	m_version.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_version.set_position(2, 1);

	m_build.set_message_max_length(30);
	m_build.set_message("Build (0042)");
	m_build.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_build.set_position(2, 2);



	m_titlecard.set_position(24, 10);
	m_titlecard.set_color(GUI_COLOR_WHITE_BLUE);
	m_titlecard.load_graphic("titlecard.graphic");

	m_timer.set_timer_seconds(2);
	m_timer.start_timer();
}

GUI_Startup::~GUI_Startup()
{
	//std::cout << "Destructor called for GUI_Startup :> (" << this << ")" << std::endl;
}

void GUI_Startup::handle(int input)
{

}

void GUI_Startup::update(std::unique_ptr<GUI_BASE>& menu, Controller& controller)
{
	if (m_timer.check_time())
	{
		clear();
		menu = std::make_unique<GUI_Overview>();
	}
}

void GUI_Startup::render()
{
	m_version.render();
	m_build.render();
	m_titlecard.render();
}
