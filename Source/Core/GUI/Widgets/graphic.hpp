#ifndef __GRAPHIC_HPP__
#define __GRAPHIC_HPP__
#include <vector>
#include "display_component.hpp"
#include "../Enums/GUI_COLORS.hpp"
class Graphic
{
	private:
		std::vector<Display_Component> m_graphic;

		int m_x;
		int m_y;
		int m_color;

	public:
		Graphic();
		~Graphic();

		void set_position(int x, int y);
		void set_color(GUI_COLORS color);
		void load_graphic(std::string file);
		void render();
};
#endif // !__GRAPHIC_HPP__
