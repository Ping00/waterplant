#include "utilities.hpp"
#include <chrono>
#include <string>
#include <ctime>
std::string Utilities::get_current_time()
{

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm newtime;

	localtime_s(&newtime, &now_c);

	char buffer[20];
	strftime(buffer, sizeof(buffer), "%H:%M:%S", &newtime);
	
	return std::string(buffer);
}
