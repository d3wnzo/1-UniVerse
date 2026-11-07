#include <iostream>
using namespace std;
int main()
{
	long int fakt_iter = 1;
	cout << endl;
	cout << "Menampilkan Faktorial - Iterasi" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int n_bil = 1; n_bil <= 5; n_bil++)
	{
	fakt_iter = 1;
	for (int k_bil = 1; k_bil <= n_bil; k_bil++)
	{
	fakt_iter *= k_bil;
	}
	cout << "Faktorial dari " << n_bil << " adalah = " << fakt_iter << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cin.get();
}