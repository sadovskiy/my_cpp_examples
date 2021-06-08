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

#ifndef E_H
#define E_H

#include "c.h"

class E: public C
{
		int e;
	public:
		E();
		E(const int val_1, const int val_2, const int val_3);
		E(const E& other);
		virtual ~E();
		void show_e() const;
		int get_e() const;
		void set_e(const int val);
};

#endif // E_H
