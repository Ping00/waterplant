#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__
#include "../../Sensors/SPI/SPI_SENSOR/SPI_SENSOR.hpp"
class MCP3008
{
	private:
		int			m_spi_channel;
		int			m_clock_speed_hz;

		SPI_SENSOR	m_connected_sensors;
		bool		m_used_channel[8];
		
		double		m_sensor_data[8];
	

	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);
		void add_sensor(int channel);
		void remove_sensor(int channel);
};
#endif // !__MCP3008_HPP__
