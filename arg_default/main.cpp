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
 * Программа показывает работу аргументов функции по умолчанию
 * 
 * Подробнее:
 * https://ru.wikipedia.org/wiki/C++
 *
 * 
 */

#include <iostream>

using namespace std;

// Значения для аргументов задаются в прототипе.
// Значения должны идти всегда с последнего аргумента без пропусков
int left(int a, int b = 1, int c = 5010);

int main()
{
    int result = 0;

    // Обычный вызов функции переопределяет переменные по умолчанию
    result = left(5, 6, 7);
    cout << result << endl;

    // Вызов функции где опущены переменные добавит те, которые по умолчанию
    result = left(5);
    cout << result << endl;

    return 0;
}

int left(int a, int b, int c)
{
    return a + b + c;
}
