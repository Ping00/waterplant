#ifndef __GUI_OVERVIEW_HPP__
#define __GUI_OVERVIEW_HPP__
#include "GUI_BASE.hpp"
#include "../Widgets/horizontal_menu.hpp"
class GUI_Overview : public GUI_BASE
{
	private:
		Display_Component	m_test;
		Display_Component	m_splitting_line;
		Display_Component	m_current_menu_title;
		Horizontal_Menu		m_horizontal_menu;

	public:
		GUI_Overview();
		~GUI_Overview();

		void handle(int input);
		void update(std::unique_ptr<GUI_BASE>& stack);
		void render();
};
#endif // !__GUI_OVERVIEW_HPP__
