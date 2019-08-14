#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__
#include "../../Sensors/SPI/TMP36/TMP36.hpp"
class MCP3008
{
	private:
		bool		m_initialized;

		int			m_spi_channel;
		int			m_clock_speed_hz;


		//double		m_spi_data[8];
		//SPI_SENSOR	m_spi_sensor[8];
		//bool			m_spi_active[8];
	

	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);
		
		//void add_sensor(int channel);
		//void remove_sensor(int channel);
};
#endif // !__MCP3008_HPP__
