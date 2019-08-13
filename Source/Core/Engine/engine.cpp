#include <iostream>
#include "engine.hpp"
#include "../GUI/GUI.hpp"
#include "../GUI/States/GUI_Startup.hpp"
#include "../GUI/States/GUI_Overview.hpp"
Engine::Engine()
{
	//std::cout << "Constructor called for Engine :> (" << this << ")" << std::endl;
	m_initialized = false;
	m_gui = nullptr;
}

Engine::~Engine()
{
	//std::cout << "Destructor called for Engine :> (" << this << ")" << std::endl;
}

bool Engine::init()
{
	//Init Engine and subsystems
	//Assign GUI to startup
	m_gui = std::make_unique<GUI_Startup>();


	m_initialized = true;
	return m_initialized;
}

bool Engine::running()
{
	return m_initialized;
}

void Engine::handle()
{
	m_gui.get()->handle();
}

void Engine::update()
{
	m_gui.get()->update();
}

void Engine::render()
{
	m_gui.get()->render();
}