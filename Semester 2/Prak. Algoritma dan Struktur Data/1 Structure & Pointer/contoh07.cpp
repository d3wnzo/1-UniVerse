#include <iostream>
using namespace std;

struct Node {
    int NilaiUTS;
    int NilaiUAS;
    int N1, N2; };
    Node *P, *Q;

int main(){
    P = new Node;
    P -> N1 = 99;
    Q = new Node;  
    Q -> N2 = 78;

    //Menampilkan isi Variabel
    cout << endl;
    cout << "Isi Variabel P = " << P -> N1 << endl;
    cout << "Isi Variabel Q = " << Q -> N2 << endl;
    cout << endl;
    cin.get(); 
}