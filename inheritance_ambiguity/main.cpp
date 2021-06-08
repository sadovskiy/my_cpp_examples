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
#include "b.h"
#include "c.h"
#include "d.h"
#include "e.h"

// Что бы было видно разницу в конструкторе класса C добалено значение 5

using namespace std;

int main()
{
    A *ptr1 = nullptr;
    A *ptr2 = nullptr;
	A a(1);

	D d(1, 2, 3);

    cout << "show_d()" << endl;
	d.show_d();
    ptr1 = dynamic_cast<B *>(&d); // требуется определить класс
    cout << "show_a() through B" << endl;
    if (ptr1 != nullptr)
        ptr1->show_a();

    ptr2 = dynamic_cast<C *>(&d); // требуется определить класс
    cout << "show_a() through C" << endl;
    if (ptr2 != nullptr)
        ptr2->show_a();

    return 0;
}
