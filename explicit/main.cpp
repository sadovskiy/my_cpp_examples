/*
 * Copyright (C) 2022. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример работы неявного приведения типов и
 * использования ключевого слова explicit
 *
 *
 */

#include <iostream>
#include <string>

using namespace std;

class TObject
{
    string mStr;
public:
    TObject(): mStr() {}
    explicit TObject(const char *lStr): mStr(lStr) {}

    // Метод для вставки строки
    void setStr(const string &newStr) {mStr = newStr;}
    // Метод для извлечения (копирования) строки
    const string &str() const {return mStr;}
    // тоже самое через перегрузку преобразования в тип string
    operator string() const { return mStr; }

    // Пример для возврата по типу bool
    operator bool() const { return true; }
};

int main()
{
    // При таком варианте неявного приведения типа нет
    // и этот код работает нормально в любом случае
    TObject obj("Hello World!");
    // А при таком варианте неявное приведение типа есть и код не будет работать,
    // если перед конструктором будет стоять ключевое слово explicit
//    TObject obj = "Hello World!";

    // Неявное приведение типа за счёт перегруженной
    // операции преобразования в тип
    string str = obj;
    bool a = obj;

    cout << "String: " << str << "\nbool: " << boolalpha << a << endl;


    return 0;
}
