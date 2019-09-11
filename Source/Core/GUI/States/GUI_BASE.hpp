#ifndef __GUI_BASE_HPP__
#define __GUI_BASE_HPP__
#include "../../Controller/controller.hpp"
class GUI_BASE
{

	public:
		GUI_BASE();
		virtual ~GUI_BASE();

		virtual void handle(int input) = 0;
		virtual void update(std::unique_ptr<GUI_BASE>& menu, Controller& controller) = 0;
		virtual void render() = 0;
};
#endif // !__GUI_HPP__
