#include <iostream>
using namespace std;

int main(){
	for (int razak1 = 1; razak1 <= 5; razak1++){
		for (int razak2 = 1; razak2 <= razak1; razak2++){
			cout << "*";
		}
		cout << endl;
	}
}