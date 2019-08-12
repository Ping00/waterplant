#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__
#include "../../Sensors/SPI/TMP36/TMP36.hpp
class MCP3008
{
	private:
		int			m_spi_channel;
		int			m_clock_speed_hz;

		TMP36		m_sensor;
	

	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);
		void add_sensor(int channel);
		void remove_sensor(int channel);
};
#endif // !__MCP3008_HPP__
