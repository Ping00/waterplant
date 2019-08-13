#ifndef __GUI_HPP__
#define __GUI_HPP__
class GUI
{
	private:
		bool					m_initialized;
		std::unique_ptr<GUI>	m_gui;

	public:
		GUI();
		~GUI();

		bool init();

		void handle();
		void update();
		void render();
};
#endif // !__GUI_HPP__
