﻿/*
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
 * Программа выводит текст UTF-8 через установку локали.
 * Имеет большое значение, где происходит установка локали и был ли
 * до этого вывод/вывод через другой поток.
 * Это важно, так как при первом выводе поток переключается в один
 * из двух режимов. Если первыми выводились однобайтные символы,
 * то при попытке в дальнейшем вывести многобайтные (широкие),
 * вывод будет сломан. Это верно и наоборот.
 * При первом выводе широких символов, нельзя будет в дальнейшем выводить
 * обычные однобайтные.
 * В Си эта проблема решалась вызовом функции freopen(0, "w", stdout).
 * В Си++ требуется отсоединить поток Си++ от потока Си,
 * а затем для каждого потока индивидуально ставить локаль.
 * Подробнее смотрите пример setmode_for_windows
 *
 * Подробнее:
 * https://habr.com/ru/post/326578/
 * https://habr.com/ru/post/104417/
 *
 * Работает только в GNU/Linux
 *
 *
 */

#include <iostream>
#include <locale>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    // Если делаем ввод/вывод до установки локали,
    // то без отсоединения потока Си++ от Си
    // нельзя будет получить корректный ввод/вывод.
    // Скорее всего будет чёрный экран

    // Посмотреть текущую локаль
    cout << "User-preferred locale setting is " << locale().name()
         << " (before set locale)" << endl;
#ifdef __linux__ || __APPLE__

    // Включаем русскую локаль в языке Си++
    locale ru_RU("ru_RU.UTF-8");
    locale::global(ru_RU); // Устанавливаем текущую локаль глобально
    // или две команды в одну строчку locale::global(locale("ru_RU.UTF-8"));

    // Если локаль не ставить вообще,
    // то будет включена локаль по умолчанию "C" или "POSIX"
//    locale::global(locale("POSIX"));


    // Отключаем синхронизацию между потоками Си (stdio) и Си++ (iostream).
    // https://habr.com/ru/post/246257
    ios_base::sync_with_stdio(false);
    // После отключения синхронизации потоков, требуется устанавливать
    // локаль для каждого потока индивидуально. Можно через переменную ru_RU
    wcout.imbue(ru_RU);
    wcerr.imbue(ru_RU);
    wclog.imbue(ru_RU);
    wcin.imbue(ru_RU);
    // или просто запрашивая текущую локаль с помощью locale()
//    wcout.imbue(locale());
//    wcerr.imbue(locale());
//    wclog.imbue(locale());
//    wcin.imbue(locale());
    // Или надо сбрасывать поток Си (stdio) функции freopen(0, "w", stdout)
#endif
    // Теперь независимо, от того был ли до этого вывод в поток для однобайтных
    // символов или нет, вывод должен заработать нормально и
    // с широкими символами

    // Посмотрим как отображается строка через поток широких символов
    // и какая у неё локаль
    wcout << L"User-preferred locale setting is " << locale().name().c_str()
          << " (after set locale)" << endl;

    // Проверка вывода строки с кодом Unicode-символа
    wstring wstr1 = L"Wide string with special chars: \u20AC";  // Euro символ
    wcout << wstr1 << endl;

    // Проверка вывода Unicode-строки
    wstring wstr2 = L"Привет мир!";
    wcout << wstr2 << endl;
    // Проверка дробного разделителя. В англоязычных странах используется точка,
    // а в остальных запятая
    // Подробнее:
    // https://ru.wikipedia.org/wiki/Десятичный_разделитель
    wcout << 6.7 << endl;

    // Если всё хорошо, то должен быть вывод как на снимке экрана
    
    return 0;
}
