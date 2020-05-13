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
 * Демонстрирует работу с шаблонами
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Шаблоны_C%2B%2B
 *
 * 
 */

#ifndef A_H
#define A_H

#include <iostream>

template <typename Type>
class A
{
    Type n;
public:
    A();
    explicit A(const Type l_n);
    ~A();

    void show() const;
};

// У шаблонов тело функции всегда должно располагаться в том же файле,
// что и класс
template <typename Type>
A<Type>::A():
    n(0)
{
    //ctor
}

template<typename Type>
A<Type>::A(const Type l_n):
    n(l_n)
{

}

template <typename Type>
A<Type>::~A()
{
    //dtor
}

template<typename Type>
void A<Type>::show() const
{
    std::cout << n << std::endl;
}

#endif // A_H
