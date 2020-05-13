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
 * Программа демонстрирует работу с указателями, ссылками и динамической памятью
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Пространство_имён
 *
 *
 */

#include <iostream>

using namespace std;

int main()
{
    // Переменная с которой работаем через указатель в автоматической памяти
    int x  = 10;
    int &y = x;
    int &z = y;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    cout << "\n";

    int   a = 20;
    int  *b = &a;
    int **c = &b;
    int *g  = b;
    int **f = 0;


    cout <<   a << endl;
    cout <<  *b << endl;
    cout << **c << endl;
    cout << *g << endl;

    cout << "\n";

    // Простой одномерный массив
    int array[] = {1, 2, 3, 4};
    int *ptr = array; // или int *ptr = &array[0]

    // Вывод на экран через смещение по указателю
    for(size_t i = 0; i < 4; ++i) {
        cout << *(ptr + i) << " ";
    }

    cout << "\n";

    // Вывод на экран через операцию индексации
    for(size_t i = 0; i < 4; ++i) {
        cout << ptr[i] << " ";
    }

    // Переменная с которой работаем через указатель в динамической памяти
    f = new int *[4]; // f - указатель на массив указателей в динамической памяти

    int *kl = new int(10); // Указатель на массив в динамической памяти.
    // Переменные будут заполнены 10.
    int **kd = new int* (kl); // Указатель на указатель на массив
    // в динамической памяти


    cout << "kl = " << *kl << endl;
    cout << "kd = " << **kd << endl;
    **kd = 50; // Перепишем значение через указатель kd на указатель kl на
    // динамическую переменную
    cout << "kl = " << *kl << endl;
    cout << "kd = " << **kd << endl;

    // Очистим динамический выделенную память
    delete [] f;
    delete kl;
    delete kd;

    // Проверки на ошибки при выделении памяти
    // 1. В стиле Си
    int *pa = new int (5);
    if (!pa) {
        cerr << "Error: memory has not been allocated!";
        return EXIT_FAILURE;
    }

    cout << *pa << endl;
    delete pa;

    // 2. С использованием исключений
    int *pb = 0;
    try {
        pb = new int (6);
    } catch (bad_alloc &mem_error) {   // mem_error - это переменная
        cerr << "Error: memory has not been allocated!";
        return EXIT_FAILURE;
    }
    cout << *pb << endl;
    delete pb;

    cout << "\n";

    return 0;
}
