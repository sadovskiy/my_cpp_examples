/*
 * Copyright (C) 2021. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример работы с ключевым словом auto, циклом for_each и лямбда-функцией.
 *
 * Цикл foreach и for_each нужны для перебора значений в различных контейнерах,
 * в том числе массивах. В C++ нет циклов с таким названием,
 * вместо этого используется обычный for, но с другим синтаксисом
 * for (type element : container) {}.
 * Следует заметить, что в C++ stl есть алгоритм for_each()
 *
 */

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Sum
{
public:
    void operator()(int n) { mSum += n; }
    int mSum{0};
};

int main()
{
    // Создадим массив целых чисел
    int array[] = {8, 2, 7, 9, 1, 5, 3, 0, 4, 5};

    // Стандартный способ обхода контейнера array
//    for (int i = 0; i < 10; ++i) {
//        cout << array[i] << " ";
//    }

    // Пример использования вывода типа auto
    // для определения типа данных переменной m
    auto m = array[0];

    // Контрольный вывод переменной m
    cout << "Auto type: " << m << endl;

    cout << "Array:  ";
    // В C++ нет циклов for_each (foreach).
    // Вместо этого используется for специального вида.
    // Ниже приведён пример.
    // Вывод на экран содержимого массива array по элементам element
//    for (int element: array) {
//        cout << element << " ";
//    }
    // или лучшая практика с использованием вывода типа auto,
    // который позволяет не думать о типе элемента контейнера
//    for (auto element: array) {
//        cout << element << " ";
//    }
//    cout << endl;

    // Ещё вариант для повышения производительности, где можно использовать
    // передачу по ссылке
    for (const auto &element: array) {
        cout << element << " ";
    }
    cout << endl;

    // Теперь создадим векторный контейнер целых чисел
    vector<int> arrayV{8, 2, 7, 9, 1, 5, 3, 0, 4, 5};

    cout << "Vector: ";
    // Выведем его на экран
    for (const auto &element: arrayV) {
        cout << element << " ";
    }
    cout << endl;

    cout << "for_each print: ";
    // С помощью алгоритма for_each()
    for_each(arrayV.begin(), arrayV.end(), [](const auto& n){cout << n << " ";});
    cout << endl;

    // Делаем контрольный подсчёт суммы элементов вектора
    // через алгоритм accumulate()
    cout << "Accumulate: " << accumulate(arrayV.begin(), arrayV.end(), 0) << endl;

    // Вычислим сумму используя анонимная лямбда-функцию и алгоритм for_each
    // Через лямбда-функцию [внешние переменные](аргументы){операторы;}
    int sumLambda = 0;
    for_each(arrayV.begin(), arrayV.end(), [&sumLambda](const auto &n){ sumLambda += n; });

    // или через функтор Sum() класса Sum
    Sum sumF = for_each(arrayV.begin(), arrayV.end(), Sum());

    cout << "Lambda sum: " << sumLambda << endl;
    cout << "Functor sum: " << sumF.mSum << endl;

    return 0;
}
