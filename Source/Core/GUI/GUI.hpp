#ifndef __GUI_HPP__
#define __GUI_HPP__
class GUI
{
	private:
		std::unique_ptr<GUI>	m_gui;

	public:
		GUI();
		~GUI();

		void init();

		void handle();
		void update();
		void render();
};
#endif // !__GUI_HPP__
