/*
 * Copyright (C) 2021. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2021. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример привидения типа static_cast
 *
 *
 */

#include <iostream>

using namespace std;

void f1(void *v);

int main()
{
    int n = 10;
    double db = 0;
    void *v = nullptr;

    // Проверяет допустимо ли приведение типа. Если допустимо, то приводит.
    db = static_cast<double>(n);
    v = static_cast<void *>(&n);
    auto a = static_cast<int*>(v);

    cout.fill('-');
    cout.width(20);
    cout << '\n';
    cout << "n: " << n << "\n"
         << "m: " << db << "\n"
         << "c: " << *a << endl;

    f1(&n);

    return 0;
}

void f1(void *v)
{
    cout.fill('-');
    cout.width(20);
    cout << '\n';
    // Нельзя воспользоваься
//    cout << "void*: " << *v << endl;

    cout << "from void*: " << *static_cast<int*>(v) << endl;
}
