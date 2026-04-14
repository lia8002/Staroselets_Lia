#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Building {
    string name;
    string address;
    int floors;
    string purpose;
    double area;
    int year;
};

void AddBuilding() {
    ofstream fout("buildings.txt");
    if (!fout) {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    Building b;

    cin.ignore();

    cout << "Введіть назву будівлі: ";
    getline(cin, b.name);

    cout << "Введіть адресу: ";
    getline(cin, b.address);

    cout << "Введіть кількість поверхів: ";
    cin >> b.floors;

    cin.ignore();
    cout << "Введіть призначення: ";
    getline(cin, b.purpose);

    cout << "Введіть площу: ";
    cin >> b.area;

    cout << "Введіть рік введення в експлуатацію: ";
    cin >> b.year;

    fout << b.name << ";" << b.address << ";" << b.floors << ";"
        << b.purpose << ";" << b.area << ";" << b.year << endl;

    fout.close(); //зберігає всі дані
    cout << "Будівлю додано!" << endl;
}

void ShowAll() {
    ifstream fin("buildings.txt");
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        Building b;

        getline(ss, b.name, ';');
        getline(ss, b.address, ';');

        ss >> b.floors;
        ss.ignore(1, ';');

        getline(ss, b.purpose, ';');

        ss >> b.area;
        ss.ignore(1, ';');

        ss >> b.year;

        cout << "Назва: " << b.name
            << "; Адреса: " << b.address
            << "; Поверхів: " << b.floors
            << "; Призначення: " << b.purpose
            << "; Площа: " << b.area
            << "; Рік: " << b.year << endl;
    }

    fin.close(); //Закриває файл, з якого читаєш
}

void FilterBuildings() {
    ifstream fin("buildings.txt");
    cout << "Будівлі > 3 поверхів і після 2005 року:\n";

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        Building b;

        getline(ss, b.name, ';');
        getline(ss, b.address, ';');

        ss >> b.floors;
        ss.ignore(1, ';');

        getline(ss, b.purpose, ';');

        ss >> b.area;
        ss.ignore(1, ';');

        ss >> b.year;

        if (b.floors > 3 && b.year > 2005) {
            cout << "Назва: " << b.name
                << "; Адреса: " << b.address
                << "; Поверхів: " << b.floors
                << "; Призначення: " << b.purpose
                << "; Площа: " << b.area
                << "; Рік: " << b.year << endl;
        }
    }

    fin.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;

    do {
        cout << "\t\tМеню:\n";
        cout << "1. Додати будівлю\n";
        cout << "2. Показати всі будівлі\n";
        cout << "3. Фільтр (поверхи >3 і рік >2005)\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddBuilding();
            break;
        case 2:
            ShowAll();
            break;
        case 3:
            FilterBuildings();
            break;
        case 0:
            cout << "Вихід з програми..." << endl;
            break;
        default:
            cout << "Неправильний вибір!" << endl;
        }

    } while (choice != 0);

    return 0;
}