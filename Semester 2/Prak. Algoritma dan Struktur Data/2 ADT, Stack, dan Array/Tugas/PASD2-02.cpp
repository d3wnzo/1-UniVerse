#include <iostream>
#include <string>

using namespace std;

class Menu {
public:
    string namaMenukrz;
    int hargakrz;

    Menu(string namakrz, int hargakrz) {
        namaMenukrz = namakrz;
        this->hargakrz = hargakrz;
    }

    Menu() {
        namaMenukrz = "";
        hargakrz = 0;
    }
};

void tampilkanMenu() {
    cout << "      Menu Rumah Makan SHALERO    " << endl;
    cout << "==================================" << endl;
    cout << "1. Nasi Goreng - Rp 5.000" << endl;
    cout << "2. Gado-gado - Rp 3.500" << endl;
    cout << "3. Bubur Ayam - Rp 2.500" << endl;
    cout << "4. Ayam Bakar Pedas - Rp 7.500" << endl;
    cout << "Masukkan menu pilihan (1-4): ";
}

int main() {
    Menu menu1("Nasi Goreng", 5000);
    Menu menu2("Gado-gado", 3500);
    Menu menu3("Bubur Ayam", 2500);
    Menu menu4("Ayam Bakar Pedas", 7500);

    Menu menuDipilih;

    int pilihanPelanggan;
    bool menuValid = false;

    tampilkanMenu();
    cin >> pilihanPelanggan;

    switch (pilihanPelanggan) {
        case 1:
            menuDipilih = menu1;
            menuValid = true;
            break;
        case 2:
            menuDipilih = menu2;
            menuValid = true;
            break;
        case 3:
            menuDipilih = menu3;
            menuValid = true;
            break;
        case 4:
            menuDipilih = menu4;
            menuValid = true;
            break;
        default:
            cout << "Pilihan Anda Salah" << endl;
            break;
    }


    if (menuValid) {
        cout << "Anda memilih: " << menuDipilih.namaMenukrz << endl;
        cout << "Harga: Rp " << menuDipilih.hargakrz << endl;
    }

    return 0;
}