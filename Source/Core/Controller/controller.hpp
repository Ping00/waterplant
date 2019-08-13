#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__
class Controller
{
	private:
		bool		m_initialized;

	public:
		Controller();
		~Controller();

		bool init();
};
#endif // !__CONTROLLER_HPP__
