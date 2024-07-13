#include "game.h"
#include "util.h"

int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}

void titleDraw() {
    cout << endl << endl << endl << endl;
    cout << "    #####                                             " << endl;
    cout << "    #    #                 ##                         " << endl;
    cout << "    #     #  ##     ###   #  #      #   ##     ##     " << endl;
    cout << "    #     # #  #  ##   #   ##          #  #   #  #    " << endl;
    cout << "    #    #  #  #   #   #     ###    #  #  #   #  #    " << endl;
    cout << "    ####     ##    #   #   #  #     #   ##     ##     " << endl;
    cout << "                           ###   #  #                 " << endl;
    cout << "                                  ##                  " << endl;
}
int startx, starty;

char tempMap[14][56];
char startMap[14][56];
     char map1[14][56] = { // ���� ��
    // ���� ���ڴ� �� �迭ũ�⿡ ���߾� 56��
    {"1111111111111111111111111111111111111111111111111111111"},
    {"1000000010000000000000000000000000000000000000000000001"},
    {"1000000010000000000000000000000000000000000000000000001"},
    {"1000100010000000000000000000000000000000000000000000001"},
    {"1000100010000000000000000000000000000000000000000000001"},
    {"1000100010000000000000000000000000000000000000000000001"},
    {"1000100010000000000000000000000000000000000000000000001"},
    {"10001000d1111100000000000000000000000000000000000000001"},
    {"1000100000000100000000000000000000000000000000000000001"},
    {"10001000d00k0100000000000000000000000000000000000111111"},
    {"1000100010000100000000000000000000000000000000000100001"},
    {"10s0100011111111111111111111111111111111111111111100q01"},
    {"10001000l0000000000000000000000000000000000000000000001"},
    {"1111111111111111111111111111111111111111111111111111111"}
};
     char map2[14][56] = {//������
         // ���� ���ڴ� �� �迭ũ�⿡ ���߾� 56��
         {"1111111111111111111111111111111111111111111111111111111"},
         {"1000001000100010000000000000000000000000000000000000001"},
         {"1000001010101010000000000000000000000000000000000000001"},
         {"1000101010101011111000000000000000000000000000000000001"},
         {"1000101010001000000000000000000000000000000000000000001"},
         {"1000100010011000000000000000000000000000000000000000001"},
         {"1000111110010000000000000000000000000000000000000000001"},
         {"1000100000010000000000000000000000000000000000000000001"},
         {"1000101111110000000000000000000000000000000000000000001"},
         {"1000101000000000000000000000000000000000000000000000001"},
         {"1000101010000000000000000000000000000000000000000000001"},
         {"10s0101010000000000000000000000000000000000000000000q01"},
         {"1000100000000000000000000000000000000000000000000000001"},
         {"1111111111111111111111111111111111111111111111111111111"}
     };

     
int menuDraw() {
    int x = 24;
    int y = 12;
    gotoxy(x - 2, y);// -2�� >�� ����ؾ��ϱ⶧��
    cout << "> �� �� �� ��" << endl;
    gotoxy(x, y + 1);
    cout << "�� �� �� ��" << endl;
    gotoxy(x, y + 2);
    cout << "  �� ��" << endl;
    while (1) {// ���ѹݺ�
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 12) {
                gotoxy(x - 2, y);
                cout << "  " << endl;
                gotoxy(x - 2, --y);
                cout << ">" << endl;
            }
            break;
        }

        case DOWN: {
            if (y < 14) {
                gotoxy(x - 2, y);
                cout << "  " << endl;
                gotoxy(x - 2, ++y);
                cout << ">";
            }
            break;
        }

        case SUBMIT: {
            return y - 12;
            // y ������ġ�� 12�����Ƿ� y-12�ϸ� 0.1.2 �� ���ڸ� �������ִ�

        }
        }
    }
}

void infoDraw() {
    system("cls");
    cout << endl << endl;
    cout << "                         [���۹�]" << endl << endl;
    cout << "                    �̵� : W, A, S, D        " << endl;
    cout << "                    ���� : �� �� �� �� �� \n\n\n\n\n  " << endl;
    cout << "                    ������ : mdongjoo\n\n" << endl;
    cout << "    �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�...." << endl;

    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}

int mapListDraw() {
    int x = 24; 
    int y = 8;
    system("cls");
    cout<< endl <<endl;
    cout << "                       [�� ����]\n\n" << endl;

    gotoxy(x - 2, y);
    cout<<"> ����"<<endl;
    gotoxy(x, y + 1);
    cout << "�����" << endl;
    gotoxy(x, y + 2);
    cout << "�� ��" << endl;

    while (1) {
        int n = keyControl();
        switch (n) {
            case UP: {
                if (y > 8) { //y�� 8,9,10 ��ŭ�� �̵� 
                    gotoxy(x - 2, y);
                    cout << " " << endl;
                    gotoxy(x - 2, --y);
                    cout << ">" << endl;
                }
                break;
            case DOWN : {
                if (y < 10) {
                    gotoxy(x - 2, y);
                    cout << " " << endl;
                    gotoxy(x - 2, ++y);
                    cout << ">" << endl;
                }
                break;
            }
            case SUBMIT: {
                return y - 8; // ù ���� y=8�̹Ƿ� return ���� 0, 1, 2
            }
        
        }
        
        }
    }
}



void drawMap(int *x, int*y) {
    system("cls");
    int h, w;//���� , ���� 

    for(h=0 ; h < 14 ; h++)
    {
        for (w = 0; w < 56; w++)
        {
            char temp =  tempMap[h][w];
            if (temp == '0') //�����
            {
                setColor(black, black);
                cout << " ";
            }
            else if (temp == '1') // ��
            {
                setColor(white, white);
                cout << "#";
            }
            else if (temp == 's') // �÷��̾�
            {
                *x = w;// �÷��̾� ��ǥ�� ����
                *y = h;
                setColor(cyan, black);
                cout << "@";
            }
            else if (temp== 'q') // ������
            {
                setColor(lightgreen, black);
                cout << "O";
            }
            else if (temp == 'k') //����
            {
                setColor(yellow, black);
                cout << "*";
            }
            else if (temp == 'l') //��� ��
            {
                setColor(brown, black);
                cout << "+";
            }
            else if (temp == 'd') //������ �״� �� 
            {
                setColor(red, red);
                cout << "x"; 
            }
        }
        cout << endl;
    }
    setColor(white, black);// �ٽ� �⺻ �������� ���ƿ��� 
   
}

void gLoop(int mapCode) {
    int x, y;// player�� ��ǥ ���� ���� ���� (x, y)
    int key = 0; // ���� ���� ���� ���� 
    int openedDoor = 0; 
     

    int playing = 1;// 1�̸� ������, 0�̸� �������� 

        // mapNumber �� 0�̸� ����� , 1�̸� ������ , 2�̸� ,,
        if(mapCode == 0) {
            memcpy(tempMap, map1, sizeof(tempMap));
            memcpy(startMap, map1, sizeof(startMap));
        }else if (mapCode == 1) {
            memcpy(tempMap, map2, sizeof(tempMap));
            memcpy(startMap, map2, sizeof(startMap));

        }
    drawMap(&x, &y); // �� ������ ���
    //�ʿ� ��ǥ �����͸� ����
  
     startx = x;
     starty = y;

    // ���ӷ��� 
    while (playing) {
        drawUI(&x, &y, &key);

        switch(keyControl()) {
            case UP:
                move(&x, &y, 0, -1, &key,&openedDoor, &playing);
                break;
            case DOWN:
                move(&x, &y, 0, 1, &key,  &openedDoor,&playing);
                break;
            case RIGHT:
                move(&x, &y, 1, 0, &key, &openedDoor, &playing);
                break;
            case LEFT:
                move(&x, &y, -1, 0, &key, &openedDoor, &playing);
                break;
            case SUBMIT:
                playing = 0; // 0�� �Ǹ� �ݺ� ����
                setColor(white, black);
        }
    }
   
        
    
}

//�÷��̾� ��ǥ�� ������ �Լ� 
//���� ��ǥ (x,y),������ ��ǥ (_x, _y)
void move(int* x, int* y, int _x, int _y, int* key,int* openedDoor, int* playing) {
    //�̵��� ��ġ�� �ִ� �� �迭�� ���� �ӽ� ���� 
    char mapObject = tempMap[*y + _y][*x + _x];
    setColor(white, black); // ���⺻��

    if (mapObject == '0') {
        gotoxy(*x, *y);
        cout << " ";

        setColor(cyan, black);
        gotoxy(*x + _x, *y + _y);
        cout << "@";

        *x += _x;
        *y += _y;
    }
    else if (mapObject == 'k') {
        *key += 1;
        tempMap[*y + _y][*x + _x] = '0';
        gotoxy(*x + _x, *y + _y);
        cout << " ";
    }
    else if (mapObject == 'l') {
        if (*key > 0) {
            *key -= 1;
            *openedDoor += 1;
            tempMap[*y + _y][*x + _x] = '0';
            setColor(white, black);
            gotoxy(*x + _x, *y + _y);
            cout << " ";
        }
    }
    else if (mapObject == 'q') {

        *playing = 0;
        gotoxy(22, 8);
        cout << "Game Clear!";
        Sleep(1500);
    }
    else if (mapObject == 'd') {
        gotoxy(22, 8);
        cout << "Game Over!";
        Sleep(1500);
        gotoxy(22, 8);
        cout << "               ";

        gotoxy(*x, *y);
        cout << " ";

       //�ʸ����� �÷��̾���ġ�� �ٲ��ְ� startx , y�� ���� ���� �ʸ��ٿ� ���� ���谹�� ��ġ , �� ���� ��ġ�� ���� 
        if ( 1 ) {// �ʸ��� ������ ���ָ� ��

            gotoxy(*x, *y);
            cout << " ";

            setColor(cyan, black);
            gotoxy(startx, starty);
            cout << "@";

            if (*openedDoor > 0 ) {
                *key = *openedDoor;
                *openedDoor = 0;
              
                gotoxy(8, 12);
                setColor(brown, black);
                cout << "+";
                tempMap[12][8] = 'l';
                setColor(white, black);
            }

            if (*key > 0) {
                *key = 0; 
                gotoxy(11, 9);
                setColor(yellow, black);
                cout << "*";
                tempMap[9][11] = 'k';
                setColor(white, black);
            }

            
        }
        else if (0) {
             gotoxy(*x, *y);
             cout << " ";

             setColor(cyan, black);
             gotoxy(startx, starty);
             cout << "@";
        }
       
       
        *x = startx;
        *y = starty;

         

        
        
    }
}

void drawUI(int* x, int* y, int* key) {
    
    setColor(white, black);
    gotoxy(3, 16);
    cout << "��ġ :" <<*x<< "," <<*y << " ";
    

    setColor(yellow, black);
    gotoxy(34, 16);
    cout << "���� : " << *key << "�� ";
}

