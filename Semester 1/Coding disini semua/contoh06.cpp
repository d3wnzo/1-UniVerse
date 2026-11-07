#include <iostream>
using namespace std;

int main()
{
	long int k,fakt_iter=1;
	cout << endl;
	cout << "Menampilkan Rekursif - FAKTORIAL" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		for(k=1; k<=7; k++)
		{
			fakt_iter = fakt_iter * k;
			cout << "Faktorial dari " << k << "! adalah = " << fakt_iter << endl;
		}
	cin.get();
}