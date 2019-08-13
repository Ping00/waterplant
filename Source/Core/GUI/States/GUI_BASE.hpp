#ifndef __GUI_BASE_HPP__
#define __GUI_BASE_HPP__
class GUI_BASE
{
	private:

	public:
		GUI_BASE();
		virtual ~GUI_BASE();

		void init();

		virtual void handle() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
};
#endif // !__GUI_HPP__