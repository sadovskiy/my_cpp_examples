/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример объектно-ориентированного подхода к написанию программ
 * Обратите внимание, данные (переменные-члены класса) и 
 * методы (функции-члены класса) находятся в локальной 
 * области видимости
 *
 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

// Для хранения и обработки разнотипных данных используется класс
// Объявим (англ. declare) этот класс
class TUser
{
    int mNum;
    char mName[100];
public:
    TUser(): mNum(0) {strcpy(mName, "");}
    TUser(const int &lNum, const char *lName):
        mNum(lNum) {strcpy(mName, lName);}
    ~TUser(){}
    int GetNum() const {return mNum;}
    char* GetName() {return mName;}
    void SetNum(const int &lNum){mNum = lNum;}
    void SetName(const char *lName){strcpy(mName, lName);}
    void print() const {cout << "Number: " << mNum <<
                                "  Name: " << mName << endl;}
};

int main()
{
    // Определим переменную (объект) user
    TUser user;

    // Вызывая методы этой переменой оказываем 
    // управляющее воздействие
    user.SetNum(1);
    user.SetName("Smith");
    user.print();

    return 0;
}
