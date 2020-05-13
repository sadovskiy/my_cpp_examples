/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует простую перегрузку (англ. overload) операций
 * в классе, таких как присваивание, поместить в поток и сложение
 *
 *
 */

#include "print.hpp"

using namespace std;

int main()
{
    simpleClass obj1("Hello");
    int x = 10;

    print(&obj1);
    print(&x);

    return 0;
}
