#include "GUI_Overview.hpp"
#include <iostream>
#include "../Enums/GUI_COLORS.hpp"
GUI_Overview::GUI_Overview()
{
	//std::cout << "Constructor called for GUI_Overview :> (" << this << ")" << std::endl;
	m_test.set_message_max_length(100);
	m_test.set_position(1, 20);

	m_splitting_line.set_message_max_length(70);
	m_splitting_line.set_message("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	m_splitting_line.set_position(2, 3);
	m_splitting_line.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_current_menu_title.set_message_max_length(20);
	m_current_menu_title.set_message("OVERVIEW");
	m_current_menu_title.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_current_menu_title.set_position(4, 5);

}

GUI_Overview::~GUI_Overview()
{
	//std::cout << "Destructor called for GUI_Overview :> (" << this << ")" << std::endl;
}

void GUI_Overview::handle(int input)
{
	if (input != -1)
	{
		m_horizontal_menu.handle(input);
		m_test.set_message(input);
	}
}

void GUI_Overview::update(std::stack<std::unique_ptr<GUI_BASE>>& stack)
{

}

void GUI_Overview::render()
{
	m_horizontal_menu.render();
	m_splitting_line.render();
	m_current_menu_title.render();
	m_test.render();
}
