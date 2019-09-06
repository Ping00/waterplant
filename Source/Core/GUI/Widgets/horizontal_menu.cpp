#include "horizontal_menu.hpp"
#include "../Enums/INPUT_KEYS.hpp"
#include "../Enums/GUI_COLORS.hpp"
Horizontal_Menu::Horizontal_Menu()
{
	m_enter = false;
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

	test.set_message_max_length(100);
	test.set_position(7, 7);
	test.set_message("!");


}

Horizontal_Menu::~Horizontal_Menu()
{

}

void Horizontal_Menu::handle(int input)
{

}

void Horizontal_Menu::update()
{

}

void Horizontal_Menu::render()
{
	m_option_status.render();
	m_option_statistics.render();
	m_option_settings.render();
	test.render();
}
