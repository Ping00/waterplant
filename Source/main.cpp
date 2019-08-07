#include <iostream>
#include <curses.h>
#include <wiringPi.h>
int main(int argc, char* argv[])
{
	//Allocate Screen Memory
	initscr();
	
	//Change Terminal Resolution
	resizeterm(50, 50);
	
	
	//------
	//Remove all from screen
	clear();
	
	//Make Changes
	//TODO
		
	move(10,10);
	printw("Hello World");
	
	//Render
	refresh();
	
	
	//TEMP GETCH
	getch();
	
	//Free Memory
	endwin();


	return 0;
}
