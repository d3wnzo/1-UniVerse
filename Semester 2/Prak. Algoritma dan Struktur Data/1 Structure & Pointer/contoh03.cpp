#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//nama struct
struct pelanggan_toko       {
    string nama[20], alamat[20], kelamin[2], telp[20];
    int umur[3];    };
pelanggan_toko data;
int main()      {
    int jumlah,i;
    cout << endl;
    cout << "INPUT DATA PELANGGAN   " << endl;
    cout << "Jumlah pelanggan   :   "; cin >> jumlah;
//Input Data
for (i=1; i<=jumlah; i++)       {
    cout << endl;
    cout << "Nama Pelanggan Toko            : "; cin >> data.nama[i];
    cout << "Alamat Pelanggan Toko          : "; cin >> data.alamat[i];
    cout << "Umur Pelanggan Toko            : "; cin >> data.umur[i];
    cout << "Jenis Kelamin Pelanggan [L/P]  : "; cin >> data.kelamin[i];
    cout << "No Telp Pelanggan              : "; cin >> data.telp[i];
    cout << endl;   }
cout << endl;   //Menampilkan Data
cout << "============================================" << endl;
cout << "           Data Pelanggan Toko : " << endl;
cout << "============================================" << endl;
cout << " Nama  | Alamat | Umur | Kelamin |  No telp " << endl;
cout << "============================================" << endl;
for (i=1; i<jumlah+1; i++)  {
    cout << setw (5) << data.nama[i] << setw (10) << data.alamat [i] << setw(10) << data.umur[i];
    cout << setw (10) << data.kelamin[i] << setw (10) << data.telp << setw (10);
    cout << endl;   }
cout << "============================================" << endl;
cout << endl;
cin.get();      }