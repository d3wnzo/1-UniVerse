#include <iostream>
#include <string>
using namespace std;

//Deklarasi Struktur
struct Koordinat    {
    int X;
    int Y;  };
//Prototipe
void Tampil_Posisi (Koordinat Posisi);

int main ()     {
//Pendefinisian Variabel Struktur
Koordinat Posisi;
//Pengaksesan Anggota Struktur
Posisi.X    = 56;
Posisi.Y    = 53;
cout << endl;
Tampil_Posisi (Posisi);
cin.get ();     }

//Definisi fungsi TAMPIL_POSISI
void Tampil_Posisi (Koordinat Posisi)   {
    cout << "Posisi Koordinat X adalah " << Posisi.X << endl;
    cout << "Posisi Koordinat Y adalah " << Posisi.Y << endl;   }