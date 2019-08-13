#include "GUI.hpp"
#include <iostream>
GUI::GUI()
{
	std::cout << "Constructor called for GUI :> (" << this << ")" << std::endl;
}

GUI::~GUI()
{
	std::cout << "Destructor called for GUI :> (" << this << ")" << std::endl;
}