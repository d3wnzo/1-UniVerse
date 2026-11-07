#include <iostream>
using namespace std;

int main()
{
int n_tegar = 1;
for(int k_tegar = 1; k_tegar <= 3; k_tegar++){
cout << "k_tegar = " << k_tegar << endl;

  for(int m_tegar = 1; m_tegar <=4; m_tegar++){
  cout << "m_tegar = " << m_tegar << endl;
  
   n_tegar = 1;
   
   for(int i_tegar = 1; i_tegar <=4; i_tegar++){
   
    n_tegar = n_tegar*3+1;
	cout <<" n_tegar = " << n_tegar << endl;
	}
   }
  }
cin.get();
}
  