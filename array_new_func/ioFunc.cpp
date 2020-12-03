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
 * Программа демонстрирует работу с созданием массива структуры 
 * с автоматической и динамической продолжительностью хранения
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Структура_(язык_Си)
 * https://ru.wikipedia.org/wiki/Массив_(тип_данных)
 * https://ru.wikipedia.org/wiki/Указатель_(тип_данных)
 * https://ru.wikipedia.org/wiki/Ссылка_(программирование)
 * https://ru.wikipedia.org/wiki/Динамическое_распределение_памяти
 *
 */

#include "ioFunc.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

void autoArrayInit(TClient localClient[], const size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        localClient[i].id    = i;
        localClient[i].fName = "Stаn";
        localClient[i].lName = "Smith " + std::to_string(i);
        localClient[i].contractNumber = 1000 + i;
    }
}

void autoArrayPrint(TClient localClient[], const size_t count)
{
    cout << "Array with automatic storage duration" << endl;
    for (size_t i = 0; i < count; ++i) {
        cout << "id: "               << localClient[i].id << "  |  "
             << "Name: "             << localClient[i].fName << " "
             << localClient[i].lName << "  |  "
             << "Contract No: "      << localClient[i].contractNumber << endl;
    }
    cout << endl;
}

void dynArrayInit(TClient *localClient, const size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        (localClient + i)->id = i;
        (localClient + i)->fName = "Stаn";
        (localClient + i)->lName = "Smith " + std::to_string(i);
        (localClient + i)->contractNumber = 1000 + i;
    }
}

void dynArrayPrint(TClient *localClient, const size_t count)
{
    cout << "Array with dynamic storage duration" << endl;
    for (size_t i = 0; i < count; ++i) {
        cout << "id: "   << (localClient + i)->id << "  |  "
             << "Name: " << (localClient + i)->fName << " "
             << (localClient + i)->lName << "  |  "
             << "Contract No: " << (localClient + i)->contractNumber << endl;
    }
}
