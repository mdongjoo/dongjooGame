#include "main.h"
#include "util.h"
#ifndef KEY_CODE
#define KEY_CODE

//키보드값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택(스페이스바)

#endif

int keyControl();
void titleDraw();
int menuDraw();
void infoDraw();
int mapListDraw();
void drawMap(int*, int*);
void gLoop(int);
void move(int*, int*, int, int, int*, int* , int*);// x, _x, y , _y , key, openedDoor , playing
void drawUI(int*, int*, int*);






