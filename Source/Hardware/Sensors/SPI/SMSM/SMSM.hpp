#ifndef __SMSM_HPP__
#define __SMSM_HPP__
#include "../SPI_SENSOR/SPI_SENSOR.hpp"
class SMSM : public SPI_SENSOR
{
	private:
		virtual double format(double data);

	public:
		SMSM();
		~SMSM();
};
#endif // !__SHM_HPP__
