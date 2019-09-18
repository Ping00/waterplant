#include "WATERPLANT_FILE.hpp"
#include <fstream>
#include <sstream>
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
		const short int controller_default_tickrate = 2000;
		const short int tmp36_default_tickrate = 200;
		settings.write((char*) &controller_default_tickrate, sizeof(short int));
		settings.write((char*) &tmp36_default_tickrate, sizeof(short int));

		settings.close();
	}
}

int WATERPLANT_FILE::read(std::string path, int offset)
{
	unsigned short int data = 0;
	char bytes[32] = { 0 };

	std::ifstream settings(path, std::ios::out | std::ios::binary | std::ios::app);
	if (settings.is_open())
	{
		settings.seekg(2);
		settings.read(bytes, offset);
		data = ((bytes[1] << 8) | (bytes[0] & 0xFF));
		return data;
	}
	return -1;
}
