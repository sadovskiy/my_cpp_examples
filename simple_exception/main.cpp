/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует работу с системой обработки исключений
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Обработка_исключений
 *
 *
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    // Блок внутри которого ведётся отлов исключений
    try {
        throw 100.5; // Инструкция генерирующая исключение
    }
    // Отлов только целых исключений
    catch (int x) {
        cerr << "int" << "\n";
        return EXIT_FAILURE;
    }
    // Отлов только дробных исключений
    catch (double d) {
        cerr << "double" << "\n";
        return EXIT_FAILURE;
    }

    // Отлов всех исключений
    catch (...) {
        cerr << "All" << "\n";
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
