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
 * Программа демонстрирует работу с указателями и автоматической памятью
 * путём размещения в ней вектора или кортежа (одномерный массив)
 * и матрицы (двумерный массив).
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Указатель_(тип_данных)#Адресная_арифметика
 *
 *
 */

#include <iostream>

using namespace std;
int main()
{
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const int row = 2;
    const int col = 5;

    int matrix[][col] = { {1, 2, 3, 4, 5},
                          {6, 7, 8, 9, 10} };

    // Можно узнать сколько одномерный массив занимает в памяти
    size_t size_v_byte = sizeof(vector);
    cout << "Size vector in byte: " << size_v_byte << endl;

    size_t size_v = size_v_byte / sizeof(int);
    cout << "Size vector in elements: " << size_v << endl;

    cout << "Vector after inicialization: ";
    for (size_t i = 0; i < size_v; ++i) {
        cout << vector[i] << " ";
    }
    cout << endl;

    // Можно узнать сколько двумерный массив занимает в памяти
    size_t size_m_byte = sizeof(vector);
    cout << "Size matrix in byte: " << size_m_byte << endl;

    cout << "Matrix after inicialization:\n";
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    // Сделаем указатели на вектор и матрицу
    int *ptr_v = &vector[0]; // или int *ptr_v = vector;


    int *ptr_m = &matrix[0][0]; // или int *ptr_m = matrix[0];

    cout << "Size vector pointer in byte: "  << sizeof(ptr_v) << endl;
    cout << "Size matrix pointer in byte: "  << sizeof(ptr_m) << endl;

    // Выведем вектор используя арифметику указателей
    cout << "Print vector through pointer: ";
    for(size_t i = 0; i < size_v; ++i)
        cout << *(ptr_v + i) << " ";
    cout << endl;

    // Выведем матрицу используя арифметику указателей
    cout << "Print matrix through pointer:\n";
    for(size_t i = 0; i < size_m_byte / sizeof (int); ++i)
        cout << *(ptr_m + i) << " ";

    cout << endl;

    // Изменим часть значений вектора через указатель
    ptr_v[0] = 31;
    ptr_v[1] = 32;
    ptr_v[2] = 33;
    ptr_v[3] = 34;
    ptr_v[4] = 35;

    // Проверим, что значения изменились у вектора
    cout << "Vector after assignment value: ";
    for (size_t i = 0; i < size_v; ++i) {
        cout << vector[i] << " ";
    }
    cout << endl << endl;

    return 0;
}
