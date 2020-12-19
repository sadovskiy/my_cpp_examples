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
 * Программа выводит текст UTF-8 с использованием локали
 *
 * Работает только в GNU/Linux
 *
 * 
 */

#include <iostream>
#include <locale>

using namespace std;

int main()
{
    // Включаем русскую локаль в языке Си++
    locale loc("ru_RU.UTF-8");
    locale::global(loc);

    wstring str = L"Привет мир!";

    wcout << str << endl;
    
    return 0;
}
