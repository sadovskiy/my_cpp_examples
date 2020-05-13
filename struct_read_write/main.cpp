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

#include <iostream>
#include <locale>

#include "func.h"

using namespace std;

int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif
    // Создадим студента
    Student ivan_ivanov;

    // Так как кто будет конкретно прочитан из файла,
    // сделаем вторую переменную с шаблонным названием
    Student student;

    ivan_ivanov.id = 455;
    ivan_ivanov.name = L"Иван";
    ivan_ivanov.surname = L"Ivanov";
    ivan_ivanov.patronymic = L"Ivanovich";
    ivan_ivanov.facult = L"ISTAC";
    ivan_ivanov.year = 2;
    ivan_ivanov.group = 1;
    ivan_ivanov.mark = 5;

    // Сохраним студента в файл
    write_to_file(&ivan_ivanov);

    // А теперь прочитаем информацию о студенте из файла
    int status = read_to_file(&student);

    if (!status) {
        // Выведем на экран
        wcout << L"id = " << student.id << L"\n"
              << L"Name: " << student.name << L"\n"
              << L"Surname: " << student.surname << L"\n"
              << L"Patronymic: " << student.patronymic << L"\n"
              << L"Facult: " << student.facult << L"\n"
              << L"Year: " << student.year << L"\n"
              << L"Group: " << student.group << L"\n"
              << L"Mark: " << student.mark << endl;
    }
    return 0;
}
