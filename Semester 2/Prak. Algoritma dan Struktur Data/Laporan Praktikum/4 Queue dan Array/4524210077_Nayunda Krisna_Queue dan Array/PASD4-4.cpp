#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<char> antrian;
    antrian.push('A');
    antrian.push('B');
    antrian.push('C');

    cout << "Antrian awal: ";
    queue<char> temp_print = antrian;
    while (!temp_print.empty()) {
        cout << temp_print.front() << " ";
        temp_print.pop();
    }
    cout << endl;

    queue<char> antrian_a;
    bool inserted_d = false;
    while (!antrian.empty()) {
        char current = antrian.front();
        antrian.pop();
        antrian_a.push(current);
        if (current == 'A' && !inserted_d) {
            antrian_a.push('D');
            inserted_d = true;
        }
    }
    antrian = antrian_a;

    cout << "\nAntrian setelah memasukkan D setelah A: ";
    temp_print = antrian;
    while (!temp_print.empty()) {
        cout << temp_print.front() << " ";
        temp_print.pop();
    }
    cout << endl;

    while (!antrian.empty()) {
        antrian.pop();
    }
    antrian.push('F');

    cout << "\nAntrian setelah memasukkan F (A, B, C hilang): ";
    temp_print = antrian;
    while (!temp_print.empty()) {
        cout << temp_print.front() << " ";
        temp_print.pop();
    }
    cout << endl;

    queue<char> antrian_d;
    inserted_d = false;
    antrian.push('A');
    antrian.push('B');
    antrian.push('C');
    queue<char> antrian_e;
    while (!antrian.empty()) {
        char current = antrian.front();
        antrian.pop();
        antrian_e.push(current);
        if (current == 'B' && !inserted_d) {
            antrian_e.push('E');
            inserted_d = true;
        }
    }
    antrian = antrian_e;

    cout << "\nAntrian setelah memasukkan E setelah B: ";
    temp_print = antrian;
    while (!temp_print.empty()) {
        cout << temp_print.front() << " ";
        temp_print.pop();
    }
    cout << endl;

    return 0;
}