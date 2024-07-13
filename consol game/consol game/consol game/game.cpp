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
     char map1[14][56] = { // 쉬운 맵
    // 가로 숫자는 위 배열크기에 맞추어 56개
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
     char map2[14][56] = {//어려운맵
         // 가로 숫자는 위 배열크기에 맞추어 56개
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
    gotoxy(x - 2, y);// -2는 >를 출력해야하기때문
    cout << "> 게 임 시 작" << endl;
    gotoxy(x, y + 1);
    cout << "게 임 정 보" << endl;
    gotoxy(x, y + 2);
    cout << "  종 료" << endl;
    while (1) {// 무한반복
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
            // y 시작위치가 12였으므로 y-12하면 0.1.2 세 숫자를 받을수있다

        }
        }
    }
}

void infoDraw() {
    system("cls");
    cout << endl << endl;
    cout << "                         [조작법]" << endl << endl;
    cout << "                    이동 : W, A, S, D        " << endl;
    cout << "                    선택 : 스 페 이 스 바 \n\n\n\n\n  " << endl;
    cout << "                    개발자 : mdongjoo\n\n" << endl;
    cout << "    스페이스바를 누르면 메인화면으로 이동합니다...." << endl;

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
    cout << "                       [맵 선택]\n\n" << endl;

    gotoxy(x - 2, y);
    cout<<"> 쉬움"<<endl;
    gotoxy(x, y + 1);
    cout << "어려움" << endl;
    gotoxy(x, y + 2);
    cout << "뒤 로" << endl;

    while (1) {
        int n = keyControl();
        switch (n) {
            case UP: {
                if (y > 8) { //y는 8,9,10 만큼만 이동 
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
                return y - 8; // 첫 시작 y=8이므로 return 값은 0, 1, 2
            }
        
        }
        
        }
    }
}



void drawMap(int *x, int*y) {
    system("cls");
    int h, w;//가로 , 세로 

    for(h=0 ; h < 14 ; h++)
    {
        for (w = 0; w < 56; w++)
        {
            char temp =  tempMap[h][w];
            if (temp == '0') //빈공간
            {
                setColor(black, black);
                cout << " ";
            }
            else if (temp == '1') // 벽
            {
                setColor(white, white);
                cout << "#";
            }
            else if (temp == 's') // 플레이어
            {
                *x = w;// 플레이어 좌표값 저장
                *y = h;
                setColor(cyan, black);
                cout << "@";
            }
            else if (temp== 'q') // 도착지
            {
                setColor(lightgreen, black);
                cout << "O";
            }
            else if (temp == 'k') //열쇠
            {
                setColor(yellow, black);
                cout << "*";
            }
            else if (temp == 'l') //잠긴 문
            {
                setColor(brown, black);
                cout << "+";
            }
            else if (temp == 'd') //닿으면 죽는 벽 
            {
                setColor(red, red);
                cout << "x"; 
            }
        }
        cout << endl;
    }
    setColor(white, black);// 다시 기본 색상으로 돌아오기 
   
}

void gLoop(int mapCode) {
    int x, y;// player의 좌표 저장 변수 선언 (x, y)
    int key = 0; // 열쇠 갯수 저장 변수 
    int openedDoor = 0; 
     

    int playing = 1;// 1이면 게임중, 0이면 게임종료 

        // mapNumber 가 0이면 쉬운맵 , 1이면 어려운맨 , 2이면 ,,
        if(mapCode == 0) {
            memcpy(tempMap, map1, sizeof(tempMap));
            memcpy(startMap, map1, sizeof(startMap));
        }else if (mapCode == 1) {
            memcpy(tempMap, map2, sizeof(tempMap));
            memcpy(startMap, map2, sizeof(startMap));

        }
    drawMap(&x, &y); // 맵 설정후 출력
    //맵에 좌표 조인터를 전달
  
     startx = x;
     starty = y;

    // 게임루프 
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
                playing = 0; // 0이 되면 반복 종료
                setColor(white, black);
        }
    }
   
        
    
}

//플레이어 좌표를 조작할 함수 
//원래 좌표 (x,y),증감할 좌표 (_x, _y)
void move(int* x, int* y, int _x, int _y, int* key,int* openedDoor, int* playing) {
    //이동할 위치에 있는 맵 배열의 문자 임시 저장 
    char mapObject = tempMap[*y + _y][*x + _x];
    setColor(white, black); // 색기본값

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

       //맵마다의 플레이어위치로 바꿔주고 startx , y를 통해 그후 맵마다에 따라 열쇠갯수 위치 , 문 갯수 위치를 수정 
        if ( 1 ) {// 맵마다 설정만 해주면 됨

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
    cout << "위치 :" <<*x<< "," <<*y << " ";
    

    setColor(yellow, black);
    gotoxy(34, 16);
    cout << "열쇠 : " << *key << "개 ";
}

