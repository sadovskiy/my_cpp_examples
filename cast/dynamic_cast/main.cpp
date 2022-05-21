/*
 * Copyright (C) 2021. GPL
 *
 * Written by Sadovskiy B. S.
 *
 * Права на программу (С) 2021. GPL
 *
 * Написана Садовским Б. С.
 *
 * Пример привидения типа dynamic_cast
 *
 *
 */

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class TDevice
{
    string mBrand;
    string mModel;
public:
    TDevice(): mBrand(), mModel() {}
    TDevice(const string &newBrand,
            const string &newModel): mBrand(newBrand), mModel(newModel) {}

    const string &brand() const {return mBrand;}
    void setBrand(const string &newBrand) {mBrand = newBrand;}
    const string &model() const {return mModel;}
    void setModel(const string &newModel) {mModel = newModel;}

    virtual void show() const = 0;
};

class TCPU: public TDevice
{
    int mCores;
    int mClockSpeed;
public:
    TCPU(): TDevice(), mCores(), mClockSpeed() {}
    TCPU(const string &lBrand,
         const string &lModel,
         const int lCores,
         const int lClockSpeed):
        TDevice(lBrand, lModel),
            mCores(lCores), mClockSpeed(lClockSpeed) {}

    const int &cores() const {return mCores;}
    void setCores(const int newCores) {mCores = newCores;}
    const int &clockSpeed() const {return mClockSpeed;}
    void setClockSpeed(const int newClockSpeed) {mClockSpeed = newClockSpeed;}
    // TDevice interface
    void show() const override {cout << "Brand: " << brand() << "\n"
                                     << "Model: " << model() << "\n"
                                     << "Cores: " << cores() << "\n"
                                     << "ClockSpeed: " << clockSpeed() << endl;}

    // Метод существующий только в этом классе
    void ACT() const {cout << "ACT!" << endl;}
};

class TMotherboard: public TDevice
{
    string mChipset;
    string mFormFactor;
public:
    TMotherboard(): TDevice(), mChipset(), mFormFactor() {}
    TMotherboard(const string &lBrand,
                 const string &lModel,
                 const string &lChipset,
                 const string &lFormFactor):
        TDevice(lBrand, lModel),
            mChipset(lChipset), mFormFactor(lFormFactor) {}

    const string &chipset() const {return mChipset;}
    void setChipset(const string &newChipset) {mChipset = newChipset;}
    const string &formFactor() const {return mFormFactor;}
    void setFormFactor(const string &newFormFactor) {mFormFactor = newFormFactor;}
    // TDevice interface
    void show() const override {cout << "Brand: " << brand() << "\n"
                                     << "Model: " << model() << "\n"
                                     << "Chipset: " << chipset() << "\n"
                                     << "Form Factor: " << formFactor() << endl;}
};

void f1(TDevice *pDevice);

int main()
{
    TCPU cpu("Intel", "Core i5-10400", 6, 4300);
    TMotherboard mb("ASUS", "ROG Strix B450-F Gaming", "AMD B450", "ATX");

    f1(&cpu);
    std::cout.fill('-');
    cout.width(20);
    cout << "\n";

    f1(&mb);

    cout << endl;

    return 0;
}

void f1(TDevice *pDevice)
{
    // Отображение результатов через указатель на базовый класс
    // работает за счёт того, что метод show() виртуальный
    pDevice->show();
    cout << "Class: " << typeid(pDevice).name() << endl;

    // Для того, что бы воспользоваться другими специфичными для калсса методами
    // надо сделать динамическое приведение типов
    TCPU *pCPU = dynamic_cast<TCPU*>(pDevice);

    if (pCPU) {
        pCPU->show();
        pCPU->ACT(); // Метод есть только в TCPU
    }

    // Или ещё способ узнать от какого класса образован обеъкт
    cout << "Class: " << typeid(pCPU).name() << endl;


    TMotherboard *pMotherboard = dynamic_cast<TMotherboard*>(pDevice);

    if (pMotherboard)
        pMotherboard->show();

    cout << "Class: " << typeid(pMotherboard).name() << endl;
}
