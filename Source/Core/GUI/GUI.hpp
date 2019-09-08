#ifndef __GUI_HPP__
#define __GUI_HPP__
#include "States/GUI_BASE.hpp"
#include <memory>
class GUI
{
	private:
		void init_colors();

		bool						m_initialized;
		std::unique_ptr<GUI_BASE>	m_gui;
		
		int							m_input;
		bool						m_enter;

	public:
		GUI();
		~GUI();

		bool init();

		void handle();
		void update();
		void render();
};
#endif // !__GUI_HPP__
