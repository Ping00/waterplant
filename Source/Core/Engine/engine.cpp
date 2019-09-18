#include <iostream>
#include "engine.hpp"
#include "../GUI/GUI.hpp"
#include "../GUI/States/GUI_Startup.hpp"
#include "../../Utilities/WATERPLANT_FILE.hpp"
#include <fstream>
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
	//Check if there exists a settings file, if no, create one with defaults, if yes do nothing
	/*
	if(!FILE::Exists("waterplant_settings.data"))
	{
		FILE::Create("waterplant_settings.data",DEFAULT);
	}
	*/
	if (!WATERPLANT_FILE::exists("waterplant_settings.data"))
	{
		std::cout << "NO FILE EXISTS!!!!!" << std::endl;
		WATERPLANT_FILE::create("waterplant_settings.data");
	}

	//
	m_gui.init();
	m_controller.init();

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
	m_gui.update(m_controller);
}

void Engine::render()
{
	m_gui.render();
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
}