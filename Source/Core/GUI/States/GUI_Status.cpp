#include "GUI_Status.hpp"
#include "../Enums/GUI_COLORS.hpp"
GUI_Status::GUI_Status()
{
	m_current_menu_title.set_message_max_length(20);
	m_current_menu_title.set_message("STATUS");
	m_current_menu_title.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_current_menu_title.set_position(4, 5);

	m_splitting_line.set_message_max_length(70);
	m_splitting_line.set_message("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	m_splitting_line.set_position(2, 3);
	m_splitting_line.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_horizontal_menu.set_highlight(0);
}

GUI_Status::~GUI_Status()
{
}

void GUI_Status::handle(int input)
{

}

void GUI_Status::update(std::unique_ptr<GUI_BASE>& stack)
{
	m_horizontal_menu.update();
}

void GUI_Status::render()
{
	m_current_menu_title.render();
	m_splitting_line.render();
	m_horizontal_menu.render();
}
