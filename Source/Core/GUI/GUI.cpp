#include "GUI.hpp"
#include "States/GUI_Startup.hpp"
#include <iostream>
#include "curses.h"
#include "Enums/GUI_COLORS.hpp"
GUI::GUI()
{
	std::cout << "Constructor called for GUI :> (" << this << ")" << std::endl;
}

GUI::~GUI()
{
	if (m_initialized)
	{
		//Free memory if initialized properly
		endwin();
	}
}

bool GUI::init()
{
	//Create our state of our startup view
	
	//Init screen
	initscr();
	
	//make so no characters will be written if we type
	noecho();

	//Remove cursor (Blinking white part)
	curs_set(0);

	//Set nodelay (Allows for nonblocking async input)
	nodelay(stdscr, TRUE);
	
	//activate arrowkeys for input
	keypad(stdscr, TRUE);

	//Setup colors
	init_colors();

	//Create our view
	m_gui = std::make_unique<GUI_Startup>();
	if (m_gui == nullptr) return false;


	m_initialized = true;
	return m_initialized;
}

void GUI::handle()
{
	if (m_gui != nullptr)
		//Nullify all current input
		m_input = getch();
		if(m_input != ERR)
		m_gui.get()->handle(m_input);
}

void GUI::update(Controller& controller)
{
	if (m_gui != nullptr)
		m_gui.get()->update(m_gui, controller);

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
	init_pair(GUI_COLOR_WHITE_BLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair(GUI_COLOR_BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
	init_pair(GUI_COLOR_BLUE_WHITE, COLOR_BLUE, COLOR_WHITE);

	//Set default background color
	wbkgd(stdscr, COLOR_PAIR(GUI_COLOR_WHITE_BLUE));
}