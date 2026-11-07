#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> NumList = {65, 2, 44, 26, 19, 22, 5, 3, 12};
    int n = NumList.size();

    cout << "Data SEBELUM diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(3) << NumList[i];
    }
    cout << endl << endl;

    quickSort(NumList, 0, n - 1);

    cout << "Data SETELAH diurutkan (Ascending):" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(3) << NumList[i];
    }
    cout << endl;

    return 0;
}