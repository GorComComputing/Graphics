// ������� �������
#include <stdio.h>
#include "display.h"

HDC dc;                   // �������� ������

BITMAPINFOHEADER    bih;
PDWORD              pBmp;
HBITMAP             hBmp;
HDC                 hBmpDC;


// ������������� ���� ������
void SetDisplay(){
    system("cls");                      // �������� �������
    printf("\e[?25l");                  // ������ ������
    //printf("\e[?25h");                // �������� ������

    HWND hwnd = GetConsoleWindow();     // �������� ���������� �������
    //HWND hwnd = GetDesktopWindow();   // �������� ���������� �������
    //HWND hwnd = FindWindow(NULL, "�����������");
    dc = GetDC(hwnd);


    memset(&bih, 0, sizeof bih);        // ������� ��������� �����������
    bih.biSize          = sizeof bih;   // ��������� ��� ������ �����������
    bih.biPlanes        = 1;
    bih.biBitCount      = 8 << 2;       // 32 ���� �� �������
    bih.biCompression   = BI_RGB;       // ������� ������
    bih.biWidth         = BITMAP_WIDTH;
    bih.biHeight        = BITMAP_HEIGHT;
    bih.biSizeImage     = bih.biWidth * bih.biHeight * (1 << 2);

    // ������ �����������
    hBmp = CreateDIBSection(NULL, (PBITMAPINFO)&bih, DIB_RGB_COLORS, (PVOID *)&pBmp, NULL, NULL);

    // ������ ��������
    hBmpDC = CreateCompatibleDC(NULL);
    SelectObject(hBmpDC, hBmp);

    // ������������� ����� �� ��������� � ������� �����
    SetColor(0x000000);
    SetBackColor(0xFFFFFF);
    ClearDevice();
    Draw();
}


// ������� �������� ������
void DeleteDisplay(){
    DeleteDC(hBmpDC);
    DeleteObject(hBmp);
}


// ��������� ����������
void FillLB(int start, int count, int value){
    for(int i = start; i <= start+count-1; i++){
        pBmp[i] = value;
    }
}


// ��������� ���������� ��������
void FillLBrnd(){
    for(int i = 0; i < SIZE; i++){
        if(pBmp[i] != 1){
            pBmp[i] = rand()%(256*256*256);
        }
    }
}


// ������� ���������� �� �����
void Draw(){
    BitBlt(dc, 0, 0, BITMAP_WIDTH, BITMAP_HEIGHT, hBmpDC, 0, 0, SRCCOPY);
}
