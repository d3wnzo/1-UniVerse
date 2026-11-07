#include <iostream>
using namespace std;

int main ()
{
	// Deklarasi
	int A;
	
	// Deskripsi
	cout << endl;
	cout << "Masukkan angka = "; cin >> A;
	cout << endl;
	
	if (A % 2 == 0) {
		cout << "Bilangan GENAP" << endl;
	}
	else {
		cout << "Bilangan GANJIL" << endl;
	}
cin.get();
}