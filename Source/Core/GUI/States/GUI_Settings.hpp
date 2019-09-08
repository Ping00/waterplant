#ifndef __GUI_SETTINGS_HPP__
#define __GUI_SETTINGS_HPP__
#include "GUI_BASE.hpp"
#include "../Widgets/horizontal_menu.hpp"
class GUI_Settings : public GUI_BASE
{
	private:
		Display_Component	m_current_menu_title;
		Horizontal_Menu		m_horizontal_menu;
		Display_Component	m_splitting_line;

		bool				m_return;

	public:
		GUI_Settings();
		~GUI_Settings();

		void handle(int input);
		void update(std::unique_ptr<GUI_BASE>& stack);
		void render();
};
#endif // !__GUI_SETTINGS_HPP__
