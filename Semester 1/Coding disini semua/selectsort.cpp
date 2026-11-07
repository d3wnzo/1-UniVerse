#include <iostream>
#include <string.h>
#define n 9
using namespace std;

int krzi, krzj, krzk, krzX;

void Tampil1()
{
	int A[n] = {23, 17, 14, 6, 13, 10, 1, 5, 7};
	cout << "Sebelum Dilakukan Pengurutan" << endl;
	cout << "============================" << endl;
	cout << endl;
	for(krzi=0; krzi<n-1; krzi++)
		cout << A[krzi] << "	";
		cout << endl;
		cout << endl;
}
void Tampil2()
{
	int A[n];
	cout << "Step By Step Dilakukan Pengurutan" << endl;
	cout << "=================================" << endl;
	cout << endl;
	krzk=0;
	while(krzk<=n-2)	{
		krzj=krzk;
		krzi=krzk+1;
		while(krzi<=n-1)	{
			if(A[krzi] > A[krzj])
				krzj=krzi;
				cout << A[krzi] << "	";
			krzi++;			}
		cout << endl;
		krzX = A[krzj];
		A[krzj] = A[krzk];
		A[krzk] = krzX;
		krzk++;			}
	cout << endl;	cout << endl;	}
	
void Tampil3()
{
	int A[n];
	cout << "Sesudah Dilakukan Pengurutan" << endl;
	cout << "============================" << endl;
	cout << endl;
	for (krzi=0; krzi<=n-1; krzi++)
		cout << A[krzi] << "	";
}

int main()
{
	Tampil1();
	Tampil2();
	Tampil3();
	cout << endl;
	
	cin.get();
}