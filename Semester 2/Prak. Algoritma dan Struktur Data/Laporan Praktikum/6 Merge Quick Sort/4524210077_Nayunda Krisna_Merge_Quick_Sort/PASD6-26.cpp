#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DataArray {
    vector<int> arr;
    int ukuran;
};

void merge(DataArray* data, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = data->arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = data->arr[tengah + 1 + j];

    int i = 0, j = 0;
    int k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data->arr[k] = L[i];
            i++;
        } else {
            data->arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data->arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data->arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(DataArray* data, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        mergeSort(data, kiri, tengah);
        mergeSort(data, tengah + 1, kanan);

        merge(data, kiri, tengah, kanan);
    }
}

void cetakData(const DataArray* data, const string& keterangan) {
    cout << keterangan << endl;
    for (int i = 0; i < data->ukuran; i++) {
        cout << data->arr[i] << (i == data->ukuran - 1 ? "" : " ");
    }
    cout << endl << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    DataArray data;
    data.ukuran = n;
    data.arr.resize(n);

    cout << "Masukkan " << n << " elemen array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data.arr[i];
    }

    cetakData(&data, "Data SEBELUM diurutkan:");

    mergeSort(&data, 0, data.ukuran - 1);

    cetakData(&data, "Data SETELAH diurutkan (Ascending):");

    return 0;
}