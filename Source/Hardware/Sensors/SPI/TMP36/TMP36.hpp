#ifndef __TMP36_HPP__
#define __TMP36_HPP__
#include <thread>
#include <shared_mutex>
#include <mutex>
class TMP36
{
	private:
		//Is the sensor component activated
		bool					m_initialized;

		//Our custom thread which polls the sensor
		std::thread				m_thread;

		//Which channel are we transmitting to in the MCP3008
		int						m_channel;

		//How often we attempt to write new data
		int						m_tickrate;

		//Mutex for sharing data for other sources so we dont corrupt it
		std::shared_mutex		m_mutex;

		//Our data reading
		double					m_data;

		//Convert our millivolt reading into the sensors proper format
		double					format		(double data);

		//Collect data
		double					poll_sensor	();

		//the thread function
		void	run();

		//Write the new value to our sensor
		void	write(double data);

	public:
		TMP36();
		~TMP36();

		//Start the sensor
		bool	init			(int channel);

		//Read the data we have stored
		double	read			();

};
#endif // !__TMP36_HPP__
