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
 * Программа демонстрирует работу перегрузкой по типу данных
 *
 * Подробнее:
 * https://en.wikipedia.org/wiki/Перегрузка_операторов
 *
 * 
 */

#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

class TExplicitCasting
{
    int i;
    static int g;
public:
    TExplicitCasting();
    explicit TExplicitCasting(const int n);
    ~TExplicitCasting();

    operator int() const;
    operator double() const;
    void show() const;
};

#endif
