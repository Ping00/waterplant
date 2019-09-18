#ifndef __WATERPLANT_FILE_HPP__
#define __WATERPLANT_FILE_HPP__
#include <string>
class WATERPLANT_FILE
{
	public:
		static bool exists(std::string path);
		static void create(std::string path);
		static int	read(std::string path, int offset);
};
#endif // !__FILE_HPP__
