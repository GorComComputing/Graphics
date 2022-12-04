#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0A00     // Версия операционной системы Win10
#include <windows.h>

#include "display.h"

int main()
{
    // Устанавливаем экран на консоль
    SetDisplay();


    PutPixel(100, 50, 0x0000FF);
    Draw();

    // Главный цикл
    while(GetKeyState(VK_ESCAPE) >= 0){
        //RndPixel();
    }
    // Освобождаем экран
    DeleteDisplay();
    return 0;
}


// Случайное мерцание пекселов
void RndPixel(){
    FillLBrnd();
    Draw();
}



