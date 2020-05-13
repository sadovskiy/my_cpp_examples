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
 * Программа демонстрирует работу перегрузкой по типу данных
 *
 * Подробнее:
 * https://en.wikipedia.org/wiki/Перегрузка_операторов
 *
 * 
 */

#include "explicit_casting.hpp"

using std::cout;
using std::endl;

int main()
{
    TExplicitCasting f;
    double d = f; // Можно так получить данные, основываясь на типе

    cout << d << endl;
    cout << (double)f << endl; // Или сделать приведение типа

    return 0;
}


