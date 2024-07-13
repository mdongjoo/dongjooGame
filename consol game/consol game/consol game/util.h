#include "main.h"

void init();
void gotoxy(int, int);

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

 enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif 

void setColor(int, int);

