/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует работу множественного наследования,
 * переопределённых функций, виртуальных функций и ромбовидного наследования
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Наследование_(программирование)
 * https://ru.wikipedia.org/wiki/Множественное_наследование
 * https://ru.wikipedia.org/wiki/Виртуальное_наследование
 * https://ru.wikipedia.org/wiki/Переопределение_метода
 * https://ru.wikipedia.org/wiki/Ромбовидное_наследование
 *
 * 
 */


#include <iostream>

using namespace std;

class A
{ // Класс предок
protected:
    int a;
public:
    A(): a(0){}
    A(const int n): a(n) {}
    virtual ~A() {}
    virtual void make(int i) {a = i;}
    virtual void show() {cout << "a = " << a << endl;}
};

class B : public virtual A
{ // 1-ый класс потомок
protected:
    int b;
public:
    B(): A(), b(0){}
    B(const int n): A(n + 10), b(n) {}
    virtual ~B() {}
    void make(int i) override {b = i;}
    void show() override {A::show();cout << "b = " << b << endl;}
};

class C: public virtual A
{ // 2-ой класс потомок
protected:
    int c;
public:
    C(): c(0){}
    C(const int n): A(n + 20), c(n) {}
    virtual ~C() {}
    void make(int i) override {c = i;}
// При использовании членов A потребуется
// указать путь наследования (B::A или C::A)
    void show() override {A::show();cout << "c = " << c << endl;}
};

// В классе D переопределяется метод make()
class D : public B, public C
{
    int d;
public:
    D(): A(), B(), C(), d(0) {}
    D(const int n): A(n), B(n), C(n), d(n) {}
    virtual ~D(){}
    void make(int i) override {d = i;}
// При использовании членов A потребуется
// указать путь наследования (B::A или C::A)
    void show() override {cout << "d = " << d << endl; B::show();C::show();}
};

int main()
{
    A *ptr = 0;

    A a(1);
    B b(2);
    C c(3);
    D d(4);

    ptr = &a;
    ptr->show();
    cout << "-------------" << endl;
    ptr = &b;
    ptr->show();
    ptr = &c;
    ptr->show();
    cout << "-------------" << endl;
    ptr = &d;
    ptr->show();

    return 0;
}
