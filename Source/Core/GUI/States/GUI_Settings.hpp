#ifndef __GUI_SETTINGS_HPP__
#define __GUI_SETTINGS_HPP__
#include "GUI_BASE.hpp"
class GUI_Settings : public GUI_BASE
{
	public:
		GUI_Settings();
		~GUI_Settings();

		void handle(int input);
		void update(std::stack<std::unique_ptr<GUI_BASE>>& stack);
		void render();
};
#endif // !__GUI_SETTINGS_HPP__
