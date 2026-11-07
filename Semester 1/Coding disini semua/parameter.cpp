#include <iostream>
using namespace std;

int add (int krx, int kry) {
	return krx+kry;
}

int main(){
	int hasil, krx, kry;
	cout << endl;
	cout << "Masukkan Nilai X : " ; cin >> krx ; cout << endl;
	cout << "Masukkan Nilai Y : " ; cin >> kry ; cout << endl;
	
	hasil = add (krx,kry);
	
	cout << "Hasil Fungsi Pertambahan : " << hasil << endl;
}