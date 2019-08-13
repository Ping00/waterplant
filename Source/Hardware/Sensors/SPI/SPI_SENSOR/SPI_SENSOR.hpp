#ifndef __SPI_SENSOR_HPP__
#define __SPI_SENSOR_HPP__
#include <thread>
#include <memory>
class SPI_SENSOR
{
	private:
		std::thread						m_thread;
		bool							m_initialized;

		int								m_channel;
		std::shared_ptr<MCP3008>		m_master_mcp3008;

	public:
		SPI_SENSOR();
		virtual ~SPI_SENSOR();

		bool init(int channel);
		void run();
		void read() = 0;
};
#endif // !__SPI_SENSOR_HPP__
