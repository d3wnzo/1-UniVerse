#include <iostream>
#include <string>
#include <limits>

using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct {
    int first;
    int last;
    NilaiMK Dat[10];
} queue;

void buatQUkosong(queue *Q) {
    (*Q).first = -1;
    (*Q).last = -1;
}

bool IsKosong(queue Q) {
    bool hasil = false;
    if (Q.first == -1) {
        hasil = true;
    }
    return hasil;
}

bool IsPenuh(queue Q) {
    bool hasil = false;
    if (Q.last == 9) {
        hasil = true;
    }
    return hasil;
}

void ADD(string npm, string nama_mhs, double nilai, queue *Q) {
    if (IsKosong(*Q)) {
        (*Q).first = 0;
        (*Q).last = 0;
        (*Q).Dat[0].npm = npm;
        (*Q).Dat[0].nama_mhs = nama_mhs;
        (*Q).Dat[0].nilai = nilai;
    } else {
        if (!IsPenuh(*Q)) {
            (*Q).last = (*Q).last + 1;
            (*Q).Dat[(*Q).last].npm = npm;
            (*Q).Dat[(*Q).last].nama_mhs = nama_mhs;
            (*Q).Dat[(*Q).last].nilai = nilai;
        } else {
            cout << "QUEUE PENUH!" << endl;
        }
    }
}

void DEL(queue *Q) {
    if (IsKosong(*Q)) {
        cout << "QUEUE KOSONG! Tidak ada yang bisa dihapus." << endl;
    } else {
        for (int i = (*Q).first; i < (*Q).last; i++) {
            (*Q).Dat[i] = (*Q).Dat[i + 1];
        }
        (*Q).last = (*Q).last - 1;
        if ((*Q).last < (*Q).first) {
            (*Q).first = -1;
            (*Q).last = -1;
        }
        cout << "Satu elemen telah dihapus dari queue." << endl;
    }
}

void CetakQueue(queue Q) {
    if (IsKosong(Q)) {
        cout << "QUEUE KOSONG" << endl;
    } else {
        cout << "======== MENAMPILKAN QUEUE ========" << endl;
        cout << "------------------------------------" << endl;
        for (int i = Q.first; i <= Q.last; i++) {
            cout << "Elemen ke-" << i + 1 << " : " << endl;
            cout << "  Nomor Pokok Mahasiswa : " << Q.Dat[i].npm << endl;
            cout << "  Nama Mahasiswa      : " << Q.Dat[i].nama_mhs << endl;
            cout << "  Nilai Mahasiswa     : " << Q.Dat[i].nilai << endl;
            cout << "------------------------------------" << endl;
        }
    }
}

int main() {
    queue Q;
    buatQUkosong(&Q);
    int pilihan;

    do {
        cout << "   ======== MENU OPERASI QUEUE ========" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa (Dequeue)" << endl;
        cout << "3. Tampilkan Isi Queue" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        cin.ignore(numeric_limits<streamsize>::max(), ' ');

        switch (pilihan) {
            case 1: {
                if (!IsPenuh(Q)) {
                    string npm, nama_mhs;
                    double nilai;
                    cout << "Masukkan Nomor Pokok Mahasiswa: ";
                    getline(cin, npm);
                    cout << "Masukkan Nama Mahasiswa: ";
                    getline(cin, nama_mhs);
                    cout << "Masukkan Nilai Mahasiswa: ";
                    cin >> nilai;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    ADD(npm, nama_mhs, nilai, &Q);
                    cout << "Data mahasiswa berhasil ditambahkan ke queue." << endl;
                } else {
                    cout << "Queue sudah penuh. Tidak dapat menambahkan data lagi." << endl;
                }
                break;
            }
            case 2:
                DEL(&Q);
                break;
            case 3:
                CetakQueue(Q);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}