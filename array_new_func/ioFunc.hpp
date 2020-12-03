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

#ifndef IOFUNC_HPP
#define IOFUNC_HPP

#include "client.hpp"

void autoArrayInit(TClient localClient[], const size_t count);
void autoArrayPrint(TClient localClient[], const size_t count);

void dynArrayInit(TClient *localClient, const size_t count);
void dynArrayPrint(TClient *localClient, const size_t count);

#endif // IOFUNC_HPP
