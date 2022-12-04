#include <stdio.h>
#include <stdlib.h>

#define _WIN32_WINNT 0x0A00     // ������ ������������ ������� Win10
#include <windows.h>

#include "display.h"

int main()
{
    // ������������� ����� �� �������
    SetDisplay();


    PutPixel(100, 50, 0x0000FF);
    Draw();

    // ������� ����
    while(GetKeyState(VK_ESCAPE) >= 0){
        //RndPixel();
    }
    // ����������� �����
    DeleteDisplay();
    return 0;
}


// ��������� �������� ��������
void RndPixel(){
    FillLBrnd();
    Draw();
}



