#include "display_component.hpp"
#include "curses.h"
Display_Component::Display_Component()
{

}

Display_Component::~Display_Component()
{

}

void Display_Component::set_message(std::string message)
{
	m_message.set_message(message);
}

void Display_Component::set_message(int message)
{
	m_message.set_message(message);
}

void Display_Component::set_message_length(int length)
{
	m_message.set_length(length);
}

void Display_Component::set_position(int x, int y)
{
	m_x_position = x;
	m_y_position = y;
}

void Display_Component::set_message_color(int color)
{
	m_color = color;
}

void Display_Component::render()
{
	move(m_y_position, m_x_position);
	attron(COLOR_PAIR(m_color));
	printw(m_message.get_message().c_str());
	attroff(COLOR_PAIR(m_color));
}

void Display_Component::set_optional()
{
	//Colors etc
}
