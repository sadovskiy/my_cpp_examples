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

#ifndef UTFTO866_H
#define UTFTO866_H

#include <iostream>
#include <windows.h>

class UtfTo866
{
    std::string str;
public:
    UtfTo866();
    UtfTo866(const UtfTo866& other);
    virtual ~UtfTo866();
    UtfTo866& operator=(const UtfTo866& other);

    std::string utf8To866(const wchar_t *m_str);
    void setString(std::string m_str);
    void setUtf8(const wchar_t *m_str);
    std::string get866() const;

};

#endif // UTFTO866_H
