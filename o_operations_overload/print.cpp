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

// Пример реализаций (определений, англ. defination) функций
// с перегруженным именем
void print(simpleClass *ptr)
{
    simpleClass newObj("world");
    simpleClass twoObj;
    // Воспользуемся перегруженными операциями сложения и присваивания
    twoObj = *ptr + newObj;

    // На самом деле неявно происходит вызов методов определённых в классе
    // Ниже он показан явно
//    twoObj.operator=(ptr->operator+(newObj));

    // Воспользуемся операцией поместить в поток, что бы узнать результат
    // предыдущего оператора
    cout << twoObj;

    // В явном виде эта операция будет иметь вид
//    operator<<(cout, twoObj);
}

void print(int *ptr)
{
    cout << *ptr << endl;
}
