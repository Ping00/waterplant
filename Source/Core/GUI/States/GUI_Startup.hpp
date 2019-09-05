#ifndef __GUI_STARTUP_HPP__
#define __GUI_STARTUP_HPP__
#include "GUI_BASE.hpp"
#include <vector>
#include "../Widgets/display_component.hpp"
#include "../Widgets/graphic.hpp"
class GUI_Startup : public GUI_BASE
{
	private:
		//GUI Components /Bars, Menus, Texts, etc.
		Display_Component	m_version;
		Display_Component	m_build;
		Graphic				m_titlecard;
		
		int m_timer = 0;

	public:
		GUI_Startup();
		~GUI_Startup();

		void handle();
		void update();
		void render();

};
#endif // !__GUI_STARTUP_HPP__
