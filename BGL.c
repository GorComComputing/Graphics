// Графическая библиотека
#include "BGL.h"
#include "display.h"

int CC; // Текущий цвет
int BC; // Цвет заднего фона

int const Black = 0x000000;
int const White = 0xFFFFFF;
int const Red = 0xFF0000;
int const Green = 0x00FF00;
int const Blue = 0x0000FF;
int const Yellow = 0xFFFF00;
int const Magenta = 0xFF00FF;
int const Cyan = 0x00FFFF;


// Устанавливает текущий цвет
void SetColor(int Color){
    CC = Color;
}


// Устанавливает цвет заднего фона
void SetBackColor(int Color){
    BC = Color;
}


// Очистить экран
void ClearDevice(){
    FillLB(0, SIZE, BC);
}


// Точка
void PutPixel(int x, int y, int Color){
    FillLB((BITMAP_WIDTH*(GETMAX_Y-y) + x), 1, Color);
}
