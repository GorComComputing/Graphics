#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0A00     // ������ ������������ ������� Win10
#include <windows.h>

#include "display.h"

int main()
{
    // ������������� ����� �� �������
    SetDisplay();

    //TestPutPixel();
    //LineDDAgl(50, 50, 50, 50);
    Draw();


    // ������� ����
    while(GetKeyState(VK_ESCAPE) >= 0){
        //TestLineDDAgl();
        //TestRndPixel();
        Sleep(10);
    }
    // ����������� �����
    DeleteDisplay();
    return 0;
}

///////////////////////////////////SET TESTS/////////////////////////////////
// ��������� �������� ��������
void TestRndPixel(){
    FillLBrnd();
    Draw();
}


// ���� �������
void TestPutPixel(){
    PutPixel(100, 50, 0x0000FF);
    Draw();
}


// ���� ���������� ������ �������
void TestLineDDAgl(){
    SetColor(rand()%(256*256*256));
    LineDDAgl(rand()%BITMAP_WIDTH, rand()%BITMAP_HEIGHT, rand()%BITMAP_WIDTH, rand()%BITMAP_HEIGHT);
    Draw();
}



