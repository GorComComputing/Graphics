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
    Draw();


    // Главный цикл
    while(GetKeyState(VK_ESCAPE) >= 0){
        //TestLineDDAgl();
        //TestRndPixel();
        Sleep(10);
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



