#include "graphic.hpp"

Graphic::Graphic()
{
}

Graphic::~Graphic()
{
}

void Graphic::set_position(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Graphic::set_color(GUI_COLORS color)
{
	m_color = color;
}

void Graphic::load_graphic(std::string file)
{
	//TODO NOT IMPLEMENTED YET (ETA v1.0)

	
	std::vector<std::string> image_row;
	image_row.push_back("__          __   _                  _             _   ");
	image_row.push_back("\\ \\        / /  | |                | |           | |  ");
	image_row.push_back(" \\ \\  /\\  / /_ _| |_ ___ _ __ _ __ | | __ _ _ __ | |_ ");
	image_row.push_back("  \\ \\/  \\/ / _` | __/ _ \\ '__| '_ \\| |/ _` | '_ \\| __|");
	image_row.push_back("   \\  /\\  / (_| | ||  __/ |  | |_) | | (_| | | | | |_ ");
	image_row.push_back("    \\/  \\/ \\__,_|\\__\\___|_|  | .__/|_|\\__,_|_| |_|\\__|");
	image_row.push_back("                             | |                      ");
	image_row.push_back("                             |_|                      ");


	int image_total_columns = image_row.size();
	for (int i = 0; i < image_total_columns; i++)
	{
		Display_Component graphic_line;
		graphic_line.set_message_color(m_color);
		graphic_line.set_message_max_length(image_row[i].length()+1);
		graphic_line.set_message(image_row[i]);
		graphic_line.set_position(m_x, m_y + i);
		m_graphic.push_back(graphic_line);
	}
	


	/*
	std::vector<std::string> graphic;
	graphic.push_back("__          __   _                  _             _   ");
	graphic.push_back("\\\ \\\        / /  | |                | |           | |  ");
	graphic.push_back(" \\\ \\\  /\\\  / /_ _| |_ ___ _ __ _ __ | | __ _ _ __ | |_ ");
	graphic.push_back("  \\\ \\\/  \\\/ / _` | __/ _ \\\ '__| '_ \\\| |/ _` | '_ \\\| __|");
	graphic.push_back("   \\\  /\\\  / (_| | ||  __/ |  | |_) | | (_| | | | | |_ ");
	graphic.push_back("    \\\/  \\\/ \\\__,_|\\\__\\\___|_|  | .__/|_|\\\__,_|_| |_|\\\__|");
	graphic.push_back("                             | |                      ");
	graphic.push_back("                             |_|                      ");

	for (int i = 0; i < graphic.size(); i++)
	{
		Display_Component x;
		x.set_position(30, 10 + i);
		x.set_message_max_length(60);
		x.set_message(graphic[i]);
		m_titlecard.push_back(x);
	}
	*/
}

void Graphic::render()
{
	int size = m_graphic.size();
	for (int i = 0; i < size; i++)
	{
		m_graphic[i].render();
	}
}
