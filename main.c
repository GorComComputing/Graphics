#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0A00     // Версия операционной системы Win10
#include <windows.h>

#include "display.h"

int main()
{
    // Устанавливаем экран на консоль
    SetDisplay();

    //TestPutPixel();
    //LineDDAgl(50, 50, 50, 50);
    //DrawKoch(7, 50, 200, 60, 100);

    Draw();

    float t = 0;



    // Главный цикл
    while(GetKeyState(VK_ESCAPE) >= 0){
        t += 20;
        if(t > 1000) {t = -3.14*12;}
        Flag(100, 100, (int)t);


        //TestLineDDAgl();
        //TestRndPixel();
        Sleep(150);
    }
    // Освобождаем экран
    DeleteDisplay();
    return 0;
}

///////////////////////////////////SET TESTS/////////////////////////////////
// Случайное мерцание пекселов
void TestRndPixel(){
    FillLBrnd();
    Draw();
}


// Тест пиксела
void TestPutPixel(){
    PutPixel(100, 50, 0x0000FF);
    Draw();
}


// Тест заполнения рандом линиями
void TestLineDDAgl(){
    SetColor(rand()%(256*256*256));
    LineDDAgl(rand()%BITMAP_WIDTH, rand()%BITMAP_HEIGHT, rand()%BITMAP_WIDTH, rand()%BITMAP_HEIGHT);
    Draw();
}


// Фрактал Коха
void DrawKoch(int depth, int x1, int y1, int angle, int length){
    SetColor(rand()%(256*256*256));
    if(depth == 0){
        LineDDAgl(x1, y1, (int)(x1+length*cos(angle*(3.14/180))), (int)(y1+length*sin(angle*(3.14/180))));
    }
    else{
        DrawKoch(depth - 1, x1, y1, angle, length/3);

        x1 = (int)(x1+length*cos((angle-60)*(3.14/180)));
        y1 = (int)(y1+length*sin((angle-60)*(3.14/180)));
        DrawKoch(depth - 1, x1, y1, angle - 60, length/3);

        x1 = (int)(x1+length*cos((angle+60)*(3.14/180)));
        y1 = (int)(y1+length*sin((angle+60)*(3.14/180)));
        DrawKoch(depth - 1, x1, y1, angle + 60, length/3);

        x1 = (int)(x1+length*cos((angle)*(3.14/180)));
        y1 = (int)(y1+length*sin((angle)*(3.14/180)));
        DrawKoch(depth - 1, x1, y1, angle, length/3);
    }
    Draw();
}


// Флаг Горячев
void Flag(int x, int y, int t){
    char flag[] = \
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "             ppppppppppp      ppppppp      pppppppppp      pppppppppp    ppp     ppp    ppppppppppp    pppppppppp                "
    "             ppppppppppp    ppppppppppp    ppppppppppp    ppppppppppp    ppp     ppp    ppppppppppp    ppppppppppp               "
    "             ppp            ppp     ppp    ppp     ppp    ppp     ppp    ppp     ppp    ppp            ppp     ppp               "
    "             ppp            ppp     ppp    ppp     ppp    ppp     ppp    ppp     ppp    ppp            ppp     ppp               "
    "             ppp            ppp     ppp    ppp     ppp    ppp     ppp    ppp     ppp    ppppppppppp    pppppppppp                "
    "             ppp            ppp     ppp    ppppppppppp    ppppppppppp    ppp     ppp    ppppppppppp    pppppppppp                "
    "             ppp            ppp     ppp    pppppppppp      pppppppppp     pppppppppp    ppp            ppp     ppp               "
    "             ppp            ppp     ppp    ppp                ppp ppp            ppp    ppp            ppp     ppp               "
    "             ppp            ppppppppppp    ppp              ppp   ppp            ppp    ppppppppppp    ppppppppppp               "
    "             ppp             ppppppppp     ppp            ppp     ppp            ppp    ppppppppppp    pppppppppp                "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    "                                                                                                                                 "
    ;

    //for(var x=0-t; x+t<w; x++){  //-pi*xk
	//	y=yk*Sinus(x/xk);

    int xstart = x;
    int ystart = y;
    int dy = 0;
    SetBackColor(0x000000);
    ClearDevice();
    int sd = rand()%(129);
    for(int i = 0; i < 66; i++){
        for(int j = 0; j < 129; j++){
                if(flag[i*129 + j] == 'p'){
                    PutPixel(x + j, (int)(y + i + 2*sin(j/12.+t)), 0xFFFF00);
                }
                else{
                    PutPixel(x + j, (int)(y + i + 2*sin(j/12.+t)), 0xFF0000);
                }
                x += 2;
                if(x%4 == 0) y++;
        }
        x = xstart;
        dy += 2;
        y = ystart + dy;
    }
    Draw();
}


