#include <iostream>
using namespace std;

int main() {
	int ips, ipsTertinggi = 0, jumlah = 0;
	char lagi;

	do {
		cout << "Masukkan IPS: ";
		cin >> ips;

		if (ips > ipsTertinggi) {
			ipsTertinggi = ips;
			jumlah = 1;

		} else if (ips == ipsTertinggi) {
		jumlah++;
		}
		
		cout << "Apakah Anda ingin memasukkan IPS lagi? (y/n): ";
		cin >> lagi;
	} while (lagi == 'y' || lagi == 'Y');
	cout <<endl;
	cout << "IPS tertinggi: " << ipsTertinggi << endl;
	cout << "Jumlah mahasiswa dengan IPS tertinggi: " << jumlah << " orang" << endl;
	
cin.get();
}