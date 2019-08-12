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
		
		void init();
		void run();
		void fetch();
};
#endif // !__TMP36_HPP__
