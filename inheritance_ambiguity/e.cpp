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

#include "e.h"

using namespace std;

E::E(): C(), e(0)
{
	//ctor
}

E::E(const int val_1, const int val_2, const int val_3): C(val_1, val_2), e(val_3)
{

}

E::~E()
{
	//dtor
}

E::E(const E& other): C(other.get_a(), other.get_c()), e(other.e)
{
	//copy ctor
}

void E::show_e() const
{
	cout << "class E" << get_a() << get_c() << e << endl;
}

int E::get_e() const
{
	return e;
}

void E::set_e(const int val)
{
	e = val;
}
