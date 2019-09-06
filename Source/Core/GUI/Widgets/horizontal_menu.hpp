#ifndef __HORIZONTAL_MENU_HPP__
#define __HORIZONTAL_MENU_HPP__
#include "display_component.hpp"
#include <vector>
class Horizontal_Menu
{
	private:
		Display_Component	m_option_status;
		Display_Component	m_option_settings;
		Display_Component	m_option_statistics;

		int m_menu_selection;

		bool m_enter;

		Display_Component m_test;

	public:
		Horizontal_Menu();
		~Horizontal_Menu();

		void handle(int input);
		void update();
		void render();
};
#endif // !__HORIZONTAL_MENU_HPP__
