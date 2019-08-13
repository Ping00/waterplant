#include "GUI.hpp"
#include "States/GUI_Overview.hpp"
#include "curses.h"
GUI::GUI()
{

}

GUI::~GUI()
{
	if (!m_initialized)
	{
		//Free memory if initialized properly
	}
}

bool GUI::init()
{
	//make unique
	m_initialized = true;
	return m_initialized;
}

void GUI::handle()
{

}

void GUI::update()
{

}

void GUI::render()
{
	
}
