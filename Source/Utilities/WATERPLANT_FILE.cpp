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
	std::ofstream settings(path, std::ios::out | std::ios::binary | std::ios::app);
	if (settings.is_open())
	{
		//Add in basic settings data
		const short int controller_default_tickrate = 600;
		const short int tmp36_default_tickrate = 200;
		const short int smsm_default_tickrate = 200;
		const short int valve_open_default_value = 20;
		const short int valve_close_default_value = 100;

		settings.write((char*) &controller_default_tickrate, sizeof(short int));
		settings.write((char*) &tmp36_default_tickrate, sizeof(short int));
		settings.write((char*) &smsm_default_tickrate, sizeof(short int));
		settings.write((char*) &valve_open_default_value, sizeof(short int));
		settings.write((char*) &valve_close_default_value, sizeof(short int));

		settings.close();
	}
}

int WATERPLANT_FILE::read(std::string path, int offset)
{
	unsigned short int data = 0;
	char bytes[2] = { 0 };

	std::ifstream settings(path, std::ios::in | std::ios::binary);
	if (settings.is_open())
	{
		settings.seekg(offset);
		settings.read(bytes, 2);
		data = ((bytes[1] << 8) | (bytes[0] & 0xFF));
		settings.close();
		return data;
	}
	return -1;
}

void WATERPLANT_FILE::overwrite(std::string path, int offset, const short int data)
{
	//Overwrites bytes at specified location
	std::ofstream settings(path, std::ios::out | std::ios::in | std::ios::binary);
	if (settings.is_open())
	{
		settings.seekp(offset, std::ios::beg);
		settings.write((char*)& data, sizeof(short int));
		settings.close();
	}
}
