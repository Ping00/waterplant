#ifndef __SMSM_OLD_HPP__
#define __SMSM_OLD_HPP__
#include "../SPI_SENSOR/SPI_SENSOR.hpp"
#include "../../../../Utilities/FILE_DATA_POSITIONS.hpp"
#include "../../../../Utilities/WATERPLANT_FILE.hpp"
class SMSM
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

		//Start the thread
		void	                run();

		//Write the new value to our sensor
		void	write(double data);

	public:
		SMSM();
		~SMSM();

		//Start the sensor
		bool	init(int channel);

		//get sensor init status
		bool	get_init();

		//Read the data we have stored
		double	read();

		void load_settings(std::string path);

};
#endif // !__SHM_HPP__
