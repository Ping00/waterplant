#ifndef __SPI_SENSOR_HPP__
#define __SPI_SENSOR_HPP__
#include <thread>
#include <memory>
#include "../../../Microproccesors/MCP3008/MCP3008.hpp"
class SPI_SENSOR
{
	private:
		std::thread						m_thread;
		bool							m_initialized;

		int								m_channel;
		std::shared_ptr<MCP3008>		m_master_mcp3008;
		
		virtual void convert() = 0;

	public:
		SPI_SENSOR();
		virtual ~SPI_SENSOR();

		bool init(int channel, MCP3008 master);
		void run();
		void write();
};
#endif // !__SPI_SENSOR_HPP__
