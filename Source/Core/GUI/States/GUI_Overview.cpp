#include "GUI_Overview.hpp"
#include <iostream>
#include "../Enums/GUI_COLORS.hpp"
#include "../Enums/INPUT_KEYS.hpp"
#include "GUI_Status.hpp"
#include "GUI_Statistics.hpp"
#include "GUI_Settings.hpp"
#include "curses.h"
GUI_Overview::GUI_Overview()
{
	m_selected_option = false;

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
	m_horizontal_menu.handle(input);
	m_test.set_message(input);
	if (input == INPUT_KEY_ENTER)
	{
		m_selected_option = true;
	}
	else
	{
		m_selected_option = false;
	}
}

void GUI_Overview::update(std::unique_ptr<GUI_BASE>& menu)
{
	//Populate with data from Controller


	//Update menu based on input settings
	m_horizontal_menu.update();
	if (m_selected_option)
	{
		int transfer = m_horizontal_menu.get_menu_index();
		switch (transfer)
		{
			case 0:
				clear();
				menu = std::make_unique<GUI_Status>();
				break;

			case 1:
				clear();
				menu = std::make_unique<GUI_Statistics>();
				break;

			case 2:
				clear();
				menu = std::make_unique<GUI_Settings>();
				break;

			default:
				break;
		}
	}
}

void GUI_Overview::render()
{
	m_horizontal_menu.render();
	m_splitting_line.render();
	m_current_menu_title.render();
	m_test.render();
}

void GUI_Overview::set_highlight(int pos)
{
	m_horizontal_menu.set_highlight(pos);
}
