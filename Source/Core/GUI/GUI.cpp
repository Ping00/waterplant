#include "GUI.hpp"
#include "States/GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
#include "GUI_COLORS.hpp"
GUI::GUI()
{
	std::cout << "Constructor called for GUI :> (" << this << ")" << std::endl;
}

GUI::~GUI()
{
	if (!m_initialized)
	{
		//Free memory if initialized properly
		endwin();
	}
}

bool GUI::init()
{
	//Create our state of our startup view
	
	initscr();
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);
	
	init_colors();

	m_gui = std::make_unique<GUI_Startup>();
	if (m_gui == nullptr) return false;


	m_initialized = true;
	return m_initialized;
}

void GUI::handle()
{
	if (m_gui != nullptr)
		m_gui.get()->handle();
}

void GUI::update()
{
	if (m_gui != nullptr)
		m_gui.get()->update();

}

void GUI::render()
{
	if (m_gui != nullptr)
		m_gui.get()->render();

	refresh();
}

void GUI::init_colors()
{
	start_color();

	//Set color combinations according to enum list
	init_pair(2, COLOR_WHITE, COLOR_BLUE);

	//Set default background color
	wbkgd(stdscr, COLOR_PAIR(2));
}