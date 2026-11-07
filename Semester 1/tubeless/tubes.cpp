#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk pelanggan
struct Customer {
    string name;
    double payment;
};

// Fungsi untuk menampilkan daftar pelanggan
void displayCustomers(Customer* customers, int size) {
    cout << "Daftar Pembayaran Pelanggan:\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". Nama: " << customers[i].name << ", Pembayaran: Rp " << customers[i].payment << endl;
    }
    cout << endl;
}

// Fungsi untuk mengurutkan pelanggan berdasarkan pembayaran menggunakan insertion sort
void sortCustomersByPayment(Customer* customers, int size) {
    for (int i = 1; i < size; i++) {
        Customer key = customers[i];
        int j = i - 1;

        // Geser elemen yang lebih besar dari key ke posisi berikutnya
        while (j >= 0 && customers[j].payment > key.payment) {
            customers[j + 1] = customers[j];
            j--;
        }
        customers[j + 1] = key;
    }
}

// Fungsi utama
int main() {
    // Data pelanggan (tanpa inputan)
    Customer customers[] = {
        {"Andi", 150000},
        {"Budi", 200000},
        {"Citra", 100000},
        {"Dewi", 250000},
        {"Eka", 180000}
    };

    // Jumlah pelanggan
    int size = sizeof(customers) / sizeof(customers[0]);

    // Pointer ke array pelanggan
    Customer* customerPtr = customers;

    // Menampilkan daftar pelanggan sebelum diurutkan
    cout << "Data sebelum diurutkan:\n";
    displayCustomers(customerPtr, size);

    // Mengurutkan pelanggan berdasarkan pembayaran
    sortCustomersByPayment(customerPtr, size);

    // Menampilkan daftar pelanggan setelah diurutkan
    cout << "Data setelah diurutkan berdasarkan pembayaran:\n";
    displayCustomers(customerPtr, size);

    return 0;
}