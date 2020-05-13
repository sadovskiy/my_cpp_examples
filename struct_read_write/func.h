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

#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <string>

// Информация о результате чтения файла
#define READ_FAILURE 1
#define READ_SUCCESS 0

// Создаём новую структуру "Студент"
struct Student
{
    int id; // Идентификатор студента (например номер зачётки)
    std::wstring name;  // Имя студента
    std::wstring surname;  // Фамилия студента
    std::wstring patronymic; // Отчество студента
    std::wstring facult;  // Институт
    int year;            // Курс обучения
    int group;           // Группа
    int mark;            // Получена оценка по предмету
};


void write_to_file(Student *student);
int read_to_file(Student *student);

#endif // FUNC_H_INCLUDED
