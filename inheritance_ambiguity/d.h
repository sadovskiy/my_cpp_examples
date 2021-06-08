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
 */

#ifndef D_H
#define D_H

#include "b.h"
#include "c.h"

class D: public B, public C
{
		int d;
	public:
		D();
		D(const int val_1, const int val_2, const int val_3);
		D(const D& other);
		virtual ~D();
		void show_d() const;
		int get_d() const;
		void set_d(const int val);
};

#endif // D_H
