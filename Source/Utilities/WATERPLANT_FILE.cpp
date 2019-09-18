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
		const short int test = 2000;
		settings.write((char*) &test, sizeof(short int));

		settings.close();
	}
}

int WATERPLANT_FILE::read(std::string path, int offset, int read_bytes)
{
	unsigned short int data = 0;
	char bytes[32] = { 0 };

	std::ifstream settings(path, std::ios::out | std::ios::binary | std::ios::app);
	if (settings.is_open())
	{
		settings.seekg(offset);
		settings.read(bytes, read_bytes);
		return bytes[0];
	}
	return -1;
}
