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
 * Программа демонстрирует работу с указателями и динамической памятью
 * путём размещения в ней вектора или кортежа (одномерный массив)
 * и матрицы (двумерный массив).
 * Дополнительно показан перехват исключения bad_alloc
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Указатель_(тип_данных)#Адресная_арифметика
 *
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    const size_t col = 5;
    const size_t row = 2;

    int *ptr_vector = 0;

    int **ptr_matrix = 0;

    try {
        // Создадим вектор в динамической памяти
        // Выделение памяти для указателя целого типа int
        ptr_vector = new int [10];
        // Присвоение значений от 100 до 109
        for ( size_t i = 0; i < 10; i++ ) // Обратимся к элементу
            ptr_vector[i] = 100 + i;    // вектора через индексацию


        // Создадим матрицу в динамической памяти
        int x = 20;
        ptr_matrix = new int *[row];
        for (size_t i = 0; i < row; i++) {
            // Обращение к элементу используя адресную арифметику
            *(ptr_matrix + i) = new int [col];
            // К элементам матрицы можно обращаться используя синтаксис
            // характерный для обращения к автоматической переменной,
            // то есть через индексацию двумерного массива (матрицы)
            // ptr_matrix[i] = new int [col];
        }

        for (size_t i = 0; i < row; i++)
            for (size_t j = 0; j < col; j++ ) {
                // Обращение к переменной через адресную арифметику
                *(*(ptr_matrix + i) +j) = x;
                // Обращение к переменной через индексация двумерного массива
                // ptr_matrix[i][j] = x;
                x++;
            }
    } catch (bad_alloc &mem_error) { // Проверяем на ошибки при выделении памяти
        cout << "Error: memory has not been allocated!" << endl;
        return 1;
    }

    cout << "Dynamic memory vector: ";
    // Выводим вектор на экран
    for ( size_t i = 0; i < 10; i++ )
        cout << ptr_vector[i] << " ";
    cout << endl;

    cout << "Dynamic memory matrix:" << endl;
    // Выводим матрицу на экран
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++ )
            cout << *(*(ptr_matrix + i) +j) << " ";
        cout << "\n";
    }
    cout << endl;

    // Освобождения памяти (удаление вектора)
    delete [] ptr_vector;


    // Так как технически в памяти матрица состоит из нескольких массивов,
    // то процесс удаления состоит из удаления одномерных массивов
    // отвечающих за строки
    for (size_t i = 0; i < row; i++)
        delete [] *(ptr_matrix + i);
    // и за тем удаляем массив указателей на эти строки
    delete [] ptr_matrix;

    return 0;
}
