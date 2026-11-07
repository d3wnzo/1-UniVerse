#include <iostream>
using namespace std;

int main()
{
    int n,*pn,**ppn;
    n = 44;
    //inisialisasi pointer pn dengan alamat addres n
    pn = &n;
    //inisialisasi pointer ppn dengan isi variabel dalam hexa
    ppn = &pn;
    //menampilkan isi variabel, address dan isi variabel dalam hexa n
    cout << endl;
    cout << " isi variabel [n - *pn - *ppn] = " <<n<< " - " <<*pn<<" - " <<*ppn<< endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " isi variabel [&n - &pn - &ppn] = " <<&n<< " - " <<&pn<<" - " <<&ppn<< endl;
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << " isi variabel [n - pn - ppn] = " <<n<< " - " <<pn<<" - " <<ppn<< endl; 
    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << endl;
}