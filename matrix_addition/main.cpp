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
 * Программа складывает матрицы
 *
 * Подробнее:
 * https://en.wikipedia.org/wiki/Matrix_addition
 *
 *
 */

#include <iostream>

using namespace std;

const int col = 2;
const int row = 2;

void addition_array(const int a[][col], const int b[][col], int c[][col])
{
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    cout << "\n";

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main()
{
    int matrix_a[row][col];
    int matrix_b[row][col];

    cout << "Enter matrix A: " << endl;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> matrix_a[i][j];

    cout << "Enter matrix B: " << endl;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> matrix_b[i][j];

    cout << "\n";

    int matrix_c[row][col] = {{0},{0}};
    addition_array( matrix_a, matrix_b, matrix_c );

    cout << "\n";

    cout << "Addition result AxB: " << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++)
            cout << matrix_c[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

