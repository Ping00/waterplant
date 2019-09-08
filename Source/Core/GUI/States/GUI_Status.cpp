#include "GUI_Status.hpp"
#include "../Enums/GUI_COLORS.hpp"
GUI_Status::GUI_Status()
{
	m_current_menu_title.set_message_max_length(20);
	m_current_menu_title.set_message("SETTINGS");
	m_current_menu_title.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_current_menu_title.set_position(4, 5);
}

GUI_Status::~GUI_Status()
{
}

void GUI_Status::handle(int input)
{

}

void GUI_Status::update(std::unique_ptr<GUI_BASE>& stack)
{

}

void GUI_Status::render()
{
	m_current_menu_title.render();
}
