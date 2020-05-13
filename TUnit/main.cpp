/*
 * Copyright (C) 2020. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2020. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример моделирования объекта
 *
 * 
 */

#include <iostream>
#include <string>

// Пример класса центрального процессора (ЦП) (англ. CPU)
class TCPU
{
    std::wstring mManufacturer; // Производитель
    std::wstring mModel;  // Модель процессора
    float mFreq; // Частота
    int mCores; // Количество ядер
    // Другие свойства CPU

public:
    // Перечисляются базовые методы
    TCPU(): mManufacturer(), mModel(), mFreq(), mCores() {}
    TCPU(const std::wstring &lManufacturer,
         const std::wstring &lModel,
         const float &lFreq,
         const int &lCores);
    ~TCPU(){}

    // Далее следуют функции для работы с параметрами ЦП
    void setCPU(const std::wstring &lManufacturer,
                const std::wstring &lModel,
                const float &lFreq,
                const int &lCores);

    void setManufacturer(const std::wstring &lManufacturer)
    {
        mManufacturer = lManufacturer;
    }
    std::wstring getManufacturer() const
    {
        return mManufacturer;
    }

    void setModel(const std::wstring &lModel)
    {
        mModel = lModel;
    }
    std::wstring getModel() const
    {
        return mModel;
    }

    void setFreq(const float lFreq)
    {
        mFreq = lFreq;
    }
    float getFreq() const
    {
        return mFreq;
    }

    void setCores(const int lCores)
    {
        mCores = lCores;
    }
    int getCores() const
    {
        return mCores;
    }

    void show() const;
    // Далее описываются ещё методы исходя из решаемой задачи
};

// Описание методов вне класса
TCPU::TCPU(const std::wstring &lManufacturer,
           const std::wstring &lModel,
           const float &lFreq,
           const int &lCores):
    mManufacturer(lManufacturer)
  , mModel(lModel)
  , mFreq(lFreq)
  , mCores(lCores)
{

}

void TCPU::setCPU(const std::wstring &lManufacturer,
                  const std::wstring &lModel,
                  const float &lFreq,
                  const int &lCores)
{
    mManufacturer = lManufacturer;
    mModel = lModel;
    mFreq = lFreq;
    mCores = lCores;
}

void TCPU::show() const
{
    std::wcout << L"Manufacturer: " << mManufacturer << std::endl;
    std::wcout << L"Model: " << mModel << std::endl;
    std::wcout << L"Frequency: " << mFreq << std::endl;
    std::wcout << L"Cores: " << mCores << std::endl;
}


int main()
{
#ifdef __linux__
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
#endif
    // В качестве контрольного примера сделаем объект
    TCPU cpu;

    // и зададим ему параметры
    cpu.setCPU(L"Intel", L"Core i7", 3.5, 4);

    // Выведем на экран
    cpu.show();

    return 0;
}

