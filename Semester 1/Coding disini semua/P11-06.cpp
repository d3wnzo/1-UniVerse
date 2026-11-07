#include <iostream>
#include <vector>
using namespace std;

void displayArray(vector<char> arr) {
    for (char ch : arr) {
        cout << ch << " ";
    }
    cout << endl;
}

void selectionSort(vector<char>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);

        cout << "Step " << i + 1 << ": ";
        displayArray(arr);
    }
}

int main() {
    vector<char> arr;
    int n;

    cout << "Masukkan jumlah huruf: ";
    cin >> n;

    cout << "Masukkan huruf-hurufnya (tanpa spasi): ";
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "Array sebelum diurutkan: ";
    displayArray(arr);

    cout << "\nProses pengurutan:\n";
    selectionSort(arr);

    cout << "\nArray setelah diurutkan: ";
    displayArray(arr);

    return 0;
}