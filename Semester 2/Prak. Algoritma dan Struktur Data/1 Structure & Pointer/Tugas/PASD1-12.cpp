#include <iostream>
using namespace std;

struct KTP {
    int NOKTP;
    string Nama;
    struct Alamat {
        string Jalan;
        string Kota;
        int KodePos;
    } Alamat;
    struct Lahir {
        int Tanggal;
        int Bulan;
        int Tahun;
    } Lahir;
};

int main() {
    KTP JatiDiri;
    cout << "Masukkan No KTP    = "; cin >> JatiDiri.NOKTP;
    cout << "Masukkan Nama      = "; cin >> JatiDiri.Nama;
    cout << "Alamat" << endl;
    cout << "   - Jalan         = "; cin >> JatiDiri.Alamat.Jalan;
    cout << "   - Kota          = "; cin >> JatiDiri.Alamat.Kota;
    cout << "   - Kode Pos      = "; cin >> JatiDiri.Alamat.KodePos;
    cout << "Tanggal Lahir" << endl;
    cout << "   - Tanggal       = "; cin >> JatiDiri.Lahir.Tanggal;
    cout << "   - Bulan         = "; cin >> JatiDiri.Lahir.Bulan;
    cout << "   - Tahun         = "; cin >> JatiDiri.Lahir.Tahun;
    cout << endl;

    cout << "No KTP             = " << JatiDiri.NOKTP << endl;
    cout << "Nama               = " << JatiDiri.Nama << endl;
    cout << "Alamat             = " << JatiDiri.Alamat.Jalan << ", "
         << JatiDiri.Alamat.Kota    << ", " << JatiDiri.Alamat.KodePos << endl;
    cout << "Tanggal Lahir      = " << JatiDiri.Lahir.Tanggal << "-"
         << JatiDiri.Lahir.Bulan    << "-" << JatiDiri.Lahir.Tahun << endl;

         cin.get ();
}