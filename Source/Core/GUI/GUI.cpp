#include "GUI.hpp"
#include "States/GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
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
	start_color();

	init_pair(1, COLOR_GREEN, COLOR_BLACK);


	m_gui = std::make_unique<GUI_Startup>();
	if (m_gui == nullptr) return false;



	m_initialized = true;
	return m_initialized;
}

void GUI::handle()
{
	m_gui.get()->handle();
}

void GUI::update()
{
	m_gui.get()->update();
}

void GUI::render()
{
	m_gui.get()->render();
	refresh();
}
