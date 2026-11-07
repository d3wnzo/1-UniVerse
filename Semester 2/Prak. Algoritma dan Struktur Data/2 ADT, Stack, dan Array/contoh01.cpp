#include <iostream>
#include <string>
using namespace std;

typedef int angka;
typedef float pecahan;
typedef char huruf[30];
int main() {
    angka umur;
    pecahan pecah;
    huruf nama;
    huruf karakter;
    cout << "Masukkan umur anda         : "; cin >> umur;
    cout << "Umur anda adalah " << umur << endl;
    cout << endl;
    cout << "Masukkan bilangan pecahan  : "; cin >> pecah;
    cout << "Bilangan pecahan " << pecah << endl;
    cout << endl;
    cout << "Masukkan nama              : "; cin >> nama;
    cout << "Nama anda " << nama << endl;
    cout << endl;
    cout << "Masukkan satu huruf        : "; cin >> karakter;
    cout << "Huruf anda " << karakter << endl;
cin.get(); }