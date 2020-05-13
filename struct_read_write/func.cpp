/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Программа демонстрирует запись/чтение структуры
 * на языке Си++
 *
 * Подробнее:
 * https://ru.wikipedia.org/wiki/Структура_(язык_Си)
 *
 * 
 */

#include "func.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

using std::wstring;
using std::wfstream;
using std::ios_base;
using std::wcerr;
using std::endl;
using std::wcout;
using std::stoi;

void write_to_file(Student *student)
{
    wfstream file_out;
    file_out.open("file.txt", ios_base::out);

    if (!file_out.is_open())
        wcerr << L"Error: file not open!" << endl;

    // Записываем информацию о студенте Иванове построчно в файл
    file_out << student->id << L";"
             << student->name << L";"
             << student->surname << L";"
             << student->patronymic << L";"
             << student->facult << L";"
             << student->year << L";"
             << student->group << L";"
             << student->mark << L";";

    file_out.close();
}

int read_to_file(Student *student)
{
    wfstream file_in;
    wstring str;
    file_in.open("file.txt", ios_base::in);

    if (!file_in.is_open()) {
        wcerr << L"Error: file not opened!" << endl;
        return READ_FAILURE;
    }

    // Чтение построчно с последующим разбором
    while (!file_in.eof()){
        getline(file_in, str);

        // Берём строчку ищем find() точку с запятой, вырезаем substr()
        // этот кусок, конвертируем stoi() в целое число и копируем в id
        student->id = stoi(str.substr(0, str.find(L";")));
        // Удаляем скопированный фрагмент
        str.erase(0, str.find(L";") + 1);

        // Повторяем для следующего поля структуры
        student->name = str.substr(0, str.find(L";"));
        str.erase(0, str.find(L";") + 1);

        student->surname = str.substr(0, str.find(L";"));
        str.erase(0, str.find(L";") + 1);

        student->patronymic = str.substr(0, str.find(L";"));
        str.erase(0, str.find(L";") + 1);

        student->facult = str.substr(0, str.find(L";"));
        str.erase(0, str.find(L";") + 1);

        student->year = stoi(str.substr(0, str.find(L";")));
        str.erase(0, str.find(L";") + 1);

        student->group = stoi(str.substr(0, str.find(L";")));
        str.erase(0, str.find(L";") + 1);

        student->mark = stoi(str.substr(0, str.find(L";")));
        str.erase(0, str.find(L";") + 1);
    }

    file_in.close();

    return READ_SUCCESS;
}
