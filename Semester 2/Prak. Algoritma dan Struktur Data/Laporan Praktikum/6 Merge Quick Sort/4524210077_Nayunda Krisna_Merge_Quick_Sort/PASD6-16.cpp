#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>& a, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main() {
    int num;

    cout << "<< PROGRAM PENGURUTAN MERGE SORT >>" << endl;
    cout << "------------------------------------" << endl;
    cout << "Masukkan Jumlah Bilangan Yang Diinginkan: ";
    cin >> num;

    vector<int> arr(num);

    cout << "Masukkan " << num << " buah bilangan:" << endl;
    for (int i = 0; i < num; i++) {
        cout << "Bilangan ke-" << i + 1 << " : ";
        cin >> arr[i];
    }

    cout << "\nProses Pengurutan..." << endl;
    MergeSort(arr, 0, num - 1);

    cout << "\nHasil Akhir Pengurutan:" << endl;
    cout << "[ ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << (i == num - 1 ? "" : ", ");
    }
    cout << " ]" << endl;

    return 0;
}