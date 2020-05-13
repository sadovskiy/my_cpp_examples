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
 * Программа позволяет узнать размер в байтах типа char в Си++
 * 
 * Подробнее:
 * https://ru.wikipedia.org/wiki/C++#Типы
 *
 * 
 */

#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    // Посмотрим размеры типов и констант в Си++
    cout << "size const character: " << sizeof('F') << endl;
    cout << "size char: " << sizeof(char) << endl;

    return 0;
}

