// Пример битов ввода/вывода (eofbit, failbit, badbit)

#include <iostream>

using namespace std;

int main()
{
    char a_ch[20] = {'\0'};
    char ch = 0;
    int i = 0;

    cout << "Ввод через >> " << endl;
    while (cin >> ch) {
        a_ch[i] = ch;
        i++;
    }

    // контрольный вывод
    cout << endl;
    cout << a_ch << endl;
    cout << "eofbit: ";
    if (cin.eof())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "failbit: ";
    if (cin.fail())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "badbit: ";
    if (cin.bad())
        cout << "set" << endl;
    else cout << "unset" << endl;

    // сброс значений переменных
    cout << "Reset!" << endl;
    ch = 0;
    for (i = 0; i < 20; i++)
        a_ch[i] = '\0';
    i = 0;
    cin.clear();
    cout << "eofbit: ";
    if (cin.eof())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "failbit: ";
    if (cin.fail())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "badbit: ";
    if (cin.bad())
        cout << "set" << endl;
    else cout << "unset" << endl;


    cout << "Ввод через cin.get(void)" << endl;
    while ((ch = cin.get()) != '\n') {
        a_ch[i] = ch;
        i++;
    }

    // контрольный вывод
    cout << "eofbit: ";
    if (cin.eof())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "failbit: ";
    if (cin.fail())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "badbit: ";
    if (cin.bad())
        cout << "set" << endl;
    else cout << "unset" << endl;

    // сброс значений переменных
    cout << "Reset!" << endl;
    ch = 0;
    for (i = 0; i < 20; i++)
        a_ch[i] = '\0';
    i = 0;
    cin.clear();
    cout << "eofbit: ";
    if (cin.eof())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "failbit: ";
    if (cin.fail())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "badbit: ";
    if (cin.bad())
        cout << "set" << endl;
    else cout << "unset" << endl;


    cout << "Ввод через cin.get(char &) " << endl;
    while (cin.get(ch)) {
        a_ch[i] = ch;
        i++;
    }

    // контрольный вывод
    cout << endl;
    cout << a_ch << endl;
    cout << "eofbit: ";
    if (cin.eof())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "failbit: ";
    if (cin.fail())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "badbit: ";
    if (cin.bad())
        cout << "set" << endl;
    else cout << "unset" << endl;

    // сброс значений переменных
    cout << "Reset!" << endl;
    ch = 0;
    for (i = 0; i < 20; i++)
        a_ch[i] = '\0';
    i = 0;
    cin.clear();
    cout << "eofbit: ";
    if (cin.eof())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "failbit: ";
    if (cin.fail())
        cout << "set" << endl;
    else cout << "unset" << endl;
    cout << "badbit: ";
    if (cin.bad())
        cout << "set" << endl;
    else cout << "unset" << endl;


    return 0;
}
