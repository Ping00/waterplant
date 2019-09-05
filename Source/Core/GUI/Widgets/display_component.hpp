#ifndef __DISPLAY_COMPONENT_HPP__
#define __DISPLAY_COMPONENT_HPP__
#include "message.hpp"
class Display_Component
{
	private:
		int m_x_position;
		int m_y_position;
		int m_color;
		Message m_message;

	public:
		Display_Component();
		~Display_Component();

		void set_message(std::string message);
		void set_message(int message);
		void set_message_max_length(int length);
		void set_position(int x, int y);
		void set_message_color(int color);
		void render();
		void set_optional();


};
#endif // !__DISPLAY_COMPONENT_HPP__
