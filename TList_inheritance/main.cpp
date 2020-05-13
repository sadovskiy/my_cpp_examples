/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример организации списка через класс
 *
 * 
 */

#include <iostream>
#include <string>
#include <locale>

class A
{
    int m_n;
public:
    A(){}
    A(const int n): m_n(n){}
    ~A(){}

    int get_n() const {return m_n;}
    void set_n(const int n) {m_n = n;}
};

// Делаем класс наследник с добавлением новых свойств,
// необходимых для взаимодействия элементов в связном списке
class A_unit: public A
{
    A_unit* n; // Ссылка на следующий элемент
    A_unit* p; // Ссылка на предыдущий элемент

public:
    A_unit(): n(0), p(0) {}
    ~A_unit(){}

    A_unit* next() const {return n;}
    A_unit* prior() const {return p;}

    void next(A_unit* const l_n) {n = l_n;}
    void prior(A_unit* const l_p) {p = l_p;}
    // Другие необходимые функции
};

// Класс отвечающий за хранение данных в связанном списке (Базе данных)
class list_A
{
    A_unit obj; // Объект который будет хранится в списке
    A_unit *first; // Указатель на первый элемент в списке
    A_unit *last; // Указатель на последний элемент в списке

public:
    list_A(): first(0), last(0) {}
    ~list_A(){}

    void add(const int number); // Добавление элемента в список
    void del(const int n);  // Удаление элемента из списка
    void edit(const int num_old, const int new_num); // Редактирование элемента списка
    A_unit* find_l(const int key) const; // Поиск элемента по ключу
    void printAll() const; // Вывести на экран весь список
    bool is_full() const; // Проверка есть ли ещё место в списке
    bool is_empty_l() const; // Проверить пустой ли список
    // Другие необходимые функции
};

// Добавляем элемент в конец списка
void list_A::add(const int number)
{
    A_unit* new_element = new A_unit;
    new_element->set_n(number);
    if (!first)
        first = new_element;
    else {
        new_element->prior(last);
        last->next(new_element);
    }

    last = new_element;
}

// Удаление элемента по его значению
void list_A::del(const int n)
{
    A_unit* deleting_element = find_l(n);

    if (deleting_element) {
        if (first == last) {
            delete first;
            first = last = 0;
            return;
        }
        if (deleting_element == first) {
            deleting_element->next()->prior(0);
            first = deleting_element->next();
        }
        if (deleting_element == last) {
            deleting_element->prior()->next(0);
            last = deleting_element->prior();
        }
        if ((deleting_element->next() != 0) &&
                (deleting_element->prior() != 0)) {
            deleting_element->next()->prior(deleting_element->prior());
            deleting_element->prior()->next(deleting_element->next());
        }
        delete deleting_element;
    }
}

void list_A::edit(const int num_old, const int new_num)
{
    A_unit* num = find_l(num_old);
    if (num)
        num->set_n(new_num);
    else
        std::wcout << L"Элемент не найден!" << std::endl;
}

A_unit* list_A::find_l(const int key) const
{
    for (A_unit* current = first;
         current;
         current = current->next())
        if (current->get_n() == key)
            return current;
    return 0;
}

void list_A::printAll() const
{
    for (A_unit* current = first;
         current;
         current = current->next())
        std::wcout << current->get_n() << std::endl;
}

bool list_A::is_full() const
{
    A_unit* temp = new A_unit;
    if (temp)
    {
        delete temp;
        return 0;
    }
    else
        return 1;
}

bool list_A::is_empty_l() const
{
    if(!first)
        return true;
    else
        return false;
}


int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif
    // Создадим пустой список
    list_A list;

    // Добавим в него данные
    list.add(10);
    list.add(11);
    list.add(12);
    list.add(13);
    // Выведем на экран
    list.printAll();
    std::wcout << L"-------------" << std::endl;

    // Удалим один элемент и проверим, удалился ли он
    list.del(12);
    list.printAll();
    std::wcout << L"-------------" << std::endl;

    // Изменим один элемент и проверим, изменился ли он
    list.edit(10, 25);
    list.printAll();
    std::wcout << L"-------------" << std::endl;

    return 0;
}
