#include "GUI_Status.hpp"
#include "../Enums/GUI_COLORS.hpp"
#include "../Enums/INPUT_KEYS.hpp"
#include "GUI_Overview.hpp"
#include "curses.h"
#include "../../../Utilities/utilities.hpp"
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

	//----

	m_runtime_text.set_message_max_length(24);
	m_runtime_text.set_position(4, 7);
	m_runtime_text.set_message("Total Runtime (Session):");

	m_runtime_data.set_message_max_length(24);
	m_runtime_data.set_position(32, 7);
	m_runtime_data.set_message("00:00:00");

	m_controller_status_text.set_message_max_length(20);
	m_controller_status_text.set_position(4, 9);
	m_controller_status_text.set_message("Controller Status:");

	m_controller_status_data.set_message_max_length(20);
	m_controller_status_data.set_position(32, 9);
	m_controller_status_data.set_message("[ ??? ]");

	m_valve_status_text.set_message_max_length(20);
	m_valve_status_text.set_position(4, 11);
	m_valve_status_text.set_message("Valve Status:");

	m_valve_status_data.set_message_max_length(20);
	m_valve_status_data.set_position(32, 11);
	m_valve_status_data.set_message("[ ??? ]");

	m_mcp_status_text.set_message_max_length(20);
	m_mcp_status_text.set_position(4, 13);
	m_mcp_status_text.set_message("MCP3008 Status:");

	m_mcp_status_data.set_message_max_length(20);
	m_mcp_status_data.set_position(32, 13);
	m_mcp_status_data.set_message("[ ??? ]");

	m_active_mcp_devices_text.set_message_max_length(20);
	m_active_mcp_devices_text.set_position(4, 15);
	m_active_mcp_devices_text.set_message("Registered Sensors:");

	m_active_mcp_devices_data.set_message_max_length(20);
	m_active_mcp_devices_data.set_position(32, 15);
	m_active_mcp_devices_data.set_message("0");

	m_sensor_temperature_status_text.set_message_max_length(20);
	m_sensor_temperature_status_text.set_position(4, 17);
	m_sensor_temperature_status_text.set_message("TMP36 Status:");

	m_sensor_temperature_status_data.set_message_max_length(20);
	m_sensor_temperature_status_data.set_position(32, 17);
	m_sensor_temperature_status_data.set_message("[ ??? ]");

	m_sensor_moisture_status_text.set_message_max_length(20);
	m_sensor_moisture_status_text.set_position(4, 19);
	m_sensor_moisture_status_text.set_message("SMSMS Status:");

	m_sensor_moisture_status_data.set_message_max_length(20);
	m_sensor_moisture_status_data.set_position(32, 19);
	m_sensor_moisture_status_data.set_message("[ ??? ]");

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

void GUI_Status::update(std::unique_ptr<GUI_BASE>& menu, Controller& controller)
{
	//Update text statuses by polling devices from controller and utilities
	m_runtime_data.set_message(Utilities::get_time_difference(controller.get_system_start()));
	m_controller_status_data.set_message(Utilities::get_ok_error_state_msg(controller.get_controller_initlialized()));
	m_valve_status_data.set_message(Utilities::get_ok_error_state_msg(controller.get_valve_initialized()));
	m_mcp_status_data.set_message(Utilities::get_ok_error_state_msg(controller.get_mcp3008_initialized()));

	m_sensor_temperature_status_data.set_message(Utilities::get_ok_error_state_msg(controller.get_mcp3008_channel_init_status(0)));
	m_sensor_moisture_status_data.set_message(Utilities::get_ok_error_state_msg(controller.get_mcp3008_channel_init_status(1)));

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

	m_runtime_text.render();
	m_runtime_data.render();

	m_controller_status_text.render();
	m_controller_status_data.render();

	m_valve_status_text.render();
	m_valve_status_data.render();

	m_mcp_status_text.render();
	m_mcp_status_data.render();

	m_sensor_moisture_status_data.render();
	m_sensor_moisture_status_text.render();

	m_sensor_temperature_status_data.render();
	m_sensor_temperature_status_text.render();
}
