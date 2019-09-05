#ifndef __GRAPHIC_HPP__
#define __GRAPHIC_HPP__
#include <vector>
#include "display_component.hpp"
class Graphic
{
	private:
		std::vector<Display_Component> m_graphic;
		int m_x;
		int m_y;

	public:
		Graphic();
		~Graphic();

		void render();
};
#endif // !__GRAPHIC_HPP__
