#ifndef __GUI_STATISTICS_HPP__
#define __GUI_STATISTICS_HPP__
#include "GUI_BASE.hpp"
#include "../Widgets/horizontal_menu.hpp"
class GUI_Statistics : public GUI_BASE
{
	private:
		Display_Component	m_current_menu_title;
		Horizontal_Menu		m_horizontal_menu;
		Display_Component	m_splitting_line;

		bool				m_return;

	public:
		GUI_Statistics();
		~GUI_Statistics();

		void handle(int input);
		void update(std::unique_ptr<GUI_BASE>& stack);
		void render();
};
#endif // !__GUI_STATISTICS_HPP__
