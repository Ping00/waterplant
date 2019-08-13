#include <iostream>
#include "engine.hpp"
#include "../GUI/GUI.hpp"
#include "../GUI/States/GUI_Startup.hpp"
Engine::Engine()
{
	std::cout << "Constructor called for Engine :> (" << this << ")" << std::endl;
	m_initialized = false;
	m_gui = nullptr;
	m_gui_x = nullptr;
}

Engine::~Engine()
{

}

bool Engine::init()
{
	//Init Engine and subsystems
	

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

}

void Engine::render()
{

}