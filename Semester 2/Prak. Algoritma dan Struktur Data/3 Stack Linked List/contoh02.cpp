#include <stdio.h>
#include <iostream>
#include <stdlib.h>     // untuk library fungsi malloc
#include <string.h>

using namespace std;

void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();

struct Node {         // Deklarasi struktur simpul
    int INFO;
    struct Node *LINK;
};

typedef struct Node simpul;

simpul *P, *FIRST, *LAST, *Q;  // Menyiapkan pointer yang dapat menunjuk ke simpul
int X;

int main() {
    int A[] = {22, 28, 7, 11, 66, 63, 10}; // Data yang disimpan ke dalam INFO
    int I;
    FIRST = NULL; // Inisialisasi linked list
    I = 0;
    X = A[I];
    BUAT_SIMPUL(X);
    I = 0;
    AWAL(); // Menyiapkan simpul awal

    for (I = 1; I <= 6; I++) { // Menambahkan 6 simpul baru dan insert kanan agar terbentuk linked list
        X = A[I];
        BUAT_SIMPUL(X);
        INSERTKANAN();
    }

    cout << "Nilai Sebelum Dilakukan Insert Kanan : ";
    CETAK();

    X = 100;
    BUAT_SIMPUL(X);
    INSERTKANAN(); // Menginsert simpul baru di sebelah kanan dengan INFO = 999

    cout << "\nNilai Setelah Dilakukan Insert Kanan : ";
    CETAK();

    cin.get();
    cin.get();

    return 0;
}

// Fungsi membuat sebuah simpul baru
void BUAT_SIMPUL(int X) {
    P = (simpul*) malloc(sizeof(simpul));
    if (P == NULL) {
        cout << "Pembuatan Simpul Tidak Berhasil" << endl;
        cin.get();
        exit(1);
    } else {
        P->INFO = X;
        P->LINK = NULL;
    }
}

// Fungsi membuat simpul awal
void AWAL() {
    FIRST = P;
    LAST = P;
    P->LINK = NULL;
}

// Fungsi menginsert simpul di sebelah kanan
void INSERTKANAN() {
    LAST->LINK = P;
    LAST = P;
    P->LINK = NULL;
}

// Fungsi mencetak isi seluruh simpul
void CETAK() {
    int X;
    Q = FIRST;
    while (Q != NULL) {
        X = Q->INFO;
        cout << X << " ";
        Q = Q->LINK;
    }
    cout << endl;
}