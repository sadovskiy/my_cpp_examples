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
 * Программа рисует окошко с использованием символов псевдографики
 *
 * Работает только в GNU/Linux
 *
 * 
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

// Функция рисования окна
// Процесс рисования происходит от крайней левой верхней точки
void window(const int x, // Крайняя левая координата
            const int y, // Крайняя верхняя координата
            const int height, // Высота окна
            const int width,  // Ширина окна
            const wchar_t *title, // Заголовок окна
            const wchar_t *message); // Текст внутри окна

#endif // WINDOW_HPP
