#include <iostream>
#include "engine.hpp"
#include "../GUI/GUI.hpp"
#include "../GUI/States/GUI_Startup.hpp"
Engine::Engine()
{
	//std::cout << "Constructor called for Engine :> (" << this << ")" << std::endl;
	m_initialized = false;
}

Engine::~Engine()
{
	//std::cout << "Destructor called for Engine :> (" << this << ")" << std::endl;
}

bool Engine::init()
{
	//Init Engine and subsystems
	m_gui.init();
	//m_controller.init();

	m_initialized = true;
	return m_initialized;
}

bool Engine::running()
{
	return m_initialized;
}

void Engine::handle()
{
	m_gui.handle();
}

void Engine::update()
{
	m_gui.update();
}

void Engine::render()
{
	m_gui.render();
}