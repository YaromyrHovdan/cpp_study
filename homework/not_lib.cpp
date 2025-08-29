#include <iostream>
#include <vector>
using namespace std;

struct School {
    string name;
    string surname;
    string pos;
};

int main() {
    vector<School> employers = {
        {"Pavlo", "Kryviy", "Teacher"},
        {"Yaroslav", "Myronovych", "Teacher"}, // ярик знає свої права
        {"Ivan", "Sranyk", "Headteacher"},
        {"Vitaliy", "Klychko", "Headteacher"},
        {"Heorhiy", "Drun", "Principal"}
    };

    string choice, query;
    cout << "Search with surname or name? ";
    getline(cin, choice);

    if (choice == "surname") {
        cout << "Enter surname of the person: ";
        getline(cin, query);

        bool found = false;
        for (auto &emp : employers) {
            if (emp.surname == query) {
                cout << emp.pos<< endl;
                found = true;
            }
        }
        if (!found) cout << "No people found with that surname." << endl;
    }
    else if (choice == "name") {
        cout << "Enter name of the person: ";
        getline(cin, query);

        bool found = false;
        for (auto &emp : employers) {
            if (emp.name == query) {
                cout << emp.pos << endl;
                found = true;
            }
        }
        if (!found) cout << "No people found with that name." << endl;
    }
    else {
        cerr << "Incorrect answer. Please type 'surname' or 'name'." << endl;
    }

    return 0;
}
