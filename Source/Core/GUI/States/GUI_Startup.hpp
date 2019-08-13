#ifndef __GUI_STARTUP_HPP__
#define __GUI_STARTUP_HPP__
#include "../GUI.hpp"
class GUI_Startup : public GUI
{
	private:
		//GUI Components /Bars, Menus, Texts, etc.

	public:
		GUI_Startup();
		~GUI_Startup();

		void handle();
		void update();
		void render();

};
#endif // !__GUI_STARTUP_HPP__
