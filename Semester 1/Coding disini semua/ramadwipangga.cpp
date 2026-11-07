#include <iostream>
using namespace std;

int main()
{
	int n = 44;
	int *pn = &n;
	
	cout << endl;
	cout << "	Alamat Address [pn]	=	" << pn << endl;
	cout << "=================================" << endl;
	cout << endl;
	
	int m = *pn;
	
	cout << "	Isi Variabel m		=	" << m << endl;
	cout << "=================================" << endl;
	cout << endl;
	
	cin.get();
}