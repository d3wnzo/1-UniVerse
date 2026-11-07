#include <iostream>
using namespace std;

class Mahasiswa {
    public:
    char NPM[9];
    char nama[30];
    float IPK;
    };
int main() {
    Mahasiswa mhs;
    cout << "Nomor Pokok Mahasiswa      = "; cin >> mhs.NPM;
    cout << "Nama Mahasiswa             = "; cin >> mhs.nama;
    cout << "Indeks Prestasi Komulatif  = "; cin >> mhs.IPK;
    cout << endl;
    cout << "================================================" << endl;
    cout << "                   Data Anda" << endl;
    cout << "================================================" << endl;
    cout << "Nomor Pokok Mahasiswa      = " << mhs.NPM << endl;
    cout << "nama Mahasiswa             = " << mhs.nama << endl;
    cout << "Indeks Prestasi Komulatif  = " << mhs.IPK << endl;
    cin.get();
}