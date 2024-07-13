#include "util.h"



void init() {
    system("mode con cols=56 lines=20 ");

    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0; // false�Ǵ� 0 : ����� 
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
    
}

// Ŀ�� ��ġ �̵��Լ�
void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

//ù��°: �ؽ�Ʈ, �ι�° : ���
void setColor(int forground, int background) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
    int code = forground + background * 16;
    SetConsoleTextAttribute(consoleHandle, code);
}