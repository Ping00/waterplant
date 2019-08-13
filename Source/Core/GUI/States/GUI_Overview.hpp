#ifndef __GUI_OVERVIEW_HPP__
#define __GUI_OVERVIEW_HPP__
#include "../GUI.hpp"
class GUI_Overview : public GUI
{
	
	public:
		GUI_Overview();
		~GUI_Overview();

		void handle();
		void update();
		void render();
};
#endif // !__GUI_OVERVIEW_HPP__
