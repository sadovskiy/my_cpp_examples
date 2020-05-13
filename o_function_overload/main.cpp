/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует простую перегрузку функций на примере
 * операции возведения в степень x^2
 *
 *
 */

#include <iostream>

using namespace std;

// Пример прототипов (объявлений, англ. declare) функций с перегруженным именем
int    sqr(    int i);
int    sqr(  short i);
double sqr( double d);
long   sqr(   long l);
// Возвращаемый тип не влияет на возможность перегрузить имя функции

int main()
{
    // Вызывается самый подходящий из доступных вариантов
    cout << sqr(10)   << "\n";
    cout << sqr(11.5) << "\n";
    cout << sqr(9L)   << "\n";

    return 0;
}

// Пример определений (англ. define) перегруженных функций
int sqr(int i)
{
    return i * i;
}

int sqr(short i)
{
    return i * i;
}

double sqr(double d)
{
    return d * d;
}

long sqr(long l)
{
    return l * l;
}
