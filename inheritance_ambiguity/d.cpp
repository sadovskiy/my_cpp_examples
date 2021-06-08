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

#include "d.h"

using namespace std;

D::D():
    B()
  , C()
  , d(0)
{
	//ctor
}

D::D(const int val_1, const int val_2, const int val_3):
    B(val_1, val_2)
  , C(val_1, val_2)
  , d(val_3)
{

}

D::~D()
{
	//dtor
}

D::D(const D& other):
    B()
  , C()
  , d(other.d)
{
	//copy ctor
}

void D::show_d() const
{
    cout << "class D (get_a(" << B::get_a()
         << "), get_c(" << get_c()
         << "), d: " << d << ")" << endl;
}

int D::get_d() const
{
	return d;
}

void D::set_d(const int val)
{
	d = val;
}
