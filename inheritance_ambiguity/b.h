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

#ifndef B_H
#define B_H

#include "a.h"

class B: public A
{
		int b;
	public:
		B();
		B(const int val_1, const int val_2);
		B(const B& other);
		virtual ~B();
		void show_b() const;
		int get_b() const;
		void set_b(const int val);
};

#endif // B_H
