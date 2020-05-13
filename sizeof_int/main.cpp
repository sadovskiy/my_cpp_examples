/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа выводит максимальные значения типов данных в Си++
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Система_типов_Си
 * https://ru.wikipedia.org/wiki/C%2B%2B#Типы
 *
 * 
 */

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    // Получаем значение констант
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_long_long = LLONG_MAX;

    // Посмотрим их размеры
    cout << "int is " << sizeof (int) << " bytes." << endl;
    cout << "short is " << sizeof (n_short) << " bytes." <<endl;
    cout << "long is " << sizeof (n_long) << " bytes." << endl;
    cout << "long long is " << sizeof (n_long_long) << " bytes." << endl << endl;
    
    // Посмотрим максимальные значения
    cout << "Max values: " << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_long_long << endl;
    cout << "minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;

	return 0;
}
