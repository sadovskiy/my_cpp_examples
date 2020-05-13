/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует работу конструкторов/деструкторов,
 * механизма наследования, переопределённых функций, виртуальных функций
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Конструктор_(объектно-ориентированное_программирование)
 * https://ru.wikipedia.org/wiki/Деструктор
 * https://ru.wikipedia.org/wiki/Наследование_(программирование)
 * https://ru.wikipedia.org/wiki/Виртуальное_наследование
 * https://ru.wikipedia.org/wiki/Правило_трёх_(C%2B%2B)
 * https://ru.wikipedia.org/wiki/Переопределение_метода
 *
 * 
 */

#include <iostream>

using namespace std;

class A
{
    int a;
public:
    A(): a(0) {}
    A(int n): a(n) {cout << "Ctor A " << a << endl;}
    virtual ~A(){cout << "Dtor A " << a << endl;}

    // Обычные функции с уникальными именами будут доступны всем наследникам
    void setA(const int n) {a = n;}
    int  getA() const {return a;}
    void showA() {cout << "class A" << "\n" << "a = " << a << endl;}

    // Функция show() в базовом классе объявлена, как виртуальная
    virtual void show() {cout << "class A show() base" << "\n"
                              << "a = " << a << endl;}
};

class B: public A
{
    int b;
public:
    B(): A(), b(0) {} // Передача аргумента в вышестоящий класс
    B(int n): A(n + 10), b(n) {cout << "Ctor B " << b << endl;}
    virtual ~B(){cout << "Dtor B " << b << endl;}

    void setB(const int n) {b = n;}
    int  getB() const {return b;}
    void showB() {cout << "class B" << "\n" << "b = " << b << endl;}

    // Переопределённый метод
    void show() override {cout << "class B - show() override" << "\n"
                               << "b = " << b << endl;}
};

class C: public A
{
    int c;
public:
    C(): A(), c(0) {} // Передача аргумента в вышестоящий класс
    C(int n): A(n + 20), c(n) {cout << "Ctor C " << c << endl;}
    virtual ~C(){cout << "Dtor C " << c << endl;}

    void setC(const int n) {c = n;}
    int  getC() const {return c;}
    void showB() {cout << "class C" << "\n" << "c = " << c << endl;}

    // Переопределённый метод
    void show() override {cout << "class C - show() override" << "\n"
                               << "c = " << c << endl;}
};

int main()
{
    A *ptr[3]; // Создание массива указателей типа A

    // Тут будут вызываться конструкторы
    A a(1); // Базовый класс не АБС, значит можно делать по нему объекты
    cout << "-------------" << endl;
    B b(2);
    C c(4);

    // В массиве указателей можно хранить любой объект потомок
    ptr[0] = &a;
    ptr[1] = &b;
    ptr[2] = &c;
    cout << "-------------" << endl;
    for (size_t i = 0; i < 3; i++) // Какую переменную вызвать
        ptr[i]->show();         // определяется во время выполнения
    // Если в базовом классе указано,
    // что функция show() виртуальная
    cout << "-------------" << endl;
    // Тут будут вызываться деструкторы
    return 0;
}
