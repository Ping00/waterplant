#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__
#include "../../Sensors/SPI/TMP36/TMP36.hpp"
#include <shared_mutex>
#include <mutex>
class MCP3008
{
	private:
		bool				m_initialized;

		int					m_spi_channel;
		int					m_clock_speed_hz;

		bool				m_spi_active[8];
		//SENSOR			m_sensors[8];
		TMP36				m_tmp36;

	

	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);

		double get_data(int channel);
		
		//void add_sensor(int channel);
		//void remove_sensor(int channel);
};
#endif // !__MCP3008_HPP__
