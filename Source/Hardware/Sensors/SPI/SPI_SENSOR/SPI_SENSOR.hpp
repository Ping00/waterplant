#ifndef __SPI_SENSOR_HPP__
#define __SPI_SENSOR_HPP__
#include <thread>
#include <shared_mutex>
#include <mutex>
#include <string>
class SPI_SENSOR
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
		std::shared_mutex		m_mutex_data;
		std::shared_mutex		m_mutex_tickrate;

		//Our data reading
		double					m_data;

		//Convert our millivolt reading into the sensors proper format
		virtual double	format(double data) = 0;
		virtual void	load_settings(std::string path) = 0;


		//Collect data
		double	poll_sensor();

		//Start the thread
		void	run();

		//Write the new value to our sensor
		void	write(double data);


	public:
		SPI_SENSOR();
		virtual ~SPI_SENSOR();

		//Start the sensor
		bool	init(int channel);
		bool	get_init();

		//Set tickrate
		int		get_tickrate();
		void	set_tickrate(int ms);

		//Read the data we have stored
		double	read();
};
#endif // !__SPI_SENSOR_HPP__
