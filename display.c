// Драйвер дисплея
#include <stdio.h>
#include "display.h"

HDC dc;                   // Контекст вывода

BITMAPINFOHEADER    bih;
PDWORD              pBmp;
HBITMAP             hBmp;
HDC                 hBmpDC;


// Устанавливаем окно вывода
void SetDisplay(){
    system("cls");                      // Очистить консоль
    printf("\e[?25l");                  // Скрыть курсор
    //printf("\e[?25h");                // Показать курсор

    HWND hwnd = GetConsoleWindow();     // Получаем дескриптор консоли
    //HWND hwnd = GetDesktopWindow();   // Получаем дескриптор консоли
    //HWND hwnd = FindWindow(NULL, "Калькулятор");
    dc = GetDC(hwnd);


    memset(&bih, 0, sizeof bih);        // Очищаем заголовок изображения
    bih.biSize          = sizeof bih;   // Заполняем его своими параметрами
    bih.biPlanes        = 1;
    bih.biBitCount      = 8 << 2;       // 32 бита на пиксель
    bih.biCompression   = BI_RGB;       // Простой формат
    bih.biWidth         = BITMAP_WIDTH;
    bih.biHeight        = BITMAP_HEIGHT;
    bih.biSizeImage     = bih.biWidth * bih.biHeight * (1 << 2);

    // Создаём изображение
    hBmp = CreateDIBSection(NULL, (PBITMAPINFO)&bih, DIB_RGB_COLORS, (PVOID *)&pBmp, NULL, NULL);

    // Создаём контекст
    hBmpDC = CreateCompatibleDC(NULL);
    SelectObject(hBmpDC, hBmp);

    // Устанавливаем цвета по умолчанию и очищаем экран
    SetColor(0x000000);
    SetBackColor(0xFFFFFF);
    ClearDevice();
    Draw();
}


// Удаляем контекст вывода
void DeleteDisplay(){
    DeleteDC(hBmpDC);
    DeleteObject(hBmp);
}


// Заполняет видеобуфер
void FillLB(int start, int count, int value){
    for(int i = start; i <= start+count-1; i++){
        pBmp[i] = value;
    }
}


// Заполняет видеобуфер случайно
void FillLBrnd(){
    for(int i = 0; i < SIZE; i++){
        if(pBmp[i] != 1){
            pBmp[i] = rand()%(256*256*256);
        }
    }
}


// Выводит видеобуфер на экран
void Draw(){
    BitBlt(dc, 0, 0, BITMAP_WIDTH, BITMAP_HEIGHT, hBmpDC, 0, 0, SRCCOPY);
}
