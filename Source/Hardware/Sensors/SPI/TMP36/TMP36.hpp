#ifndef __TMP36_HPP__
#define __TMP36_HPP__
#include <thread>
class TMP36
{
	private:
		int				m_tickrate;
		std::thread		m_thread;
		bool			m_initialized;

	public:
		TMP36();
		~TMP36();
		
		void init(int m_tickrate, MCP3008& master);
		void run();
		void fetch();
		
		void set_tickerate(int rate);

		void get_tickrate();
		void get_initialized();
};
#endif // !__TMP36_HPP__
