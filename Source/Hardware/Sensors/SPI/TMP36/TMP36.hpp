#ifndef __TMP36_HPP__
#define __TMP36_HPP__
#include <thread>

class TMP36
{
	private:
		bool		m_initialized;

		std::thread	m_thread;
		int			m_channel;

	public:
		TMP36();
		~TMP36();

		bool init(int channel);
		void run();
		void write();

};
#endif // !__TMP36_HPP__
