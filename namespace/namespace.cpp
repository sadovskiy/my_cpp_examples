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

// Примеры использования объявления using, для использования в программе
// стандартных объектов cout и endl
using std::cout;
using std::endl;
// Использование объявления using позволяет не использовать
// всю библиотеку std, а только нужные в данный момент сущности

namespace myCode
{
// Функция, которую видно только из данного пространства
void foo()
{
    cout << "function foo()" << endl;
}

int i;
}

namespace someoneElsesCode
{
// Функция с именем, которое уже есть, но в другом пространстве,
// а по этому не происходит конфликта
void foo()
{
    cout << "function foo()" << endl;
}

int i;
}
