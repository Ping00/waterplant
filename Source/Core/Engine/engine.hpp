#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
#include <memory>
#include "../GUI/GUI.hpp"
class Engine
{
	private:
		//swap to Unique ptr once we have multiple views to swap between
		bool		m_initialized;
		GUI			m_gui;

		//Controller

		int temp = 0;

	public:
		Engine();
		~Engine();

		bool init();
		bool running();

		void handle();
		void update();
		void render();
};
#endif // !__ENGINE_HPP__
