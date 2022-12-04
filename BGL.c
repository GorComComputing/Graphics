// Графическая библиотека
//#include <math.h>

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


// Линия ЦДА
void LineDDAgl(int x1, int y1, int x2, int y2){
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    if(dx > dy){
        float k = (float)(y2-y1)/(float)(x2-x1);
        int x;
        int xend;
        float yf;
        if(x1 < x2){
            x = x1;
            xend = x2;
            yf = y1;
        }
        else {
            x = x2;
            xend = x1;
            yf = y2;
        }
        PutPixel(x, (int)roundf(yf), CC);
        while(x < xend){
            x++;
            yf += k;
            PutPixel(x, (int)roundf(yf), CC);
        }
    }
    else if(dy > 0){
        float k = (float)(x2-x1)/(float)(y2-y1);
        int y;
        int yend;
        float xf;
        if(y1 < y2){
            y = y1;
            yend = y2;
            xf = x1;
        }
        else {
            y = y2;
            yend = y1;
            xf = x2;
        }
        PutPixel((int)roundf(xf), y, CC);
        while(y < yend){
            y++;
            xf += k;
            PutPixel((int)roundf(xf), y, CC);
        }
    }
    else{
        PutPixel(x1, y1, CC);
    }
}
