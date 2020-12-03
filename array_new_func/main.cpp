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

#include "ioFunc.hpp"

using namespace std;

int main()
{
    TClient autoClient[SIZE];

    autoArrayInit(autoClient, SIZE - 990);
    autoArrayPrint(autoClient, SIZE - 990);

    TClient *client = new TClient[SIZE];

    dynArrayInit(client, SIZE - 990);
    dynArrayPrint(client, SIZE - 990);

    delete [] client;

    return 0;
}
