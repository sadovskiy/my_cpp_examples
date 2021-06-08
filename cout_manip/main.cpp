/*
 *
 * Copyright (C) 2021. GPL
 *
 * Written by Sadovskiy B. S.
 *
 *
 * Права на программу (С) 2021. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует работу манипуляторами вывода, 
 * позволяя создавать столбцы и выравнивая данные в них 
 * 
 * Подробнее: https://ru.wikipedia.org/wiki/Перевод_строки
 *
 *
 *
 */

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

int main()
{
    int x1 = 1234, x2 = 5678, x3 = 12345;
    int widthField = 10;

    // Контрольный вывод с нумерацией позиций
    cout << "|12345678|1234567890|1234567890|" << endl;
    // Для котроля столбцов их заголовки прижимаются к левому краю
    cout << setw(widthField + 1) << left << "Column 1"
         << setw(widthField + 1) << left << "Column 2"
         << setw(widthField) << left << "Column 3" << endl;

    cout << "|" << setw(widthField - 2) << left  << x1 << "|" << setw(widthField) << left  << x2 << "|" << setw(widthField) << right << x3 << "|" << endl
         << "|" << setw(widthField - 2) << right << x1 << "|" << setw(widthField) << left  << x2 << "|" << setw(widthField) << left  << x3 << "|" << endl
         << "|" << setw(widthField - 2) << left  << x1 << "|" << setw(widthField) << right << x2 << "|" << setw(widthField) << left  << x3 << "|" << endl
         << "|" << setw(widthField - 2) << left  << x1 << "|" << setw(widthField) << left  << x2 << "|" << setw(widthField) << left  << x3 << "|" << endl;

    return 0;
}
