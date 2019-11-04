#include "TMP36.hpp"
TMP36::TMP36()
{

}

TMP36::~TMP36()
{

}

double TMP36::format(double data)
{
	//Converts our ADC results into the proper format to be read (Depending on device)

	//the current schematic uses a 3.3v pin for the voltage so it needs to be converted from
	//a range of 0-1023 to 0-3.3v
	double voltage = data * 3.3;
	voltage /= 1024.0;

	//Convert voltage to temperature
	double temperature = (voltage - 0.5) * 100.0;
	return temperature;
}

void TMP36::load_settings(std::string path)
{
	set_tickrate(WATERPLANT_FILE::read(path, FILE_DATA_TMP36_TICKRATE));
}
