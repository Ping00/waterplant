#include "TMP36.hpp"
#include <iostream>
TMP36::TMP36()
{

}

TMP36::~TMP36()
{

}

bool TMP36::init(int channel)
{
	m_channel = channel;
	m_thread = std::thread(&TMP36::run, this);
	m_initialized = true;

	return m_initialized;
}

void TMP36::run()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		write();
	}
}

void TMP36::write()
{
	int num = rand();
	std::cout << "TMP36" << std::endl;
}
