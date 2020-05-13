/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует простую перегрузку (англ. overload) операций
 * в классе, таких как присваивание, поместить в поток и сложение
 *
 *
 */

#ifndef PRINT_HPP_INCLUDED
#define PRINT_HPP_INCLUDED

#include "simpleclass.hpp"

// Пример прототипов (объявлений, англ. declaration) функций
// с перегруженным именем
void print(simpleClass *ptr);
void print(int *ptr);

#endif // PRINT_HPP_INCLUDED
