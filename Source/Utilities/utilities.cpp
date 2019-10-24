#include "utilities.hpp"
#include <chrono>
#include <string>
#include <ctime>
#include <time.h>
#include <sstream>
#include <iomanip>
std::string Utilities::get_current_time()
{
	
	//LINUX
	struct tm newtime;
	time_t ltime;
	
	ltime = time(&ltime);
	localtime_r(&ltime, &newtime);
	
	std::stringstream ss;
	ss  << std::setw(2) << std::setfill('0') << newtime.tm_hour << ":" 
		<< std::setw(2) << std::setfill('0') << newtime.tm_min << ":"
		<< std::setw(2) << std::setfill('0') << newtime.tm_sec;
	
	//WINDOWS
	/*
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm newtime;

	localtime_r(&newtime, &now_c);

	char buffer[20];
	strftime(buffer, sizeof(buffer), "%H:%M:%S", &newtime);
	*/
	return std::string(ss.str());
}

std::string Utilities::get_time_difference(std::chrono::high_resolution_clock::time_point time)
{
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(now - time);

	double elapsed = time_span.count();
	int hours = (int)elapsed / (60*60);
	int min = ((int)elapsed / 60) % 60;
	int sec = (int)elapsed % 60;

	std::stringstream ss;
	ss  << std::setw(2) << std::setfill('0') << hours << ":" 
		<< std::setw(2) << std::setfill('0') << min << ":"
		<< std::setw(2) << std::setfill('0') << sec;

	return std::string(ss.str());
}

std::string Utilities::convert_temp_data_to_string(double temp)
{

	//Fix presentation
	std::stringstream ss;
	ss << std::fixed << std::setprecision(1) << std::setw(2) << std::setfill('0') << temp << " °C";

	return ss.str();
}

std::string Utilities::get_open_closed_state_msg(bool state)
{
	if (state)
	{
		return "[ OPEN ]";
	}
	else
	{
		return "[ CLOSED ]";
	}
}

std::string Utilities::get_ok_error_state_msg(bool state)
{
	if (state)
	{
		return "[ OK ]";
	}
	else
	{
		return "[ ERROR ]";
	}
}
