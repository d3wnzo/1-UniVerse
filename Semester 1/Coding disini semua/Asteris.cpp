#include <iostream>
using namespace std;

int main()
{
	int gil1, gil2;
	for (int gil1 = 1; gil1 <= 10; gil1++){
		for (int gil2 = 1; gil2 <= gil1; gil2++){
			cout << "*" ;
		}
		cout << endl;
	}
	cin.get();
}