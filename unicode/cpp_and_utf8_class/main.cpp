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
 * В программе показан пример функции конвертации символов UTF-8 в 866
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Широкий_символ
 * https://ru.wikipedia.org/wiki/Символьный_тип
 * https://ru.wikipedia.org/wiki/Printf
 *
 *
 */

#include <fstream>
#include "utfto866.h"
#include <locale>

using namespace std;

int main()
{
    UtfTo866 m;
    m.utf8To866(L"1 - Привет мир!\n");
    cout << m.get866() << endl;
    cout << m.utf8To866(L"2 - Привет мир!\n") << endl;

    return 0;
}
