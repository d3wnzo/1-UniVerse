#include <iostream>
#include <vector>
using namespace std;

struct DataArray {
    vector<int> arr;
    int ukuran;
};

void cetakData(const DataArray& data, const string& keterangan) {
    cout << keterangan << endl;
    for (int i = 0; i < data.ukuran; i++) {
        cout << data.arr[i] << " ";
    }
    cout << endl << endl;
}

void mergeAscending(DataArray& data, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = data.arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = data.arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data.arr[k++] = L[i++];
        } else {
            data.arr[k++] = R[j++];
        }
    }

    while (i < n1) data.arr[k++] = L[i++];
    while (j < n2) data.arr[k++] = R[j++];
}

void mergeDescending(DataArray& data, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = data.arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = data.arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            data.arr[k++] = L[i++];
        } else {
            data.arr[k++] = R[j++];
        }
    }

    while (i < n1) data.arr[k++] = L[i++];
    while (j < n2) data.arr[k++] = R[j++];
}

void mergeSort(DataArray& data, int kiri, int kanan, bool ascending) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(data, kiri, tengah, ascending);
        mergeSort(data, tengah + 1, kanan, ascending);
        if (ascending) {
            mergeAscending(data, kiri, tengah, kanan);
        } else {
            mergeDescending(data, kiri, tengah, kanan);
        }
    }
}

int main() {
    DataArray data;
    int pilihan;

    cout << "Masukkan jumlah elemen array: ";
    cin >> data.ukuran;
    data.arr.resize(data.ukuran);

    cout << "Masukkan " << data.ukuran << " elemen array:" << endl;
    for (int i = 0; i < data.ukuran; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> data.arr[i];
    }

    do {
        cout << endl << "=== MENU PENGURUTAN MERGE SORT ===" << endl;
        cout << "1. Pengurutan Ascending" << endl;
        cout << "2. Pengurutan Descending" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            DataArray dataAsc = data;
            mergeSort(dataAsc, 0, dataAsc.ukuran - 1, true);
            cetakData(dataAsc, "Hasil pengurutan ASCENDING:");
        } else if (pilihan == 2) {
            DataArray dataDesc = data;
            mergeSort(dataDesc, 0, dataDesc.ukuran - 1, false);
            cetakData(dataDesc, "Hasil pengurutan DESCENDING:");
        } else if (pilihan == 3) {
            cout << "Program selesai. Terima kasih!" << endl;
        } else {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }

    } while (pilihan != 3);

    return 0;
}