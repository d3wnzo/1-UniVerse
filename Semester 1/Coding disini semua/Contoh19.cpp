#include <iostream>
using namespace std;
	
int main() {
	int k, i, n;
	
	cout << endl;
	cout << "   Menampilkan Pengulangan 4X (k) dan 6X (i)   " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	
	n = 0;
	
	for (k = 1; k <= 4; k++) {
		for (i = k; i <= 6; i++) {
			n += 5;
		}
	}
	cout << "Nilai Akhir dari N adalah " << n << endl;
	
	cin.get();
}