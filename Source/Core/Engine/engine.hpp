#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
class Engine
{
	private:
		//swap to Unique ptr once we have multiple views to swap between
		bool		m_init;

	public:
		Engine();
		~Engine();

		bool init();

		void handle();
		void update();
		void render();
};
#endif // !__ENGINE_HPP__
