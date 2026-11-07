#include <iostream>
using namespace std;


int opmat01(int x, int y, int z) {
    return x + (y * z);
}

int main() {

    int X = 10;
    int Y = 20;
    int Z = 30;


    int hasil = opmat01(X, Y, Z);


    cout << "Hasil dari operasi (X + Y * Z) adalah: " << hasil << endl;

    return 0;
}
