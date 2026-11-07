#include <iostream>
using namespace std;

int main() {
    int nilai;

    
    cout << "Masukkan nilai (1-5): ";
    cin >> nilai;

    
    switch (nilai) {
        case 1:
            cout << "Nilai anda: A" << endl;
            break;
        case 2:
            cout << "Nilai anda: B" << endl;
            break;
        case 3:
            cout << "Nilai anda: C" << endl;
            break;
        case 4:
            cout << "Nilai anda: D" << endl;
            break;
        case 5:
            cout << "Nilai anda: E" << endl;
            break;
        default:
            cout << "Nilai yang anda masukkan salah!" << endl;
            break;
    }

    cin.get();
}
