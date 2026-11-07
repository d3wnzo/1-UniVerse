#include <iostream>
#include <ctype.h>
using namespace std;

int main()      {
    int i;
    char *namaKu, NM[6] = {'K', 'R', 'I', 'S', 'N', 'A'};
    cout << "   nama KU  " << endl;
    cout << " =========== " << endl;
    for (i=0; i<6; i++)
    {
    namaKu = &NM[i];
    cout << "   " << *namaKu << endl;
    }
    cin.get();      }