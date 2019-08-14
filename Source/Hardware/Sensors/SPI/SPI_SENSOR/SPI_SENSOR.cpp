#include "SPI_SENSOR.hpp"
SPI_SENSOR::SPI_SENSOR()
{

}

SPI_SENSOR::~SPI_SENSOR()
{

}

bool SPI_SENSOR::init(int channel)
{
	return m_initialized;
}

void SPI_SENSOR::run()
{
	while (true)
	{
		write();
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
}

void SPI_SENSOR::write()
{

}
