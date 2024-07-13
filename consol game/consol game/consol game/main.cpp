#include "util.h"
#include "game.h"


int main()
{
    init();
   
    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0) {
            //게임시작
            int n = mapListDraw();

            if(n == 0) {
                gLoop(0);
            }else if (n == 1) {
                gLoop(1);
        }
        } else if (menuCode == 1) {
            infoDraw();
        }
        else if (menuCode == 2) {
            return 0;
        }
        system("cls");

    }
    return 0;
}
    





