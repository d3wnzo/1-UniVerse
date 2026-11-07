#include <iostream>
#include <stack>

using namespace std;

void pindah(stack<int>& asal, stack<int>& tujuan, const string& namaAsal, const string& namaTujuan) {
    if (!asal.empty()) {
        int elemen = asal.top();
        asal.pop();
        tujuan.push(elemen);
        cout << "Memindahkan " << elemen << " dari " << namaAsal << " ke " << namaTujuan << endl;
    }
}

void hanoi(int n, stack<int>& asal, stack<int>& tujuan, stack<int>& perantara, 
           const string& namaAsal, const string& namaTujuan, const string& namaPerantara) {
    if (n > 0) {
        hanoi(n - 1, asal, perantara, tujuan, namaAsal, namaPerantara, namaTujuan);
        pindah(asal, tujuan, namaAsal, namaTujuan);
        hanoi(n - 1, perantara, tujuan, asal, namaPerantara, namaTujuan, namaAsal);
    }
}

int main() {
    stack<int> tumpukan1, tumpukan2, tumpukan3;
    int jumlah = 3; 

    for (int i = jumlah; i >= 1; --i) {
        tumpukan1.push(i);
    }

    cout << "Proses pemindahan stack:\n";
    hanoi(jumlah, tumpukan1, tumpukan3, tumpukan2, "Tumpukan 1", "Tumpukan 3", "Tumpukan 2");

    return 0;
}