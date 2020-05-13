/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 *
 * Демонстрирует работу с шаблонами функции
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Шаблоны_C%2B%2B
 *
 * 
 */

#include <iostream>

using namespace std;

// Функция шаблон по обмене переменых местами
template <typename A_B>
void A_swap(A_B &a, A_B &b)
{
    A_B temp;

    temp = a;
    a    = b;
    b    = temp;
}

int main()
{
    int   i = 10,   j = 20;   // целые
    float x = 10.1, y = 23.3; // дробные
    char  a = 'x',  b = 'z';  // символьные
    // До обмена
    cout << "i, j: " << i << ' ' << j << endl;
    cout << "x, y: " << x << ' ' << y << endl;
    cout << "a, b: " << a << ' ' << b << endl;

    A_swap(i, j);
    A_swap(x, y);
    A_swap(a, b);
    // После обмена
    cout << "i, j: " << i << ' ' << j << endl;
    cout << "x, y: " << x << ' ' << y << endl;
    cout << "i, j: " << a << ' ' << b << endl;

    return 0;
}
