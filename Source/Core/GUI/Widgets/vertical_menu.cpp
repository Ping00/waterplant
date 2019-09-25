#include "vertical_menu.hpp"
#include "../../GUI/Enums/GUI_COLORS.hpp"
#include "../../GUI/Enums/INPUT_KEYS.hpp"
Vertical_Menu::Vertical_Menu()
{
	//Default our menu index to the first item
	m_menu_selection = 0;
	m_setting_selected = false;

	m_controller_tickrate_text.set_message_max_length(40);
	m_controller_tickrate_text.set_message("Controller Update Rate        (sec):");
	m_controller_tickrate_text.set_position(4, 7);
	
	m_controller_tickrate_data.set_message_max_length(20);
	m_controller_tickrate_data.set_message("0000");
	m_controller_tickrate_data.set_position(46, 7);

	m_tmp36_sensor_tickrate_text.set_message_max_length(40);
	m_tmp36_sensor_tickrate_text.set_message("Temperature Sensor Update Rate (ms):");
	m_tmp36_sensor_tickrate_text.set_position(4, 9);

	m_tmp36_sensor_tickrate_data.set_message_max_length(20);
	m_tmp36_sensor_tickrate_data.set_message("0000");
	m_tmp36_sensor_tickrate_data.set_position(46, 9);

	m_smsm_sensor_tickrate_text.set_message_max_length(40);
	m_smsm_sensor_tickrate_text.set_message("Moisture sensor update rate    (ms):");
	m_smsm_sensor_tickrate_text.set_position(4, 11);

	m_smsm_sensor_tickrate_data.set_message_max_length(20);
	m_smsm_sensor_tickrate_data.set_message("0000");
	m_smsm_sensor_tickrate_data.set_position(46, 11);

	m_smsm_sensor_begin_watering_text.set_message_max_length(40);
	m_smsm_sensor_begin_watering_text.set_message("Watering start (<=) value:");
	m_smsm_sensor_begin_watering_text.set_position(4, 14);

	m_smsm_sensor_begin_watering_data.set_message_max_length(20);
	m_smsm_sensor_begin_watering_data.set_message("0000");
	m_smsm_sensor_begin_watering_data.set_position(46, 14);

	m_smsm_sensor_stop_watering_text.set_message_max_length(40);
	m_smsm_sensor_stop_watering_text.set_message("Watering stop  (>=) value:");
	m_smsm_sensor_stop_watering_text.set_position(4, 16);

	m_smsm_sensor_stop_watering_data.set_message_max_length(20);
	m_smsm_sensor_stop_watering_data.set_message("0000");
	m_smsm_sensor_stop_watering_data.set_position(46, 16);


}

Vertical_Menu::~Vertical_Menu()
{

}

void Vertical_Menu::handle(int input)
{
	if (input != -1)
	{
		if (!m_setting_selected)
		{
			switch (input)
			{
			case INPUT_ARROW_KEY_DOWN:
				if (m_menu_selection < 4)
					m_menu_selection++;
				break;

			case INPUT_ARROW_KEY_UP:
				if (m_menu_selection > 0)
					m_menu_selection--;
				break;

			case INPUT_KEY_ENTER:
				m_setting_selected = true;
				break;

			default:
				break;
			}
		}
	}
}

void Vertical_Menu::update(Controller& controller)
{
	//Default colors for all settings
	m_controller_tickrate_text.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_tmp36_sensor_tickrate_text.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_smsm_sensor_tickrate_text.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_smsm_sensor_begin_watering_text.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_smsm_sensor_stop_watering_text.set_message_color(GUI_COLOR_WHITE_BLUE);

	//Update highlight if setting has been selected
	switch (m_menu_selection)
	{
		case 0:
			m_controller_tickrate_text.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 1:
			m_tmp36_sensor_tickrate_text.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 2:
			m_smsm_sensor_tickrate_text.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 3:
			m_smsm_sensor_begin_watering_text.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 4:
			m_smsm_sensor_stop_watering_text.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		default:
			break;
	}

	//---
	m_controller_tickrate_data.set_message(controller.get_tickrate());
	m_tmp36_sensor_tickrate_data.set_message(controller.get_mcp3008_channel_tickrate(0));
	m_smsm_sensor_tickrate_data.set_message(controller.get_mcp3008_channel_tickrate(1));
	m_smsm_sensor_begin_watering_data.set_message(controller.get_valve_open_value());
	m_smsm_sensor_stop_watering_data.set_message(controller.get_valve_close_value());
}


void Vertical_Menu::render()
{
	m_controller_tickrate_data.render();
	m_controller_tickrate_text.render();

	m_tmp36_sensor_tickrate_text.render();
	m_tmp36_sensor_tickrate_data.render();

	m_smsm_sensor_tickrate_text.render();
	m_smsm_sensor_tickrate_data.render();

	m_smsm_sensor_begin_watering_text.render();
	m_smsm_sensor_begin_watering_data.render();

	m_smsm_sensor_stop_watering_text.render();
	m_smsm_sensor_stop_watering_data.render();
}
