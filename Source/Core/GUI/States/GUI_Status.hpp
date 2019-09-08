#ifndef __GUI_STATUS_HPP__
#define __GUI_STATUS_HPP__
#include "GUI_BASE.hpp"
class GUI_Status : public GUI_BASE
{
	private:
		Display_Component	m_current_menu_title;

	public:
		GUI_Status();
		~GUI_Status();

		void handle(int input);
		void update(std::unique_ptr<GUI_BASE>& stack);
		void render();
};
#endif // !__GUI_STATUS_HPP__
