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
 * Программа записывает в файл текст и символы '✯', '€' в кодировке UTF-8
 *
 * Работает только в GNU/Linux
 *
 * 
 */

#include <iostream>
#include <locale>
#include <string>
#include <fstream>

using namespace std;

int main()
{
#ifdef __linux__
    // Установка локали для корректного отображения символов в Си++
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif

    // При использовании этой функции не работает вывод в файл
//    setlocale(LC_ALL, "ru_RU.UTF-8");

    wfstream out;
    wfstream in;
    wstring strHello = L"Привет мир!";
    wchar_t star = L'✯';
    wchar_t euro = L'€';

    // Вывод на экран строк в два байта (16 бит)
    wcout << "strHello: "        << strHello << "\n"
          << "star: "            << star << endl;


//    ios::арр 	     Добавление всех выводимых данных в конец заданного файла
//    ios::ate 	     Ввода-вывод может выполняться в любом месте файла.
//                   Указатель устанавливается в конец файла
//    ios::binary 	 Открытие файла для двоичных операций ввода-вывода
//    ios::in 	     Открытие файла для вывода
//    ios::nocreate  Неудача если заданного файла еще не существует
//    ios::noreplace Запрет выполнения если заданный файл уже существует
//    ios::out 	     Открытие файла для ввода
//    ios::trunc 	 Разрушение содержимого уже существующего файла

    out.open("test.txt", ios_base::out);

    if (out.is_open()) {
        out << strHello << endl;
        out << star << L" " << euro << endl;
        out.close();
    }

    in.open("test.txt", ios_base::in);

    if (in.is_open()) {
        while (!in.eof()) {
            wstring str;
            wgetline(in, str);
            wcout << str << endl;
        }

        in.close();
    }

    return EXIT_SUCCESS;
}
