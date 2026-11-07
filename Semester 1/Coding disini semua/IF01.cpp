/* Menampilkan bilangan ---IF01
Nama	: Nayunda Krisna A.P.
NPM		: 4524210077
Materi	: IF
Date	: 9 Oktober 2024 */

#include <iostream>
using namespace std;

int main()
{
// Deklarasi Variabel
	int N,P;
	
// Deskripsi
	cout << "Masukkan Nilai Bilangan Pembagi (N) =		"; cin >> N;
	cout << "Masukkan Nilai Bilangan Pembagi (P) =		"; cin >> P;
	cout << endl;
	
	if (N % P == 0)
		cout << " Jawabannya adalah BENAR" << endl;
	else cout << " Jawabannya adalah SALAH" << endl;
	
cin.get();
}