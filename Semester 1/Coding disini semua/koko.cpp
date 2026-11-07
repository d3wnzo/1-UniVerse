#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char kalimat_krz[] = "TEKNIK INFORMATIKA FAKULTAS TEKNIK UNIVERSITAS PANCASILA";
    char substring_krz[] = "TEKNIK";
    char tambahan_krz[] = "_krz";

    cout << "Kalimat lengkap sebelum perubahan: " << kalimat_krz << endl;
    cout << "Substring yang dicari: " << substring_krz << endl << endl;

    // Mencari substring
    char* ditemukan_krz = strstr(kalimat_krz, substring_krz);

    if (ditemukan_krz != nullptr) {
        cout << "Substring '" << substring_krz << "' ditemukan!" << endl;

        char hasil_krz[200]; // Buffer untuk menyimpan hasil
        int posisi_krz = ditemukan_krz - kalimat_krz;

        // Salin bagian sebelum substring
        strncpy(hasil_krz, kalimat_krz, posisi_krz);
        hasil_krz[posisi_krz] = '\0';

        // Tambahkan substring dan tambahan "_krz"
        strcat(hasil_krz, substring_krz);
        strcat(hasil_krz, tambahan_krz);

        // Tambahkan bagian setelah substring
        strcat(hasil_krz, ditemukan_krz + strlen(substring_krz));

        // Tampilkan hasil akhir
        cout << "Kalimat setelah ditambahkan '_krz': " << hasil_krz << endl;
    } else {
        cout << "Substring '" << substring_krz << "' tidak ditemukan." << endl;
    }

    return 0;
}
