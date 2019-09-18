#ifndef __TMP36_HPP__
#define __TMP36_HPP__
#include "../SPI_SENSOR/SPI_SENSOR.hpp"
#include "../../../../Utilities/FILE_DATA_POSITIONS.hpp"
#include "../../../../Utilities/WATERPLANT_FILE.hpp"
class TMP36 : public SPI_SENSOR
{
	private:
		virtual double	format(double data);
		virtual void	load_settings(std::string path);

	public:
		TMP36();
		~TMP36();
};
#endif // !__TMP36_HPP__
