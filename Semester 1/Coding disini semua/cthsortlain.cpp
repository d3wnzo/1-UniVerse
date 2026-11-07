#include <iostream>
#include <string.h>
#define n 9
using namespace std;

int main()
{
	int krzi, krzk, krzX;
	int A[n] = {23, 17, 14, 6, 13, 10, 1, 5, 7};
	cout << "Sebelum Dilakukan Pengurutan" << endl;
	cout << "============================" << endl;
	cout << endl;
	for(krzk=0; krzi<=n-1; krzi++)
		cout << A[krzi] << "	";
		cout << endl;
		
	for(krzk=0; krzk<=n; krzk++)
	{
		krzi=krzk;
		krzX=A[krzi];
		while(krzi>=0 && A[krzi-1] > krzX)
		{
			A[krzi] = A[krzi-1];
			krzi--;
		}
		A[krzi]=krzX;
	
	}
	cout << "Sesudah Dilakukan Pengurutan" << endl;
	cout << "============================" << endl;
	cout << endl;
	for(krzi=0; krzi<=n-1; krzi++)
	cout << A[krzi] << "	";
cout << endl;
cout << endl;

cin.get();
}