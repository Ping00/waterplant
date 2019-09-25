#include "GUI_Settings.hpp"
#include "GUI_Overview.hpp"
#include "../Enums/GUI_COLORS.hpp"
#include "../Enums/INPUT_KEYS.hpp"
#include "curses.h"
GUI_Settings::GUI_Settings()
{
	m_return = false;

	m_current_menu_title.set_message_max_length(20);
	m_current_menu_title.set_message("SETTINGS");
	m_current_menu_title.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_current_menu_title.set_position(4, 5);

	m_splitting_line.set_message_max_length(70);
	m_splitting_line.set_message("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	m_splitting_line.set_position(2, 3);
	m_splitting_line.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_horizontal_menu.set_highlight(2);
}

GUI_Settings::~GUI_Settings()
{

}

void GUI_Settings::handle(int input)
{
	m_vertical_menu.handle(input);
	if (input == INPUT_KEY_RETURN)
	{
		m_return = true;
	}
	else
	{
		m_return = false;
	}
}

void GUI_Settings::update(std::unique_ptr<GUI_BASE>& menu, Controller& controller)
{
	m_horizontal_menu.update();
	m_vertical_menu.update(controller);
	if (m_return && m_vertical_menu.get_setting_selected() == 0)
	{
		clear();
		std::unique_ptr<GUI_Overview> x = std::make_unique<GUI_Overview>();
		x.get()->set_highlight(2);
		menu = std::move(x);
	}
}

void GUI_Settings::render()
{
	m_current_menu_title.render();
	m_horizontal_menu.render();
	m_splitting_line.render();

	m_vertical_menu.render();
}
