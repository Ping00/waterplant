#include <iostream>
#include "engine.hpp"
#include "../GUI/GUI.hpp"
#include "../GUI/States/GUI_Startup.hpp"
#include "../GUI/States/GUI_Overview.hpp"
Engine::Engine()
{
	std::cout << "Constructor called for Engine :> (" << this << ")" << std::endl;
	m_initialized = false;
	m_gui = nullptr;
}

Engine::~Engine()
{
	std::cout << "Destructor called for Engine :> (" << this << ")" << std::endl;
}

bool Engine::init()
{
	//Init Engine and subsystems
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

}

void Engine::update()
{
	temp++;
	if (temp == 10) m_gui = std::make_unique<GUI_Overview>();
	if (temp >= 20) m_initialized = false;
}

void Engine::render()
{
	std::cout << "X: " << temp << std::endl;
	std::cout << "Engine (Render)" << std::endl;
	if (m_gui != nullptr)
	{
		m_gui.get()->render();
	}
}