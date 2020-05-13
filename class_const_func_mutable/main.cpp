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
 * Программа демонстрирует работу с константами и классом
 *
 * Подробнее:
 * https://en.wikipedia.org/wiki/Константа_(программирование)
 * https://habr.com/ru/company/infopulse/blog/341264
 *
 * 
 */

#include <iostream>

using namespace std;


class A
{
    int n;
public:
    A(): n(0) {}
    explicit A(const int m): n(m) {}
    void set(const int m) {n = m;} // const после заголовка метода запрещает
    int get() const {return n;}    // методу переписывать переменную n
};

class B
{
    int n;
public:
    B(): n(0) {}
    explicit B(const int m): n(m) {}
    void set(const int m) {n = m;}
    int get() const { return n;}
};

class C
{
    int n;
    mutable int m; // Для переменной m в этом классе делается исключение.
public:                     // Её менять можно
    C(): n(0), m(0) {}
    C(const int ln,
      const int lm): n(ln), m(lm) {}

    void set_n(const int ln) {n = ln;}
    void modification() const {m = 8;}
    int get_n() const {return n;}

    void set_m(const int lm) {m = lm;}
    int get_m() const {return m;}

    void show() const {cout << "n = " << n << endl;
                       cout << "m = " << m << endl;}
};

int main()
{
    A a(5);

    a.set(4);

    B b(6);
    const C c(10, 25);

    c.show();

    c.modification();
    c.show(); // У m новое значение, не смотря на то, что c константа
                // Это возможно за счёт mutable

    cout << "get_m() = " << c.get_m() << endl;

    return 0;
}
