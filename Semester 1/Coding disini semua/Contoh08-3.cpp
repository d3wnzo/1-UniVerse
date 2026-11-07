#include <iostream>
using namespace std;

int main()
{
	int Nilai[4][4];
	int i, j;
	cout << endl;
	cout << "Menampilkan ARRAY/LARIK 2 Dimensi" << endl;
	cout << "	Dengan Ordo 4x4			  " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	cout << endl;
	for (i=0; i<4; i++)			{
		for (j=0; j<i+1;j++)	{
			cout << "Masukkan Isi Elemen" << endl;
			cin >> Nilai[i][j];	}	}
	cout << endl;
	cout << "Tampilkan Isi Elemen" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	for (i=0; i<4;j++)		{
		for (j=0; j<i+;j++)
			cout << Nilai[i][j] << "	";
			cout << endl;	}
	return 0;
}