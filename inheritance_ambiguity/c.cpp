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

#include "c.h"

using namespace std;

C::C():
    A(), c(0)
{
	//ctor
}

C::C(const int val_1, const int val_2):
    A(val_1 + 5), c(val_2)
{

}

C::~C()
{
	//dtor
}

C::C(const C& other):
    A(other.c), c(other.c)
{
	//copy ctor
}

void C::show_c() const
{
	cout << "class C" << get_a() << c << endl;
}

int C::get_c() const
{
	return c;
}

void C::set_c(const int val)
{
	c = val;
}
