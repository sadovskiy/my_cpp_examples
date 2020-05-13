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

#ifndef SIMPLECLASS_H
#define SIMPLECLASS_H

#include <string>
#include <iostream>

// Создадим класс с перегруженными операциями. Таким образом
// дадим возможность классу использовать их
class simpleClass
{
    std::string classStr;
public:
    simpleClass();
    simpleClass(const std::string &str);
    ~simpleClass();
    simpleClass(const simpleClass &other);
    // Объявление операции "присвоить"
    simpleClass& operator=(const simpleClass &other);
    // Объявление не входящей в класс операции "поместить в поток"
    // как дружественной
    friend void operator<<(std::ostream &os, const simpleClass &other);
    // Объявление операции "сложить"
    simpleClass operator+(const simpleClass &other);
};

#endif // SIMPLECLASS_H
