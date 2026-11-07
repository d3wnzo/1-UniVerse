#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string namaBarang;
    int jumlahBarang;
    float hargaBarang;
};

struct Pelanggan {
    string nama;
    string alamat;
    string telepon;
    int jumlahBarangDibeli;
    Barang* barang;
};

float hitungTotalBayar(Pelanggan* pelanggan) {
    float totalBayar = 0;
    for (int i = 0; i < pelanggan->jumlahBarangDibeli; i++) {
        totalBayar += pelanggan->barang[i].jumlahBarang * pelanggan->barang[i].hargaBarang;
    }
    return totalBayar;
}

int main() {
    int jumlahPelanggan;

    
    cout << "Masukkan jumlah pelanggan: ";
    cin >> jumlahPelanggan;
    cin.ignore();

    Pelanggan* pelanggan = new Pelanggan[jumlahPelanggan];

    for (int i = 0; i < jumlahPelanggan; i++) {
        cout << "\nMasukkan data untuk pelanggan ke-" << i + 1 << ":\n";
        cout << "Nama pelanggan: ";
        getline(cin, pelanggan[i].nama);

        cout << "Alamat pelanggan: ";
        getline(cin, pelanggan[i].alamat);

        cout << "Telepon pelanggan: ";
        getline(cin, pelanggan[i].telepon);

        cout << "Masukkan jumlah barang yang dibeli: ";
        cin >> pelanggan[i].jumlahBarangDibeli;
        cin.ignore(); 

        pelanggan[i].barang = new Barang[pelanggan[i].jumlahBarangDibeli];

        for (int j = 0; j < pelanggan[i].jumlahBarangDibeli; j++) {
            cout << "Masukkan nama barang ke-" << j + 1 << ": ";
            getline(cin, pelanggan[i].barang[j].namaBarang);

            cout << "Masukkan jumlah barang " << pelanggan[i].barang[j].namaBarang << ": ";
            cin >> pelanggan[i].barang[j].jumlahBarang;

            cout << "Masukkan harga barang " << pelanggan[i].barang[j].namaBarang << ": ";
            cin >> pelanggan[i].barang[j].hargaBarang;
            cin.ignore();
        }
    }

    for (int i = 0; i < jumlahPelanggan; i++) {
        cout << "\n--- Data Pelanggan ke-" << i + 1 << " ---\n";
        cout << "Nama: " << pelanggan[i].nama << endl;
        cout << "Alamat: " << pelanggan[i].alamat << endl;
        cout << "Telepon: " << pelanggan[i].telepon << endl;
        cout << "Jumlah barang yang dibeli: " << pelanggan[i].jumlahBarangDibeli << endl;

        float totalBayar = hitungTotalBayar(&pelanggan[i]);
        cout << "Total bayar: Rp " << totalBayar << endl;

        delete[] pelanggan[i].barang;
    }

    delete[] pelanggan;

    return 0;
}