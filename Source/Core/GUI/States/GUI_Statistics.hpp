#ifndef __GUI_STATISTICS_HPP__
#define __GUI_STATISTICS_HPP__
#include "GUI_BASE.hpp"
class GUI_Statistics : public GUI_BASE
{
	public:
		GUI_Statistics();
		~GUI_Statistics();

		void handle(int input);
		void update(std::unique_ptr<GUI_BASE>& stack);
		void render();
};
#endif // !__GUI_STATISTICS_HPP__
