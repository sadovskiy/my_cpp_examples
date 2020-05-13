/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует работу с передачей массивов как параметров функции
 * через ссылку
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Указатель_(тип_данных)
 * https://ru.wikipedia.org/wiki/Функция_(программирование)
 * https://ru.wikipedia.org/wiki/Параметр_(программирование)
 * https://ru.wikipedia.org/wiki/Массив_(тип_данных)
 * https://en.wikipedia.org/wiki/Subroutine
 *
 * Двумерный массив - это одномерный массив,
 * элементами которого являются одномерные массивы.
 *
 * 
 */

#include <iostream>

using namespace::std;

// Через ссылку обычную переменную
void foo(int &x)
{
    x = 10;
    cout << "x = " << x << "\n";
}

// Через ссылку одномерный массив
void foo_array_1(const size_t sArray, int (&array)[])
{
    cout << "array = ";
    for (size_t i = 0; i < sArray; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Через ссылку двумерного массива
void foo_array_2(const size_t sRow, const size_t sCol, int (&array)[][5])
{
    cout << "\narray_3\n";
    for (size_t i = 0; i < sRow; i++ ) {
        for (size_t j = 0; j < sCol; j++ )
            cout << array[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int y = 1;
    foo(y);
    cout << "y = " << y << endl;


    int array_1[]      = {1, 2, 3};
    int array_2[][5] = {{11, 12, 13, 14, 15},
                        {21, 22, 23, 24, 25}
                        };

    foo_array_1(3, array_1);
    foo_array_2(2, 5, array_2);

    return 0;
}

