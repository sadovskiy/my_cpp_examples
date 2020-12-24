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
 * Программа демонстрирует работу с игнорированием символа '\n'
 * Символ перевода строки (англ. Line Feed(LF)) '\n'(10 или 0x0A) дописывается
 * во входной поток после любого введённого символа, так как cin требует
 * обязательно сопровождать любой ввод нажатием клавиши клавиатуры Enter,
 * которая и является этим символом.
 * Подробнее: https://ru.wikipedia.org/wiki/Перевод_строки
 *
 *
 *
 */

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    char n = 0; // Для switch ()
    char var = 0;
    string str;

    while (true) {
        cout << "Startup cycle!" << endl;
        cin >> n; // в буфер попадает два символа ваш и Enter '\n'

        // Ввод через cin >> var (перегруженная операция поместить в поток)
        // способен вводить не только одиночный символ,
        // но и текст до нажатия клавиши Enter. Если в тексте есть пробелы
        // (то есть он является состоящим из нескольких слов),
        // то последующие вызовы cin >> var не будут просить ввести ещё текст,
        // а будут брать его по словам из входящего потока пока они не будут
        // прочитаны полностью


        // Если в потоке ввода остался символ, то мы их удаляем (игнорируем)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (n) {
        case '1':
            cout << "cin.get()" << endl;
            // Так как в потоке '\n' был удалён, то программа на cin.get()
            // будет остановлена
            cin.get();
            break;
        case '2':
            // Текст, который обязательно надо ввести и завершить
            // нажатием Enter '\n'
            cin >> var;
            cout << "cin >> var" << endl;
            break;
        case '3':
            var = cin.get();
            cout << "var = cin.get()" << endl;
            break;
        case '4':
            cin.get(var);
            cout << "cin.get(var)" << endl;
            break;
        case '5':
            cin >> str;
            cout << "str: " << str << endl;
            cout << "cin.get()" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        case '6':
            cout << "You entered " << n << " and exiting." << endl;
            return 0;
        }

        cout << "End cycle! n = " << n << endl;
    }
}
