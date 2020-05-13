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

#include "crc16modbus.hpp"

#include <cstring>
#include <iostream>
#include <iomanip>

void initCRC16Table()
{
    // Полином 0xA001 реверс стандартного полинома 0x8005
    // 16 - бит или 2 байта по этому quint16
    const u_int16_t polynomial = 0xA001;

    size_t index;
    u_int32_t j;
    u_int16_t crc, c;

    // Построение таблицы длинной в один байт
    for (index = 0; index < arrayCRCTableLength; ++index) {

        crc = 0;
        c = index;

        for (j = 0; j < 8; ++j) {
            if ( ( crc ^ c ) & 0x0001 )
                crc = ( crc >> 1 ) ^ polynomial;
            else
                crc =   crc >> 1;

            c = c >> 1;
        }

        crcTable[index] = crc;
    }
}

u_int16_t updateCRC16(u_int16_t crc, const u_int8_t c)
{
    u_int16_t short_c = 0x00FF & c;
    u_int16_t tmp = crc ^ short_c;

    crc = ( crc >> 8 ) ^ crcTable[tmp & 0xFF];

    return crc;
}

void calculateCRC16(const u_int8_t *src, size_t size)
{
    // Для примера:
    // 000BDF2F2F
    // length = 10
    // byte = 5
    // 00 0B DF 2F 2F (по основанию 16)
    // 0 0011 0223 0047 0047 (по основанию 10)
    // CRC 1 = 4A (74)
    // CRC 2 = 32 (50)
    //
    // 0000
    // CRC 1 = 01 (1)
    // CRC 2 = B0 (176)

    u_int16_t crc16Modbus = 0xFFFF; 

    for (size_t index = 0; index < size; ++index) {
        crc16Modbus = updateCRC16(crc16Modbus, src[index]);
    }

    int dec1 = crc16Modbus & 0xFF;
    result[0] = crc16Modbus & 0xFF;
    std::cout << "Dec CRC 1: " << std::uppercase << std::hex << dec1 << std::endl;

    int dec2 = (crc16Modbus >> 8) & 0xFF;
    result[1] = (crc16Modbus >> 8) & 0xFF;
    std::cout << "Dec CRC 2: " << std::uppercase << std::hex << dec2 << std::endl;
}

