#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__
#include "../GUI/GUI.hpp"
#include "../Controller/controller.hpp"
class Engine
{
	private:
		bool		m_initialized;
		GUI			m_gui;
		//Controller	m_controller;

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
