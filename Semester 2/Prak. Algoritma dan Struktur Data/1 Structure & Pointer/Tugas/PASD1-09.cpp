#include <iostream>
#include <string>
using namespace std;

struct MataKuliah {
    string namaMK;
    int sks;
    float nilai;
};

struct Mahasiswa {
    string nama;
    string nim;
    int jumlahMK;
    MataKuliah* mataKuliah;
};

float hitungIPK(Mahasiswa* mhs) {
    float totalNilai = 0;
    int totalSks = 0;
    for (int i = 0; i < mhs->jumlahMK; i++) {
        totalNilai += mhs->mataKuliah[i].nilai * mhs->mataKuliah[i].sks;
        totalSks += mhs->mataKuliah[i].sks;
    }
    return totalNilai / totalSks;
}

int main() {
    Mahasiswa* mhs = new Mahasiswa;
    cout << "Masukkan nama mahasiswa: ";
    getline(cin, mhs->nama);

    cout << "Masukkan NIM mahasiswa: ";
    getline(cin, mhs->nim);

    cout << "Masukkan jumlah mata kuliah yang diambil: ";
    cin >> mhs->jumlahMK;
    cin.ignore();

    mhs->mataKuliah = new MataKuliah[mhs->jumlahMK];

    for (int i = 0; i < mhs->jumlahMK; i++) {
        cout << "Masukkan nama mata kuliah ke-" << i + 1 << ": ";
        getline(cin, mhs->mataKuliah[i].namaMK);
        
        cout << "Masukkan SKS untuk mata kuliah " << mhs->mataKuliah[i].namaMK << ": ";
        cin >> mhs->mataKuliah[i].sks;

        cout << "Masukkan nilai untuk mata kuliah " << mhs->mataKuliah[i].namaMK << ": ";
        cin >> mhs->mataKuliah[i].nilai;
        cin.ignore();
    }

    cout << "\n--- Data Mahasiswa ---\n";
    cout << "Nama: " << mhs->nama << endl;
    cout << "NIM: " << mhs->nim << endl;
    cout << "Jumlah Mata Kuliah: " << mhs->jumlahMK << endl;
    
    int totalSks = 0;
    for (int i = 0; i < mhs->jumlahMK; i++) {
        totalSks += mhs->mataKuliah[i].sks;
    }

    cout << "Total SKS yang diambil: " << totalSks << endl;

    float ipk = hitungIPK(mhs);
    cout << "IPK: " << ipk << endl;

    delete[] mhs->mataKuliah;
    delete mhs;

    return 0;
}