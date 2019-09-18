#include "WATERPLANT_FILE.hpp"
#include <fstream>
bool WATERPLANT_FILE::exists(std::string path)
{
	//Check if file exists
	std::ifstream instream(path);
	if (instream.fail())
	{
		return false;
	}
	return true;
}

void WATERPLANT_FILE::create(std::string path)
{
	//create/open file
	std::ofstream settings(path, std::ios::out | std::ios::binary);
	if (settings.is_open())
	{
		//Add in basic settings data
		const short int test = 2000;
		settings.write((char*) &test, sizeof(short int));

		settings.close();
	}
}

int WATERPLANT_FILE::read(std::string path, int offset, int read_bytes)
{
	return -1;
}
