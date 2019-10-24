#ifndef __SMSM_HPP__
#define __SMSM_HPP__
#include "../SPI_SENSOR/SPI_SENSOR.hpp"
#include "../../../../Utilities/FILE_DATA_POSITIONS.hpp"
#include "../../../../Utilities/WATERPLANT_FILE.hpp"
class SMSM : public SPI_SENSOR
{
	private:
		virtual double	format(double data);
		virtual void	load_settings(std::string path);

	public:
		SMSM();
		~SMSM();
};
#endif // !__SHM_HPP__
