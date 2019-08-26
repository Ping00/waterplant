#include "message.hpp"
#include <sstream>
Message::Message()
{
	m_message = "";
	m_message_length = 0;
}

Message::~Message()
{
}

void Message::set_max_length(int length)
{
	m_message_length = length;
}

void Message::set_message(std::string message)
{
	if (m_message_length < message.size())
	{
		m_message = "ERR";
		return;
	}
	else
	{
		int remainder = m_message_length - message.size();
		for (int i = 0; i < remainder; i++)
		{
			message.append(" ");
		}
		m_message = message;
	}
}

void Message::set_message(int message)
{
	std::stringstream ss;
	ss << message;
	set_message(ss.str());
}

std::string Message::get_message()
{
	return m_message;
}
