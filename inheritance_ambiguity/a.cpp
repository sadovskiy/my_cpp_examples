/*
 * Copyright (C) 2021. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует работу механизма наследования 
 * при ромбовидной иерархии классов и использование привидения типа
 * для преодоления неоднозначности
 * 
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Наследование_(программирование)
 * https://ru.wikipedia.org/wiki/Ромбовидное_наследование
 * https://ru.wikipedia.org/wiki/Приведение_типа#Приведения_типов_в_языке_C++
 * https://ru.wikipedia.org/wiki/Dynamic_cast
 *
 * 
 */

#include "a.h"

using namespace std;

A::A(): a(0)
{
	//ctor
}

A::A(const int val): a(val)
{

}

A::~A()
{
	//dtor
}

A::A(const A& other): a(other.a)
{
	//copy ctor
}

void A::show_a() const
{
    cout << "class A: " << a << endl;
}

int A::get_a() const
{
	return a;
}

void A::set_a(const int val)
{
	a = val;
}
