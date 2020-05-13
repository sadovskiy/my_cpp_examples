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

int TExplicitCasting::g = 45;

TExplicitCasting::TExplicitCasting():
    i(0)
{
    cout << "i = " << i << endl;
}

TExplicitCasting::TExplicitCasting(const int n):
    i(n)
{
    cout << "i = " << i << endl;
}

TExplicitCasting::~TExplicitCasting()
{

}

void TExplicitCasting::show() const
{
    cout << i << endl;
}

TExplicitCasting::operator int() const
{
    return i;
}

TExplicitCasting::operator double() const
{
    return double(i + 0.3);
}
