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
 * Программа демонстрирует работу с созданием автоматического массива структур
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Структура_(язык_Си)
 * https://ru.wikipedia.org/wiki/Массив_(тип_данных)
 * https://ru.wikipedia.org/wiki/Указатель_(тип_данных)
 * https://ru.wikipedia.org/wiki/Ссылка_(программирование)
 * https://ru.wikipedia.org/wiki/Динамическое_распределение_памяти
 *
 */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

struct TClient
{
    int id;
    std::string fName;
    std::string lName;
    int contractNumber;
};

const size_t SIZE = 1000;

#endif // CLIENT_HPP
