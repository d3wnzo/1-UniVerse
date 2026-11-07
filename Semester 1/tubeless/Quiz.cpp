#include <iostream>
#include <string>
using namespace std;

	//rekursif untuk hitun laba 
int hitungTotalHarga(int krzharga[], int krzjumlah[], int krzn) {
    if (krzn == 0) {
        return 0;
    }
    return krzharga[krzn - 1] * krzjumlah[krzn - 1] + hitungTotalHarga(krzharga, krzjumlah, krzn - 1);
}

int main() {
    //Sequence
    string jenisHelm[] = {"Helm Full Face", "Helm Half Face", "Helm Modular", "Helm Off-Road", "Helm Retro"};
    int hargaHelm[] = {500000, 300000, 450000, 550000, 350000};
    int jumlahTerjual[] = {3, 2, 0, 1, 1};

    //Array
    int jumlahJenisHelm = 5;

    //Sequence: Tampilkan daftar helm
    cout << "--- Penjualan Helm ---" << endl;
    cout << "Jenis Helm       | Harga   | Terjual | Subtotal" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    //Repetition: Mengulang untuk menampilkan data helm
    for (int i = 0; i < jumlahJenisHelm; i++) {
        int subtotal = hargaHelm[i] * jumlahTerjual[i];
        cout << jenisHelm[i] << "	 | " << hargaHelm[i]
             << " | " << jumlahTerjual[i]
             << " | " << subtotal << endl;
    }

    //Selection Menentukan apakah total pendapatan di atas target tertentu
    int totalPendapatan = hitungTotalHarga(hargaHelm, jumlahTerjual, jumlahJenisHelm);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Total Pendapatan: " << totalPendapatan << endl;

    int targetPendapatan = 5000000;

    if (totalPendapatan >= targetPendapatan) {
        cout << "Selamat! Target penjualan tercapai." << endl;
    } else {
        cout << "Target belum tercapai, tingkatkan penjualan!" << endl;
    }

    cin.get();
}