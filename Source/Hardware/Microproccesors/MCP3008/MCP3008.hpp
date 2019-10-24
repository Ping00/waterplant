#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__
#include "../../Sensors/SPI/TMP36/TMP36.hpp"
#include "../../Sensors/SPI/SMSM/SMSM.hpp"
#include <shared_mutex>
#include <mutex>
class MCP3008
{
	private:
		bool				m_initialized;

		int                 m_file_descriptor;
		int					m_spi_channel;
		int					m_clock_speed_hz;

		int					m_connected_devices;

		bool				m_spi_active[8];
		//SENSOR			m_sensors[8];

		TMP36				m_tmp36;
		SMSM				m_smsm;



	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);

		double get_data(int channel);

		//bool add_sensor(int channel, SENSOR sensor);
		//void remove_sensor(int channel);

		bool	get_initialized();
		bool	get_channel_sensor_initialized(int channel);
		int		get_channel_sensor_tickrate(int channel);
		void	set_channel_sensor_tickrate(int channel, int tickrate);
};
#endif // !__MCP3008_HPP__
