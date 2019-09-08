#include "GUI_Status.hpp"
#include "../Enums/GUI_COLORS.hpp"
#include "../Enums/INPUT_KEYS.hpp"
#include "GUI_Overview.hpp"
#include "curses.h"
GUI_Status::GUI_Status()
{
	m_return = false;

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
	if (input == INPUT_KEY_RETURN)
	{
		m_return = true;
	}
	else
	{
		m_return = false;
	}
}

void GUI_Status::update(std::unique_ptr<GUI_BASE>& menu)
{
	m_horizontal_menu.update();
	if (m_return)
	{
		clear();
		std::unique_ptr<GUI_Overview> x = std::make_unique<GUI_Overview>();
		x.get()->set_highlight(0);
		menu = std::move(x);
	}
}

void GUI_Status::render()
{
	m_current_menu_title.render();
	m_splitting_line.render();
	m_horizontal_menu.render();
}
