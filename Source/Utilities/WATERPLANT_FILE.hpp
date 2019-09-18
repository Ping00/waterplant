#ifndef __WATERPLANT_FILE_HPP__
#define __WATERPLANT_FILE_HPP__
#include <string>
class WATERPLANT_FILE
{
	static bool exists(std::string path);
	static void create(std::string path);
};
#endif // !__FILE_HPP__
