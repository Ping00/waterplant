#include "vertical_menu.hpp"
#include "../../GUI/Enums/GUI_COLORS.hpp"
#include "../../GUI/Enums/INPUT_KEYS.hpp"
Vertical_Menu::Vertical_Menu()
{
	//Default our menu index to the first item
	m_menu_selection = 0;
	m_setting_state = 1;

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
		if (m_setting_state < 2)
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
					m_setting_state = 2;
					break;

				case INPUT_KEY_RETURN:
					m_setting_state = 0;

				default:
					break;
			}
		}
		else
		{
			switch (input)
			{
				case INPUT_ARROW_KEY_DOWN:

					break;

				case INPUT_ARROW_KEY_UP:

					break;

				case INPUT_KEY_RETURN:
					m_setting_state = 1;
					break;

				case INPUT_KEY_ENTER:
					m_save_settings = true;
					m_setting_state = 1;
					break;

				default:
					break;
			}
		}
	}
}

void Vertical_Menu::update(Controller& controller)
{
	//Default colors for all settings text
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

	//Update setting values if in correct state
	m_controller_tickrate_data.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_tmp36_sensor_tickrate_data.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_smsm_sensor_tickrate_data.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_smsm_sensor_begin_watering_data.set_message_color(GUI_COLOR_WHITE_BLUE);
	m_smsm_sensor_stop_watering_data.set_message_color(GUI_COLOR_WHITE_BLUE);
	
	if (m_setting_state == 2)
	{
		switch (m_menu_selection)
		{
		case 0:
			m_controller_tickrate_data.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 1:
			m_tmp36_sensor_tickrate_data.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 2:
			m_smsm_sensor_tickrate_data.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 3:
			m_smsm_sensor_begin_watering_data.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		case 4:
			m_smsm_sensor_stop_watering_data.set_message_color(GUI_COLOR_BLUE_WHITE);
			break;

		default:
			break;
		}
	}

	//save new values
	if (m_save_settings)
	{

		//Reset save settings after complete
		m_save_settings = false;
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

int Vertical_Menu::get_setting_selected()
{
	return m_setting_state;
}
