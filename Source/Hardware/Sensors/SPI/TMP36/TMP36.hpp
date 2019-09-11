#ifndef __TMP36_HPP__
#define __TMP36_HPP__
#include <thread>
#include <shared_mutex>
#include <mutex>
class TMP36
{
	private:
		bool					m_initialized;

		std::thread				m_thread;
		int						m_channel;
		int						m_tickrate;

		std::shared_mutex		m_mutex;

		double					m_data;

		double					format		(double data);
		double					poll_sensor	();

	public:
		TMP36();
		~TMP36();

		bool	init			(int channel);
		void	run				();
		void	write			(double data);
		double	read			();

};
#endif // !__TMP36_HPP__
