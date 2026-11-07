#include <iostream>
using namespace std;

int main()
{
    //DEKLARASI VARIABEL
    int *pn;
    pn = new int;
    *pn = 87;

    //MENAMPILKAN ISI VARIABEL
    cout << endl;
    cout << "Isi Variabel = " << *pn << endl;
    cout << endl;
    cin.get();
}