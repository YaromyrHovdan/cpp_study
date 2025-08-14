#include <iostream>
using namespace std;

struct Car {
    string brand;
    string model;
    int year;
    double engineVolume;
    string color;
};

int main() {
    Car car1;

    cout << "Введіть марку автомобіля: ";
    cin >> car1.brand;

    cout << "Введіть модель: ";
    cin >> car1.model;

    cout << "Введіть рік випуску: ";
    cin >> car1.year;

    cout << "Введіть обʼєм двигуна (л): ";
    cin >> car1.engineVolume;

    cout << "Введіть колір: ";
    cin >> car1.color;

    cout << "\n--- Інформація про автомобіль ---\n";
    cout << "Марка: " << car1.brand << endl;
    cout << "Модель: " << car1.model << endl;
    cout << "Рік: " << car1.year << endl;
    cout << "Двигун: " << car1.engineVolume << " л\n";
    cout << "Колір: " << car1.color << endl;

    return 0;
}
