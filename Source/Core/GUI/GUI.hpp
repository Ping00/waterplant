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

		virtual void handle();
		virtual void update();
		virtual void render();
};
#endif // !__GUI_HPP__
