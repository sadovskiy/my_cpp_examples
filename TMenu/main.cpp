/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример организации класса отвечающего за меню приложения
 *
 * 
 */

#include <iostream>
#include <cstdlib>
#include <locale>

class Menu
{
    // Определяем обрабатываемые данные
    // Другие необходимые функции по работе например,
    // загрузка списка элементов из файла
public:
    Menu();
    ~Menu() {}

    // Метод (функция-член) печатающая меню на экран
    void printMenu() const;

    int exec();
};

Menu::Menu()
{
    printMenu();
}

// Метод (функция-член) печатающая меню на экран
void Menu::printMenu() const
{
    std::wcout << L"1) Добавить элемент в список."    << L"\n"
               << L"2) Вывести на экран весь список." << L"\n"
               << L"3) Выход."                        << std::endl;

}

// Метод (функция-член) отвечающая за работу меню
// В нормальном состоянии ждёт выбора пункта меню пользователем
int Menu::exec()
{
    while (true)
    {
        int ch = 0;
        std::wcin >> ch;
        switch (ch)
        {
        case 1:
#ifdef _WIN64
            system("cls");
#elif __linux__
            system("clear");
#endif
            // Допустим пункт меню по вставке элемента в список.
            std::wcout << L"Добавляется элемент в список." << std::endl;
            // Тут можно запустить какой-нибудь метод другого объекта
            break;
        case 2:
#ifdef _WIN64
            system("cls");
#elif __linux__
            system("clear");
#endif
            break;
            // Пункт меню выхода из меню и соответственно программы
        case 3:
            return EXIT_SUCCESS;
        default:
            std::wcout << L"Нет такого пункта в меню!" << std::endl;
        }
        printMenu();
    }
}

int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif
    // Тут создадим наше меню и выведем на экран
    Menu menu;

    // Теперь запустим его и будем ждать выбора пользователя
    return menu.exec();
}
