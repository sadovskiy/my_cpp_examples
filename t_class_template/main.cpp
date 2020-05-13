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
 * Демонстрирует работу с шаблонами класса
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Шаблоны_C%2B%2B
 *
 * 
 */

#include "A.h"

using namespace std;

int main()
{
    // Создание объекта по шаблону A
    A<int> obj(10);

    obj.show();

    return 0;
}
