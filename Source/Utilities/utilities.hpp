#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__
#include <string>
#include <chrono>
class Utilities
{
	public:
		static std::string get_current_time();
		static std::string get_time_difference(std::chrono::high_resolution_clock::time_point time);
};
#endif // !__UTILITIES_HPP__
