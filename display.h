#ifndef DISPLAY_H
#define DISPLAY_H

#define _WIN32_WINNT 0x0A00     // Версия операционной системы Win10
#include <windows.h>

#define BITMAP_WIDTH 960    // Размеры экрана
#define BITMAP_HEIGHT 480
#define SIZE BITMAP_WIDTH*BITMAP_HEIGHT  // Размер видеобуфера
#define GETMAX_X BITMAP_WIDTH - 1 // Координаты последней точки
#define GETMAX_Y BITMAP_HEIGHT - 1

#endif // DISPLAY_H
