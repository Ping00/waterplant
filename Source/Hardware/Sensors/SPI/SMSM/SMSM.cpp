#include "SMSM.hpp"
SMSM::SMSM()
{

}

SMSM::~SMSM()
{

}

double SMSM::format(double data)
{
	//SMSM has no proper formatting, uses raw data
	return 100.0;
}

void SMSM::load_settings(std::string path)
{
	set_tickrate(WATERPLANT_FILE::read(path, FILE_DATA_SMSM_TICKRATE));
}
