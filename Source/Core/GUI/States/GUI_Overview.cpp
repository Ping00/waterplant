#include "GUI_Overview.hpp"
#include <iostream>
#include "../Enums/GUI_COLORS.hpp"
#include "../Enums/INPUT_KEYS.hpp"
#include "GUI_Status.hpp"
#include "GUI_Statistics.hpp"
#include "GUI_Settings.hpp"
#include "curses.h"

#include "../../../Utilities/utilities.hpp"
#include <iomanip>
#include <sstream>
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

	m_current_time.set_message_max_length(30);
	m_current_time.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_current_time.set_message("00:00:00");
	m_current_time.set_position(4, 7);

	m_current_temperature_text.set_message_max_length(30);
	m_current_temperature_text.set_message("Current Temperature: ");
	m_current_temperature_text.set_position(4, 9);
	m_current_temperature_text.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_current_temperature_data.set_message_max_length(10);
	m_current_temperature_data.set_message("0.0 °C");
	m_current_temperature_data.set_position(32, 9);
	m_current_temperature_data.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_current_smsm_value_text.set_message_max_length(30);
	m_current_smsm_value_text.set_message("Soil Moisture Level:");
	m_current_smsm_value_text.set_position(4, 11);
	m_current_smsm_value_text.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_current_smsm_value_data.set_message_max_length(10);
	m_current_smsm_value_data.set_message("000");
	m_current_smsm_value_data.set_position(32, 11);
	m_current_smsm_value_data.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_valve_open_text.set_message_max_length(30);
	m_valve_open_text.set_message("Valve State:");
	m_valve_open_text.set_position(4, 13);
	m_valve_open_text.set_message_color(GUI_COLOR_WHITE_BLUE);

	m_valve_open_data.set_message_max_length(10);
	m_valve_open_data.set_message("[ ??? ]");
	m_valve_open_data.set_position(32, 13);
	m_valve_open_data.set_message_color(GUI_COLOR_WHITE_BLUE);

}

GUI_Overview::~GUI_Overview()
{
	//std::cout << "Destructor called for GUI_Overview :> (" << this << ")" << std::endl;
}

void GUI_Overview::handle(int input)
{
	m_horizontal_menu.handle(input);
	if (input == INPUT_KEY_ENTER)
	{
		m_selected_option = true;
	}
	else
	{
		m_selected_option = false;
	}
}

void GUI_Overview::update(std::unique_ptr<GUI_BASE>& menu, Controller& controller)
{
	//Populate with data from Controller

	//Update clock
	m_current_time.set_message(Utilities::get_current_time());

	//Update temperature
	m_current_temperature_data.set_message(Utilities::convert_temp_data_to_string(controller.get_mcp3008_reading(0)));

	//Update soil moisture
	m_current_smsm_value_data.set_message((int)(controller.get_mcp3008_reading(1)));

	//Set valve status
	m_valve_open_data.set_message(Utilities::get_open_closed_state_msg(controller.get_valve_open_state()));

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
	m_current_time.render();

	m_current_temperature_text.render();
	m_current_temperature_data.render();

	m_current_smsm_value_text.render();
	m_current_smsm_value_data.render();

	m_valve_open_text.render();
	m_valve_open_data.render();
}

void GUI_Overview::set_highlight(int pos)
{
	m_horizontal_menu.set_highlight(pos);
}
