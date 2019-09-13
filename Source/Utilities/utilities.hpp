#ifndef __UTILITIES_HPP__
#define __UTILITIES_HPP__
#include <string>
#include <chrono>
class Utilities
{
	public:
		static std::string get_current_time();
		static std::string get_time_difference(std::chrono::high_resolution_clock::time_point time);
		static std::string convert_temp_data_to_string(double data);
		static std::string get_open_closed_state_msg(bool state);
		static std::string get_ok_error_state_msg(bool state);
};
#endif // !__UTILITIES_HPP__
