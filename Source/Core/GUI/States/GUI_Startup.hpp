#ifndef __GUI_STARTUP_HPP__
#define __GUI_STARTUP_HPP__
#include "GUI_BASE.hpp"
#include <string>
#include "../Textwidgets/display_component.hpp"
class GUI_Startup : public GUI_BASE
{
	private:
		//GUI Components /Bars, Menus, Texts, etc.
		Display_Component	m_version;
		Display_Component	m_valve_status;

	public:
		GUI_Startup();
		~GUI_Startup();

		void handle();
		void update();
		void render();

};
#endif // !__GUI_STARTUP_HPP__
