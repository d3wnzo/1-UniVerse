#include <iostream>
#include <vector>

using namespace std;

int main() {
	
    int n, ips, maxIPS = 0, jumlahMax = 0;

    cout << "Masukkan Jumlah Mahasiswa: ";
    cin >> n;

    vector<int> dataIPS(n);
    cout << "Masukkan IPS setiap mahasiswa:\n";
    for (int i = 0; i < n; i++) {
        cin >> dataIPS[i];
        if (dataIPS[i] > maxIPS) {
            maxIPS = dataIPS[i];
            jumlahMax = 1;
        } else if (dataIPS[i] == maxIPS) {
            jumlahMax++;
        }
    }

    cout << "IPS tertinggi: " << maxIPS << endl;
    cout << "Jumlah mahasiswa dengan IPS tertinggi: " << jumlahMax << " orang" << endl;

    cin.get();
}
