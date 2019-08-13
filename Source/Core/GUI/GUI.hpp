#ifndef __GUI_HPP__
#define __GUI_HPP__
class GUI
{
	private:

	public:
		GUI();
		virtual ~GUI();

		virtual void handle() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
};
#endif // !__GUI_HPP__
