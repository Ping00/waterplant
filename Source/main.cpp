#include <iostream>
#include <curses.h>
#include <wiringPi.h>
#include <sstream>
#include <string>
int main(int argc, char* argv[])
{
	//Allocate Screen Memory
	initscr();

	//Change Terminal Resolution
	resizeterm(50, 50);

	int num = 0;

	//------
	//Make Changes
	//TODO

	while(true)
    {
        //HANDLE STEP

        //Update step
        num++;

        std::stringstream ss;
        ss << num;
        std::string str = ss.str();

        //RENDER STEP

        //Clear screen from old clutter
        move(10,10);
        printw("Hello World");

        clear();

        //Render relevant parts

        move(12,12);
        printw(str.c_str());

        //Render
        refresh();

    }
	//Free Memory
	endwin();


	return 0;
}
