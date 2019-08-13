#include "GUI.hpp"
#include <iostream>
#include "curses.h"
GUI::GUI()
{
	std::cout << "Constructor called for GUI :> (" << this << ")" << std::endl;
}

GUI::~GUI()
{
	std::cout << "Destructor called for GUI :> (" << this << ")" << std::endl;
}

void GUI::init()
{
	std::cout << "INit" << std::endl;
	initscr();
}
