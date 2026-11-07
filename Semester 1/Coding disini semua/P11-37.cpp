#include <iostream>
#include <vector>
using namespace std;

void displayArray(const vector<char>& arr) {
    for (char ch : arr) {
        cout << ch << " ";
    }
    cout << endl;
}

void insertionSort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Step " << i << ": ";
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
    insertionSort(arr);

    cout << "\nArray setelah diurutkan: ";
    displayArray(arr);

    return 0;
}