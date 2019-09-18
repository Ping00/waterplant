#ifndef __VERTICAL_MENU__
#define __VERTICAL_MENU__
#include "display_component.hpp"
#include "../../Controller/controller.hpp"
class Vertical_Menu
{
	private:
		Display_Component	m_controller_tickrate_text;
		Display_Component	m_controller_tickrate_data;

		Display_Component	m_tmp36_sensor_tickrate_text;
		Display_Component	m_tmp36_sensor_tickrate_data;

		Display_Component	m_smsm_sensor_tickrate_text;
		Display_Component	m_smsm_sensor_tickrate_data;

		Display_Component	m_smsm_sensor_begin_watering_text;
		Display_Component	m_smsm_sensor_begin_watering_data;

		Display_Component	m_smsm_sensor_stop_watering_text;
		Display_Component	m_smsm_sensor_stop_watering_data;


		int	m_menu_selection;


	public:
		Vertical_Menu();
		~Vertical_Menu();

		void handle(int input);
		void update(Controller& controller);
		void render();

};
#endif // !__VERTIVAL_MENU__
