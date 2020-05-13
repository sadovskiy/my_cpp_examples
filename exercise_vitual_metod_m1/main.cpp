/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Задача
 * Почему будет вызван метод M1
 *
 * 
 */

#include <iostream>

using namespace std;

class Base1
{
public:
    virtual ~Base1() = default;
    virtual void M1() = 0;
};

class Base2
{
public:
    virtual ~Base2() = default;

    virtual void M2() = 0;
};

class Derived : public Base1, public Base2
{
public:
    void M1() override { cout << "M1" << endl; }
    void M2() override { cout << "M2" << endl; }
};

int main()
{
    Derived d;
    d.M1();
    d.M2();

    Base1* m1 = &d;
    m1->M1();

    Base2* m2 = (Base2*)(m1);
    m2->M2(); // Почему выводит "M1" вместо "M2"?
}
