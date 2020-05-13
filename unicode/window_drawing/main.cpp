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
#include <locale>

#include "window.hpp"

using namespace std;

int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif
    // Рисуем окно
    window(6, 6,
           1, 20,
           L"Dialog",
           L"Hello World!");

    wcout << endl;

    return 0;
}

