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

#include "b.h"

using namespace std;

B::B():
    A(), b(0)
{
	//ctor
}

B::B(const int val_1, const int val_2):
    A(val_1), b(val_2)
{

}

B::~B()
{
	//dtor
}

B::B(const B& other):
    A(other.b), b(other.b)
{
	//copy ctor
}

void B::show_b() const
{
	cout << "class B" << get_a() << b << endl;
}

int B::get_b() const
{
	return b;
}

void B::set_b(const int val)
{
	b = val;
}
