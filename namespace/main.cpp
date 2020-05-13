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
 * Программа демонстрирует работу с пространствами имён
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Пространство_имён
 *
 * 
 */

#include "namespace.h"

// Воспользуемся решениями стандартной бибилотеки std через директиву using
using namespace std;

int main()
{
    // Воспользуемся функцией из этого пространства локально
    myCode::foo();

    // Воспользуемся переменной i через объявление using
    using myCode::i;


    for(i = 0; i < 10; i++)
        cout << i << " ";

    cout << endl;

    return 0;
}
