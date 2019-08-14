#ifndef __TMP36_HPP__
#define __TMP36_HPP__
#include <thread>
class MCP3008;
class TMP36
{
	private:
		bool		m_initialized;

		std::thread	m_thread;
		int			m_channel;
		int			m_tickrate;

		MCP3008*	m_master;

	public:
		TMP36();
		~TMP36();

		bool init(int channel, MCP3008* master);
		void run();
		void write();

};
#endif // !__TMP36_HPP__
