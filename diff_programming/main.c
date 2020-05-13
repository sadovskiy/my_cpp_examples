/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример процедурного подхода к написанию программ
 * Обратите внимание, все функции находятся 
 * в глобальной области видимости.
 * Переменные могут быть локальными, но их надо передавать
 * через заголовок функции
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Для хранения разнотипных данных используется структура
// Объявим (англ. declare) эту структуру
struct user
{
    int num;
    char name[100];
};

// Для обработки данных структуры определим (англ. define) функции
int GetNum(struct user *n)
{
    return n->num;
}
char* GetName(struct user *n)
{
    return n->name;
}
void SetNum(struct user *n, const int lNum)
{
    n->num = lNum;
}
void SetName(struct user *n, const char *lName)
{
    strcpy(n->name, lName);
}
void print(const struct user *n)
{
    printf("Number: %d  Name: %s\n", n->num, n->name);
}

int main()
{
    // Определим переменную us
    struct user us;

    // Обработаем значения этой переменной
    SetNum(&us, 1);
    SetName(&us, "Bob");
    print(&us);

    return 0;
}
