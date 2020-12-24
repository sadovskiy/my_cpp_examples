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
 * Программа демонстрирует запись данных класса в бинарный файл и его чтение
 *
 * Работает только в GNU/Linux
 *
 * 
 */

#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>

using namespace std;

struct A
{
    enum    mediaType { audio_cd = 0,
                        photo_cd,
                        video_cd,
                        cd_rom,
                        cdr,
                        cdrw};
    short numDisk;
    wchar_t name[256];
    mediaType       mediaTypeDisk;
    bool            recordable;
};

void f1()
{
    fstream infile("DB2.db", ios_base::out | ios_base::binary);
    A a;

    a.numDisk = 1;
    wcscpy(a.name, L"Властилин колец. Братство кольца");
    a.mediaTypeDisk = A::video_cd;
    a.recordable = false;

    if (!infile.is_open()) {
        wcerr << L"Не удалось открыть Файл!" << endl;
        exit(EXIT_FAILURE);
    }

    infile.write((char *) &a, sizeof(a));

    infile.close();
}

void f2()
{
    fstream infile("DB2.db", ios_base::in | ios_base::binary);
    A a;

    if (!infile.is_open()) {
        wcerr << L"Не удалось открыть Файл!" << endl;
        exit(EXIT_FAILURE);
    }

    infile.read((char *) &a, sizeof(a));

    wcout << a.numDisk << " ";
    wcout << a.name << " ";
    wcout << a.mediaTypeDisk << " ";
    if (a.recordable)
        wcout << L"да" << endl;
    else
        wcout << L"нет" << endl;

    infile.close();
        int in1 = 0;
    while (in1 > 200000)
    {
        in1++;
    }
}


int main()
{
#ifdef __linux__
    // Включаем русскую локаль в языке Си++
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
#endif
    f1();
    f2();


    return 0;
}

