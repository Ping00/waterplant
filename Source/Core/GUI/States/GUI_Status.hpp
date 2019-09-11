#ifndef __GUI_STATUS_HPP__
#define __GUI_STATUS_HPP__
#include "GUI_BASE.hpp"
#include "../Widgets/horizontal_menu.hpp"
class GUI_Status : public GUI_BASE
{
	private:
		Display_Component	m_current_menu_title;
		Horizontal_Menu		m_horizontal_menu;
		Display_Component	m_splitting_line;

		bool				m_return;
		///----

		Display_Component	m_runtime_text;
		Display_Component	m_runtime_data;

		Display_Component	m_controller_status_text;
		Display_Component	m_controller_status_data;

		Display_Component	m_valve_status_text;
		Display_Component	m_valve_status_data;

		Display_Component	m_mcp_status_text;
		Display_Component	m_mcp_status_data;

		Display_Component	m_active_mcp_devices_text;
		Display_Component	m_active_mcp_devices_data;

		Display_Component	m_sensor_temperature_text;
		Display_Component	m_sensor_temperature_data;

		Display_Component	m_sensor_moisture_level_text;
		Display_Component	m_sensor_moisture_level_data;

	public:
		GUI_Status();
		~GUI_Status();

		void handle(int input);
		void update(std::unique_ptr<GUI_BASE>& stack, Controller& controller);
		void render();
};
#endif // !__GUI_STATUS_HPP__
