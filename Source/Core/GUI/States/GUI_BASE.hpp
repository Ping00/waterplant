#ifndef __GUI_BASE_HPP__
#define __GUI_BASE_HPP__
#include "../Textwidgets/display_component.hpp"
class GUI_BASE
{

	public:
		GUI_BASE();
		virtual ~GUI_BASE();

		virtual void handle() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
};
#endif // !__GUI_HPP__
