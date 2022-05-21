/*
 * Copyright (C) 2021. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2021. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример привидения типа const_cast
 *
 *
 */

#include <iostream>

using namespace std;

const int *f1();


int main()
{
    int n = 10;
    const int m = 6;

    // Временно делаем переменную n const
//    const_cast<const int&>(n) = 0; // и поскольку она тут константа,
                                   // то происходит ошибка на "= 0"

    // Временно снимаем с переменной m const
    const_cast<int&>(m) = 3; // и поскольку она тут неконстанта, то всё работает

    // Далее всё возврашается как было
    n = 3; // Работает
//    m = 8; // Ошибка

    cout.fill('-');
    cout.width(20);
    cout << '\n';
    cout << "n: " << n << "\n"
         << "m: " << m << endl;


//    int *p = f1(); // Ошибка, так как f1() возвращает const
    int *p = const_cast<int*>(f1()); // Допускается, так как f1() возвращает const

    cout.width(20);
    cout << '\n';
    cout << "*p: " << *p << endl;

    *p = 4;

    cout << "*p: " << *p << endl;

    delete p;

    return 0;
}

const int *f1()
{
    int *pNew = new int(100);

    return pNew;
}
