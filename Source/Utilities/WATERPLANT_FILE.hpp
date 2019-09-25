#ifndef __WATERPLANT_FILE_HPP__
#define __WATERPLANT_FILE_HPP__
#include <string>
class WATERPLANT_FILE
{
	public:
		static bool exists(std::string path);
		static void create(std::string path);
		static int	read(std::string path, int offset);
		static void overwrite(std::string path, int offset, const short int data);
};
#endif // !__FILE_HPP__
