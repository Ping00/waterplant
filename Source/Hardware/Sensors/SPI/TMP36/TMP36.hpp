#ifndef __TMP36_HPP__
#define __TMP36_HPP__
#include "../SPI_SENSOR/SPI_SENSOR.hpp"
class TMP36 : public SPI_SENSOR
{
	private:
		virtual double	format(double data);

	public:
		TMP36();
		~TMP36();
};
#endif // !__TMP36_HPP__
