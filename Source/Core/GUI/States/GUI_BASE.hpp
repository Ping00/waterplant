#ifndef __GUI_BASE_HPP__
#define __GUI_BASE_HPP__
#include "../Widgets/display_component.hpp"
class GUI_BASE
{

	public:
		GUI_BASE();
		virtual ~GUI_BASE();

		virtual void handle(int input) = 0;
		virtual void update(std::unique_ptr<GUI_BASE>& stack) = 0;
		virtual void render() = 0;
};
#endif // !__GUI_HPP__
