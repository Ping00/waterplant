#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__

class MCP3008
{
	private:
		int			m_spi_channel;
		int			m_clock_speed_hz;
	

	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);
		void add_sensor(int channel);
		void remove_sensor(int channel);
};
#endif // !__MCP3008_HPP__
