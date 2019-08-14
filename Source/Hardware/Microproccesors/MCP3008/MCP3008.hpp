#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__
#include "../../Sensors/SPI/TMP36/TMP36.hpp"
#include <shared_mutex>
#include <mutex>
class MCP3008
{
	private:
		bool		m_initialized;

		int			m_spi_channel;
		int			m_clock_speed_hz;

		TMP36		m_tmp36;
		int			m_data;

		 std::shared_mutex m_mutex;

		//double		m_spi_data[8];
		//SPI_SENSOR	m_spi_sensor[8];
		//bool			m_spi_active[8];
	

	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);
		
		//void add_sensor(int channel);
		//void remove_sensor(int channel);

		int get_data();
		void write(int data);
};
#endif // !__MCP3008_HPP__
