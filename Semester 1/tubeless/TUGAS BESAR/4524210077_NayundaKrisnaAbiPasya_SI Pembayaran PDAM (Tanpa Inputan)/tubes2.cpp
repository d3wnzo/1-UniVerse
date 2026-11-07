// Nama		: Nayunda Krisna Abi Pasya
// NPM		: 4524210077
// MatKul	: Algoritma dan Pemrograman
// Materi	: Selection, Repetition, Array, Function, Pointer, Insertion Sort (DESC)

#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data pelanggan
struct Pelanggan {
    string nama;
    int jumlahPemakaian;
    float tagihan;
};

// Menghitung tagihan berdasarkan pemakaian (Selection)
float hitungTagihan(int pemakaian) {
    float tarif = 0;
    if (pemakaian <= 10) {
        tarif = pemakaian * 2000;
    } else if (pemakaian <= 20) {
        tarif = (10 * 2000) + ((pemakaian - 10) * 3000);
    } else {
        tarif = (10 * 2000) + (10 * 3000) + ((pemakaian - 20) * 5000);
    }
    return tarif;
}

// Melakukan insertion sort berdasarkan tagihan
void insertionSort(Pelanggan* pelanggan, int n) {
    for (int i = 1; i < n; i++) {
        Pelanggan key = pelanggan[i];
        int j = i - 1;
        while (j >= 0 && pelanggan[j].tagihan > key.tagihan) {
            pelanggan[j + 1] = pelanggan[j];
            j--;
        }
        pelanggan[j + 1] = key;
    }
}

// Fungsi untuk mencetak data pelanggan
void cetakPelanggan(Pelanggan* pelanggan, int n) {
    cout << "Daftar Pelanggan dan Tagihan PDAM:" << endl;
    cout << "----------------------------------" << endl;
    cout << "No\tNama\tPemakaian (m3)\tTagihan (Rp)" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << pelanggan[i].nama << "\t" 
             << pelanggan[i].jumlahPemakaian << "\t\t" 
             << pelanggan[i].tagihan << endl;
    }
}

int main() {
    // Data pelanggan (tanpa inputan)
    const int jumlahPelanggan = 5;
    Pelanggan pelanggan[jumlahPelanggan] = {
        {"Krisna", 15, 0},
        {"Sebraw", 20, 0},
        {"Yanto", 25, 0},
        {"Lawir", 12, 0},
        {"Rully", 5, 0}
    };

    // Menghitung tagihan untuk setiap pelanggan
    for (int i = 0; i < jumlahPelanggan; i++) {
        pelanggan[i].tagihan = hitungTagihan(pelanggan[i].jumlahPemakaian);
    }

    // Mengurutkan pelanggan berdasarkan tagihan
    insertionSort(pelanggan, jumlahPelanggan);

    // Mencetak data pelanggan
    cetakPelanggan(pelanggan, jumlahPelanggan);

    return 0;
}