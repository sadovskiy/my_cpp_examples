/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример работы с указателем на объект
 *
 * 
 */

#include <iostream>

using namespace std;

class A {
    int num;
public:
    A(): num(0) {}
    ~A() {}
    // Переменную val определяем как ссылку
    void set_num(const int &val) {num = val;}
    void show_num() const {cout << num << endl;}
};

int main()
{
    A obj, *p = 0; // Создание объекта obj и указателя p

    // Прямой доступ к объекту
    obj.set_num(1); // Передача значения num объекту obj
    obj.show_num(); // Вывод значения num на экран

    // Доступ к объекту через указатель
    p = &obj; // Присвоение адреса obj указателю p

    p->show_num(); // Вывод значения num на экран через указатель
    p->set_num(5); // Передача значения num объекту obj

    obj.show_num(); // Вывод значения num на экран

    return 0;
}
