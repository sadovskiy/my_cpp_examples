/*
 *
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует работу с пространствами имён
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Пространство_имён
 *
 * 
 */

#ifndef NAMESPACE_H_INCLUDED
#define NAMESPACE_H_INCLUDED

#include <iostream>

namespace myCode {
void foo();
extern int i;
}

namespace someoneElsesCode {
void foo();
extern int i;
}

#endif // NAMESPACE_H_INCLUDED
