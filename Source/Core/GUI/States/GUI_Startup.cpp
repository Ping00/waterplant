#include "GUI_Startup.hpp"
#include <iostream>
GUI_Startup::GUI_Startup()
{
	std::cout << "Constructor called for GUI_Startup :> (" << this << ")" << std::endl;
}

GUI_Startup::~GUI_Startup()
{
	std::cout << "Destructor called for GUI_Startup :> (" << this << ")" << std::endl;
}

void GUI_Startup::handle()
{
}

void GUI_Startup::update()
{
}

void GUI_Startup::render()
{
	std::cout << "GUI_Startup (Render)" << std::endl;
}
