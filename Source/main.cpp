#include "engine.hpp"
int main(int argc, char* argv[])
{
	Engine engine;
	engine.init();
	while (engine.running())
	{
		engine.handle();
		engine.update();
		engine.render();
	}
	return 0;
}
