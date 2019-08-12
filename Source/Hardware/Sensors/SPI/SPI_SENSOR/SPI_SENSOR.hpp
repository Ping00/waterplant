#ifndef __SPI_SENSOR_HPP__
#define __SPI_SENSOR_HPP__
#include <thread>
#include <mutex>
class SPI_SENSOR
{
	private:
		std::mutex		m_mutex;
		std::thread		m_thread;
		bool			m_initialized;
		int				m_channel;

		MCP3008*		m_master_ADC_device;

	public:
		SPI_SENSOR();
		virtual ~SPI_SENSOR();

		bool init(int channel);
		void run();
		void read() = 0;
};
#endif // !__SPI_SENSOR_HPP__
