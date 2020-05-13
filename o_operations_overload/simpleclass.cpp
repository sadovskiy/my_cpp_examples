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

#include "simpleclass.hpp"

// Определения операций
simpleClass::simpleClass():
    classStr()
{
    //ctor
}

simpleClass::simpleClass(const std::string &str):
    classStr(str)
{
    //ctor string
}

simpleClass::~simpleClass()
{
    //dtor
}

simpleClass::simpleClass(const simpleClass &other):
    classStr(other.classStr)
{
    //copy ctor
}

simpleClass& simpleClass::operator=(const simpleClass &rhs)
{
    // Проверим от присваивания объекта самому себе
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    classStr = rhs.classStr;

    return *this;
}

// Не является членом класса simpleClass
void operator<<(std::ostream &os, const simpleClass &other)
{
    os << other.classStr << std::endl;
}

simpleClass simpleClass::operator+(const simpleClass &other)
{
    std::string tempStr = classStr + " " + other.classStr + "!";

    return tempStr;
}
