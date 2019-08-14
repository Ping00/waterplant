#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__
#include <string>
class Message
{
	private:
		int m_message_length;
		std::string m_message;

	public:
		Message();
		~Message();
		
		void set_length(int length);
		void set_message(std::string message);
		void set_message(int message);
		std::string get_message();

};
#endif // !__MESSAGE_HPP__
