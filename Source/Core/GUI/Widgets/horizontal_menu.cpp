#include "horizontal_menu.hpp"
#include "../Enums/INPUT_KEYS.hpp"
#include "../Enums/GUI_COLORS.hpp"
Horizontal_Menu::Horizontal_Menu()
{
	m_menu_selection = 0;

	m_option_status.set_message_max_length(20);
	m_option_status.set_message("STATUS");
	m_option_status.set_position(4, 1);
	m_option_status.set_message_color(GUI_COLOR_WHITE_BLUE);

	
	m_option_statistics.set_message_max_length(20);
	m_option_statistics.set_message("STATISTICS");
	m_option_statistics.set_position(26, 1);
	m_option_statistics.set_message_color(GUI_COLOR_WHITE_BLUE);
	
	m_option_settings.set_message_max_length(20);
	m_option_settings.set_message("SETTINGS");
	m_option_settings.set_position(48, 1);
	m_option_settings.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_test.set_message_max_length(100);
	m_test.set_position(5, 12);
	m_test.set_message("ABC");
}

Horizontal_Menu::~Horizontal_Menu()
{
	
}

void Horizontal_Menu::handle(int input)
{
	if (input != -1)
	{
		switch (input)
		{
			case INPUT_ARROW_KEY_RIGHT:
				if(m_menu_selection < 2)
				m_menu_selection++;
				break;

			case INPUT_ARROW_KEY_LEFT:
				if (m_menu_selection > 0)
				m_menu_selection--;
				break;

			default:
				break;
		}
	}
}

void Horizontal_Menu::update()
{
	m_test.set_message(m_menu_selection);

	m_option_settings.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_option_statistics.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_option_status.set_message_color(GUI_COLOR_WHITE_BLUE);

	switch (m_menu_selection)
	{
		case 0:
			m_option_status.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 1:
			m_option_statistics.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 2:
			m_option_settings.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		default:
			break;
	}

}

void Horizontal_Menu::render()
{
	m_option_status.render();
	m_option_statistics.render();
	m_option_settings.render();


	m_test.render();
}

int Horizontal_Menu::get_menu_index()
{
	return m_menu_selection;
}

void Horizontal_Menu::set_highlight(int option)
{
	m_menu_selection = option;
}
