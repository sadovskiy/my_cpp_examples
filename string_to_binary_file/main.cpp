/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Приме записи и чтения бинарных фалов через строку
 *
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    // Сначала запишем в файл file.txt строку
    string originString = "Hello world!";
    string::size_type sizeOriginString = originString.size();

    fstream outFile("file.txt", ios_base::out | ios_base::binary );

    // Делаем приведение типа к char и записываем размер
    outFile.write(reinterpret_cast<char *>(&sizeOriginString),
                sizeof (string::size_type));
    // Записываем остальные данные
    outFile.write(originString.data(), sizeOriginString);

    outFile.close();

    // Затем прочитаем
    string destinationString;
    string::size_type sizeDestinationString;
    fstream inFile("file.txt", ios_base::in | ios_base::binary );

    // Читаем размер и записываем его в sizeDestinationString
    inFile.read(reinterpret_cast<char*>(&sizeDestinationString),
               sizeof (string::size_type));

    // Создаём временную строку tempBuffer
    std::vector<char> tempBuffer(sizeDestinationString);

    // Пишем в tempBuffer
    inFile.read(&tempBuffer[0], sizeDestinationString);

    // Копируем данные из tempBuffer в destinationString
    destinationString.assign(tempBuffer.begin(), tempBuffer.end());

    cout << destinationString << endl;

    inFile.close();

    return 0;
}
