#ifndef __GUI_HPP__
#define __GUI_HPP__
#include "States/GUI_BASE.hpp"
#include <memory>
#include <stack>
class GUI
{
	private:
		bool									m_initialized;
		std::stack<std::unique_ptr<GUI_BASE>>	m_gui;

		void init_colors();

	public:
		GUI();
		~GUI();

		bool init();

		void handle();
		void update();
		void render();
};
#endif // !__GUI_HPP__
