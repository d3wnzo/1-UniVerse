#include <iostream>
#include <string>

using namespace std;

class Hari {
public:
    string getNamaHari(int hari) {
        switch (hari) {
            case 0:
                return "Minggu";
            case 1:
                return "Senin";
            case 2:
                return "Selasa";
            case 3:
                return "Rabu";
            case 4:
                return "Kamis";
            case 5:
                return "Jum'at";
            case 6:
                return "Sabtu";
            default:
                return "Hari tidak valid";
        }
    }
};

int main() {
    int pilihanPelanggan;

    Hari hari;

    cout << "Masukkan angka (0-6) untuk mengetahui hari: ";
    cin >> pilihanPelanggan;

    cout << hari.getNamaHari(pilihanPelanggan) << endl;

    return 0;
}