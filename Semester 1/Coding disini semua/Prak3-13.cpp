#include <iostream>
using namespace std;

int main() {
    int a, b;

    
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;

    
    if (b < a) {
        int hasil = (a * 3) + a;

        
        if (a > 15) {
            cout << "BENAR" << endl;
        } else {
            cout << "SALAH" << endl;
        }
    }
    
    else if (b > a) {
        cout << "Input yang anda masukkan salah" << endl;
    }

    cin.get() ;
}
