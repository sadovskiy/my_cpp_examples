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

#include "utfto866.h"
#include <cstring>


UtfTo866::UtfTo866():
    str("")
{
    //ctor
}

UtfTo866::~UtfTo866()
{
    //dtor
}

UtfTo866::UtfTo866(const UtfTo866& other):
    str(other.str)
{
    //ctor copy
}

UtfTo866& UtfTo866::operator=(const UtfTo866& rhs)
{
    if(this == &rhs) return *this;
    str = rhs.str;

    return *this;
}

std::string UtfTo866::utf8To866(const wchar_t *m_str)
{
    char *std_char = new char[std::wcslen(m_str) + 1];

    CharToOemW(m_str, std_char);

    str = std_char;

    delete [] std_char;

    return str;
}

// Для конвертации строки типа std::string
void UtfTo866::setString(std::string m_str)
{
    wchar_t *src = new wchar_t[m_str.length() + 1];
    char *std_char = new char[m_str.length() * 2 + 1];
    unsigned long read;

    strcpy(std_char, m_str.c_str());

    WideCharToMultiByte(CP_UTF8, 0,
                                      src, read,
                                      std_char,
                                      sizeof(std_char),
                                      NULL, NULL);

    str.insert(0, std_char);

    delete [] std_char;
    delete [] src;
}

void UtfTo866::setUtf8(const wchar_t *m_str)
{
    char *std_char = new char[std::wcslen(m_str) + 1];

    CharToOemW(m_str, std_char);

    str = std_char;

    delete [] std_char;
}

std::string UtfTo866::get866() const
{
    return str;
}
