/*
 *
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа рисует окошко с использованием символов псевдографики
 *
 * Работает только в GNU/Linux
 *
 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

void window(const int x,
            const int y,
            const int height,
            const int width,
            const wchar_t *title,
            const wchar_t *message)
{
    // Задаём декоративные элементы окна
    const wchar_t vBorder = L'│';
    const wchar_t hBorder = L'─';
    const wchar_t drBorder = L'┌';
    const wchar_t dlBorder = L'┐';
    const wchar_t urBorder = L'└';
    const wchar_t ulBorder = L'┘';
    int lenTitle = wcslen(title);
    int lenMessage = wcslen(message) + 1;
    int w = width;

    // Перемещаем курсор к нужной точке
    if ((width - 4) < lenTitle)
        return;

    for (int i = 0; i < x; ++i) {
        wcout << L' ';
    }

    for (int i = 0; i < y; ++i) {
        wcout << L'\n';
    }

    // Рисуем верхний левый угол
    wcout << drBorder;

    w = width - lenTitle - 2;

    int hMiddle = width / 2;

    int hMiddleTitle = lenTitle / 2 +  2;

    int hMiddleOffset = hMiddle - hMiddleTitle;

    // Рисуем верхнюю часть рамки а заголовок
    for (int i = 0; i < w; ++i) {
        wcout << hBorder;
        if (i == hMiddleOffset)
            wcout << L" " << title << L" ";
    }

    // Рисуем верхний правый угол
    wcout << dlBorder << endl;

    // Рисуем левую часть рамки и выводим текст сообщения
    for (int i = 0; i < height; i++) {
        wcout << vBorder << L" ";
        wcout << message;
        // Рисуем правую часть рамки
        for (int j = 0; j < width - lenMessage; ++j) {
            wcout << L" ";
        }
        wcout << vBorder << endl;
    }

    // Рисуем нижний левый угол
    wcout << urBorder;
    // Рисуем нижнюю часть рамки
    for (int i = 0; i < width; ++i) {
        wcout << hBorder;
    }

    // Рисуем нижний правый угол
    wcout << ulBorder << endl;
}
