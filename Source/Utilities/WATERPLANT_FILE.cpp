#include "WATERPLANT_FILE.hpp"
#include <fstream>
bool WATERPLANT_FILE::exists(std::string path)
{
	std::ifstream instream(path);
	if (instream.fail())
	{
		return false;
	}
	return true;
}

void WATERPLANT_FILE::create(std::string path)
{
	std::fstream settings(path, std::ios::out | std::ios::app);
	if (settings.is_open())
	{
		settings.close();
	}
}
