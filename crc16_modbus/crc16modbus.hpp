/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Расчёт CRC
 *
 * 
 */

#ifndef CRC16MODBUS_HPP
#define CRC16MODBUS_HPP

#include <stddef.h>
#include <sys/types.h>

void initCRC16Table();
u_int16_t updateCRC16(u_int16_t crc, const u_int8_t c);
void calculateCRC16(const u_int8_t *src = 0, size_t size = 0);
    

#endif // CRC16MODBUS_HPP
