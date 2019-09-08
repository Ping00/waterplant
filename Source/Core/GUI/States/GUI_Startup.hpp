#ifndef __GUI_STARTUP_HPP__
#define __GUI_STARTUP_HPP__
#include "GUI_BASE.hpp"
#include <vector>
#include "../Widgets/display_component.hpp"
#include "../Widgets/graphic.hpp"
#include "../../../Utilities/timer.hpp"
class GUI_Startup : public GUI_BASE
{
	private:
		//GUI Components /Bars, Menus, Texts, etc.
		Display_Component	m_version;
		Display_Component	m_build;
		Graphic				m_titlecard;
		
		Timer				m_timer;

	public:
		GUI_Startup();
		~GUI_Startup();

		void handle(int input);
		void update(std::unique_ptr<GUI_BASE>& stack);
		void render();

};
#endif // !__GUI_STARTUP_HPP__
