//
//  main.cpp
//  lab03
//
//  Created by Кирилл Кузнецов on 14.12.2021

// #include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#define N 3

using namespace std;

class display {
private:
    string brand;
    string color;
    int32_t textResolution;
    int32_t graphicsResolution;
    int32_t price;
public:
    display(string brand, string color, int32_t textResolution, int32_t graphicsResolution, int32_t price)
    {
        this->brand = brand;
        this->color = color;
        this->textResolution = textResolution;
        this->graphicsResolution = graphicsResolution;
        this->price = price;
    }
    display()
    {
    }
    string getBrand()
    {
        return brand;
    }
    string getColor() {
        return color;
    }
    int32_t getTextResolution() {
        return textResolution;
    }
    int32_t getGraphicsResolution() {
        return graphicsResolution;
    }
    int32_t getPrice() {
        return price;
    }
    friend istream & operator >> (istream &stream, display &obj);
};

class Printer {
public:
    Printer() { }
    void printLine() {
        string line = "|" + string(80, '-') + '|';
        cout << line << endl;
    }
    void printShortLine() {
        string line = "|" + string(58, '-') + '|';
        cout << line << endl;
    }
    void printHeader() {
        printLine();
        cout << "|" << setw(10) << "Brand" << "|" << setw(10) << "Color"
            << "|" << setw(20) << "Text Resolution" << "|" << setw(20) << "Graphics Resolution"
            << "|" << setw(10) << "price" << setw(7) << "|" << endl;
        printLine();
    }
    void printShortHeader() {
        printShortLine();
        cout << "|" << setw(15) << "Brand" << "|" << setw(20) << "Graphics Resolution"
            << "|" << setw(12) << "Text Resolution" << "|" << setw(8) << "Price"
            << "|" << endl;
        printShortLine();
    }
    void printDisplay(display d) {
        cout << "|" << setw(10) << d.getBrand() << "|" << setw(10) << d.getColor()
            << "|" << setw(20) << d.getTextResolution() << "|" << setw(20) << d.getGraphicsResolution()
            << "|" << setw(10) << d.getPrice() << setw(7) << "|" << endl;
    }
    void printShortDisplay(display d) {
        cout << "|" << setw(15) << d.getBrand() << "|" << setw(20) << d.getGraphicsResolution()
            << "|" << setw(12) << d.getTextResolution() << "|" << setw(8) << d.getPrice()
            << "|" << endl;
    }
    void printAllDisplay(display * d) {
        for (int i = 0; i < N; i++)
        {
            printDisplay(d[i]);
        }
    }
    void printShortAllDisplay(display * d, int count) {
        for (int i = 0; i < count; i++)
        {
            printShortDisplay(d[i]);
        }
    }
    void printFooter() {
        printLine();
    }
    void printShortFooter() {
        printShortLine();
    }
};

istream & operator >> (istream &stream, display &obj)
{
    cout << "Brand:" << endl;
    getline(stream, obj.brand);
    while (obj.brand.length() == 0)
        getline(stream, obj.brand);
    cout << "Color:" << endl;
    getline(stream, obj.color);
    cout << "Text Resolution:" << endl;
    cin >> obj.textResolution;
    cout << "Graphics Resolution:" << endl;
    cin >> obj.graphicsResolution;
    cout << "Price:" << endl;
    cin >> obj.price;
    return stream;
}


class DisplayHelper {
public:
    DisplayHelper() {    }
    void sortDisplayArray(display* d)
    {
        for (int b = 0; b < N - 1; b++) {

            for (int i = 0; i < N - 1; i++)
            {
                if (d[i].getGraphicsResolution() > d[i+1].getGraphicsResolution())
                {
                    display t = d[i + 1];
                    d[i + 1] = d[i];
                    d[i] = t;
                }
            }
        }
    }
    void createDisplayArray(display* d)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> d[i];
        }
    }
    void freeDisplayArray(display* d)
    {
        delete d;
    }
};

int menu()
{
    // Выбранный вариант
    int v = 0;
    cout << "Выберите вариант\n" << endl;
    cout << "1.Создание массива объектов\n"
        << "2.Вывод на экран массива объектов в виде таблицы\n"
        << "3.Вывод сортировоного массива\n"
        << "4.Выйти\n" << endl;
    cout << ">>> ";
    cin >> v ;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Выберите вариант\n" << endl;
        cout << "1.Создание массива объектов\n"
            << "2.Вывод на экран массива объектов в виде таблицы\n"
            << "3.Вывод сортировоного массива\n"
            << "4.Выйти\n" << endl;
        cout << ">>> ";
        cin >> v;
    }
    return v;
}


int main() {

    setlocale(LC_ALL, "Russian");

    display * d = new display[N];

    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            cout << "Создание массива объектов" << endl;
            DisplayHelper ch;
            ch.createDisplayArray(d);
            break;
        }
        case 2:
        {
            cout << "Вывод на экран массива объектов в виде таблицы" << endl;
            Printer p;
            p.printHeader();
            p.printAllDisplay(d);
            p.printFooter();
            break;
        }
        case 3:
        {
            cout << "Вывод сортировоного массива" << endl;

            DisplayHelper ch;
            ch.sortDisplayArray(d);
            Printer p;
            p.printHeader();
            p.printAllDisplay(d);
            p.printFooter();
            break;
        }
        case 4:
        {
            exit(EXIT_SUCCESS);
            break;
        }
        default:{
            cout << "Введите 1-4!" << endl;
            break;
        }
        }
    }
    return 0;
}
