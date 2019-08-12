#ifndef __MCP3008_HPP__
#define __MCP3008_HPP__
class MCP3008
{
	private:
		int	m_pi_channel;
		int m_clock_speed_hz;

	public:
		MCP3008();
		~MCP3008();

		bool init(int channel, int clock);
};
#endif // !__MCP3008_HPP__
