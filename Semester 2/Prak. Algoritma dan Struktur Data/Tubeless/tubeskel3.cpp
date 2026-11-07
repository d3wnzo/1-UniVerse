#include <iostream>          // Library untuk input output standar (misalnya cin, cout)
#include <iomanip>           // Library untuk manipulasi format output (misalnya setw untuk mengatur lebar kolom)
#include <ctime>             // Library untuk fungsi-fungsi terkait waktu dan tanggal
using namespace std;         // Menggunakan namespace standar C++ untuk menghindari penulisan 'std::'

// === Struktur Data Linked List untuk Dokumen ===
// Definisi struktur Dokumen yang akan digunakan sebagai node dalam Linked List
struct Dokumen {
    string nama, kategori, tanggal; // Variabel untuk menyimpan nama, kategori, dan tanggal dokumen (tipe string)
    int ukuran;                     // Variabel untuk menyimpan ukuran dokumen dalam Kilobyte (KB) (tipe integer)
    Dokumen* next;                  // Pointer ke objek Dokumen berikutnya dalam Linked List
};
Dokumen* head = NULL;              // Pointer global 'head' yang menunjuk ke elemen pertama (kepala) dari Linked List, diinisialisasi NULL (kosong)

// === Stack (Riwayat Pencarian) ===
// Definisi struktur Stack yang akan digunakan sebagai node dalam Stack
struct Stack {
    string nama;                    // Variabel untuk menyimpan nama dokumen yang dicari/dicatat dalam riwayat
    Stack* next;                    // Pointer ke elemen Stack berikutnya (atau sebelumnya dalam urutan Stack)
};
Stack* topCari = NULL;             // Pointer global 'topCari' yang menunjuk ke elemen teratas (top) dari Stack Riwayat Pencarian, diinisialisasi NULL (kosong)

// === Queue (Antrian Cetak) ===
// Definisi struktur QueueNode yang akan digunakan sebagai node dalam Queue
struct QueueNode {
    string nama;                    // Variabel untuk menyimpan nama dokumen yang masuk antrian cetak
    QueueNode* next;                // Pointer ke elemen QueueNode berikutnya dalam Queue
};
QueueNode* front = NULL;           // Pointer global 'front' yang menunjuk ke elemen terdepan (first-in) dari Queue, diinisialisasi NULL
QueueNode* rear = NULL;            // Pointer global 'rear' yang menunjuk ke elemen terbelakang (last-in) dari Queue, diinisialisasi NULL

// === Stack (Hasil Proses Cetak) ===
struct Stack* topCetak = NULL;     // Pointer global 'topCetak' yang menunjuk ke elemen teratas (top) dari Stack Hasil Proses Cetak, diinisialisasi NULL (kosong)

// === Tree (BST berdasarkan nama) ===
// Definisi struktur TreeNode yang akan digunakan sebagai node dalam Binary Search Tree (BST)
struct TreeNode {
    string nama;                    // Variabel untuk menyimpan nama dokumen di node tree
    TreeNode* left;                 // Pointer ke anak kiri (sub-tree kiri)
    TreeNode* right;                // Pointer ke anak kanan (sub-tree kanan)
};
TreeNode* root = NULL;             // Pointer global 'root' yang menunjuk ke akar (root) dari BST, diinisialisasi NULL

// === Fungsi Mendapatkan Waktu Sekarang dalam Format String ===
// Fungsi untuk mengambil waktu sistem saat ini dan mengkonversinya ke format string
string waktuSekarang() {
    time_t now = time(0);                  // Mendapatkan waktu saat ini dalam format time_t (detik sejak Epoch)
    tm* ltm = localtime(&now);             // Mengkonversi waktu time_t ke struktur tm (waktu lokal)
    char buffer[30];                       // Mendefinisikan buffer karakter untuk menyimpan string tanggal/waktu
    // Memformat struktur tm ke string "dd-mm-yyyy HH:MM:SS" dan menyimpannya ke buffer
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", ltm);
    return string(buffer);                 // Mengkonversi buffer (array char) menjadi objek string dan mengembalikannya
}

// === Fungsi Stack: PUSH ===
// Fungsi untuk menambahkan elemen baru ke bagian atas stack (operasi PUSH)
void push(Stack*& top, string nama) {
    Stack* baru = new Stack{nama, top};    // Membuat node Stack baru, dengan 'nama' yang diberikan, dan pointer 'next' menunjuk ke 'top' yang lama
    top = baru;                            // Mengupdate pointer 'top' untuk menunjuk ke node yang baru dibuat (node ini sekarang adalah bagian atas stack)
}

// === Fungsi Stack: POP ===
// Fungsi untuk menghapus elemen dari bagian atas stack (operasi POP)
void pop(Stack*& top) {
    if (!top) {                            // Memeriksa apakah stack kosong (jika 'top' adalah NULL)
        cout << "\n   Riwayat pencarian kosong!" << endl; // Menampilkan pesan jika stack kosong
        return;                            // Menghentikan fungsi jika stack kosong
    }
    Stack* hapus = top;                    // Menyimpan pointer ke node yang akan dihapus (yaitu node yang sedang ditunjuk oleh 'top')
    cout << "\n Menghapus dari Riwayat (Pop LIFO): " << top->nama << endl; // Menampilkan nama dokumen yang dihapus
    top = top->next;                       // Menggeser pointer 'top' ke node berikutnya (yang sebelumnya berada di bawah node yang dihapus)
    delete hapus;                          // Mengosongkan memori dari node yang dihapus
}

// === Tampilkan Isi Stack ===
// Fungsi untuk menampilkan semua elemen yang ada di dalam stack, dari atas ke bawah
void tampilRiwayat(Stack* top, string label) {
    cout << "\n " << label << "\n==============================" << endl; // Menampilkan judul/label untuk riwayat
    Stack* bantu = top;                    // Membuat pointer bantu yang dimulai dari 'top' stack
    int no = 1;                            // Counter untuk nomor urut
    while (bantu) {                        // Melakukan iterasi selama pointer bantu belum mencapai akhir stack (NULL)
        cout << no++ << ". " << bantu->nama << endl; // Menampilkan nomor urut dan nama dokumen
        bantu = bantu->next;               // Menggeser pointer bantu ke elemen berikutnya di stack
    }
    if (no == 1) cout << "   Riwayat kosong." << endl; // Jika loop tidak berjalan (no tetap 1), berarti stack kosong
}

// === Fungsi Queue: ENQUEUE ===
// Fungsi untuk menambahkan elemen baru ke bagian belakang queue (operasi ENQUEUE)
void enqueue(string nama) {
    QueueNode* baru = new QueueNode{nama, NULL}; // Membuat node QueueNode baru dengan 'nama' yang diberikan dan 'next' diinisialisasi NULL
    if (!rear) front = rear = baru;        // Memeriksa apakah queue kosong; jika kosong, node baru menjadi 'front' sekaligus 'rear'
    else {
        rear->next = baru;                 // Jika tidak kosong, pointer 'next' dari 'rear' saat ini menunjuk ke node baru
        rear = baru;                       // Mengupdate pointer 'rear' untuk menunjuk ke node baru (node ini sekarang di belakang queue)
    }
    cout << " Ditambahkan ke Antrian Cetak: " << nama << endl; // Menampilkan pesan konfirmasi penambahan ke antrian
}

// === Fungsi Queue: DEQUEUE ===
// Fungsi untuk menghapus elemen dari bagian depan queue (operasi DEQUEUE)
void dequeue() {
    if (!front) {                          // Memeriksa apakah queue kosong (jika 'front' adalah NULL)
        cout << "\n   Antrian kosong!" << endl;    // Menampilkan pesan jika queue kosong
        return;                            // Menghentikan fungsi jika queue kosong
    }
    QueueNode* hapus = front;              // Menyimpan pointer ke node yang akan dihapus (yaitu node yang sedang ditunjuk oleh 'front')
    cout << "\n Memproses Antrian (Dequeue FIFO): " << front->nama << endl; // Menampilkan nama dokumen yang diproses
    push(topCetak, front->nama);           // Menambahkan nama dokumen yang diproses ke stack 'topCetak' (hasil proses cetak)
    front = front->next;                   // Menggeser pointer 'front' ke node berikutnya (node ini sekarang adalah bagian depan queue)
    if (!front) rear = NULL;               // Jika setelah dequeue 'front' menjadi NULL, berarti queue menjadi kosong, maka 'rear' juga diatur ke NULL
    delete hapus;                          // Mengosongkan memori dari node yang dihapus
}

// === Tampilkan Isi Queue ===
// Fungsi untuk menampilkan semua elemen yang ada di dalam queue, dari depan ke belakang
void tampilQueue() {
    cout << "\n Antrian Cetak:" << endl;         // Menampilkan judul untuk antrian cetak
    QueueNode* bantu = front;              // Membuat pointer bantu yang dimulai dari 'front' queue
    int no = 1;                            // Counter untuk nomor urut
    while (bantu) {                        // Melakukan iterasi selama pointer bantu belum mencapai akhir queue (NULL)
        cout << no++ << ". " << bantu->nama << endl; // Menampilkan nomor urut dan nama dokumen
        bantu = bantu->next;               // Menggeser pointer bantu ke elemen berikutnya di queue
    }
    if (no == 1) cout << "   Antrian kosong." << endl; // Jika loop tidak berjalan (no tetap 1), berarti queue kosong
}

// === Fungsi Tree: Insert BST Berdasarkan Nama Dokumen ===
// Fungsi rekursif untuk menyisipkan nama dokumen baru ke dalam Binary Search Tree (BST)
TreeNode* insertTree(TreeNode* node, string nama) {
    if (!node) return new TreeNode{nama, NULL, NULL}; // Jika node saat ini kosong, buat node baru sebagai tempat sisipan
    // Jika nama yang akan disisipkan lebih kecil dari nama di node saat ini, sisipkan ke anak kiri
    if (nama < node->nama) node->left = insertTree(node->left, nama);
    // Jika nama yang akan disisipkan lebih besar atau sama dari nama di node saat ini, sisipkan ke anak kanan
    else node->right = insertTree(node->right, nama);
    return node; // Mengembalikan node yang telah diperbarui (atau node baru yang dibuat)
}

// === Traversal Inorder Tree ===
// Fungsi rekursif untuk melakukan traversal in-order pada BST (cetak elemen secara terurut berdasarkan nama dokumen)
void inorder(TreeNode* node) {
    if (node) {                            // Basis rekursi: jika node tidak kosong
        inorder(node->left);               // Kunjungi anak kiri secara rekursif
        cout << "- " << node->nama << endl; // Cetak nama dokumen di node saat ini (root)
        inorder(node->right);              // Kunjungi anak kanan secara rekursif
    }
}

// === Bubble Sort untuk Mengurutkan Dokumen Berdasarkan Ukuran ===
// Fungsi untuk mengurutkan Linked List dokumen berdasarkan ukuran (dari kecil ke besar) menggunakan Bubble Sort
void bubbleSort() {
    if (!head || !head->next) return;      // Jika Linked List kosong atau hanya berisi satu elemen, tidak perlu diurutkan
    bool swapped;                          // Variabel boolean untuk melacak apakah ada penukaran yang terjadi dalam satu pass
    do {                                   // Loop do-while untuk melakukan pass pengurutan
        swapped = false;                   // Set 'swapped' ke false di awal setiap pass
        Dokumen* ptr = head;               // Pointer bantu yang dimulai dari 'head'
        while (ptr->next) {                // Melakukan iterasi selama pointer bantu belum mencapai elemen terakhir
            if (ptr->ukuran > ptr->next->ukuran) { // Membandingkan ukuran dokumen saat ini dengan dokumen berikutnya
                // Jika ukuran dokumen saat ini lebih besar, tukar seluruh data kedua dokumen
                swap(ptr->nama, ptr->next->nama);
                swap(ptr->kategori, ptr->next->kategori);
                swap(ptr->tanggal, ptr->next->tanggal);
                swap(ptr->ukuran, ptr->next->ukuran);
                swapped = true;            // Set 'swapped' menjadi true karena terjadi penukaran
            }
            ptr = ptr->next;               // Menggeser pointer bantu ke elemen berikutnya
        }
    } while (swapped);                     // Loop berlanjut selama ada penukaran yang terjadi di pass terakhir
    cout << "\n Dokumen berhasil diurutkan berdasarkan ukuran." << endl; // Pesan konfirmasi
}

// === Tambah Dokumen Baru ===
// Fungsi untuk menambahkan dokumen baru ke Linked List (sebagai head) dan juga ke BST
void tambahDokumen(string nama, string kategori, string tanggal, int ukuran) {
    // Membuat node Dokumen baru dan menyisipkannya di awal Linked List (insert at head)
    Dokumen* baru = new Dokumen{nama, kategori, tanggal, ukuran, head};
    head = baru;                           // Mengupdate 'head' untuk menunjuk ke dokumen yang baru ditambahkan
    root = insertTree(root, nama);         // Memasukkan nama dokumen ke Binary Search Tree (BST) juga
    cout << "\n Dokumen berhasil ditambahkan: " << nama << endl; // Pesan konfirmasi
}

// === Tampilkan Semua Dokumen ===
// Fungsi untuk menampilkan semua dokumen yang tersimpan dalam Linked List dalam format tabel
void tampilDokumen() {
    cout << "\n Daftar Dokumen\n";         // Judul tabel
    cout << "========================================================================================" << endl; // Garis pemisah
    // Header kolom tabel
    cout << "   No   Nama Dokumen             Kategori         Ukuran (KB)   Tanggal                 " << endl;
    cout << "========================================================================================" << endl; // Garis pemisah
    Dokumen* bantu = head;                 // Pointer bantu yang dimulai dari 'head' Linked List
    int no = 1;                            // Counter untuk nomor urut
    while (bantu) {                        // Melakukan iterasi selama pointer bantu belum mencapai akhir Linked List (NULL)
        cout << "| " << setw(2) << no++ << " | "; // Menampilkan nomor urut
        cout << setw(25) << left << bantu->nama;    // Menampilkan nama dokumen, rata kiri, lebar 25 karakter
        cout << "| " << setw(14) << left << bantu->kategori; // Menampilkan kategori, rata kiri, lebar 14 karakter
        cout << "| " << setw(11) << left << bantu->ukuran;   // Menampilkan ukuran, rata kiri, lebar 11 karakter
        cout << "| " << setw(19) << left << bantu->tanggal << "|" << endl; // Menampilkan tanggal, rata kiri, lebar 19 karakter
        bantu = bantu->next;               // Menggeser pointer bantu ke dokumen berikutnya
    }
    if (no == 1)                           // Jika loop tidak berjalan (no tetap 1), berarti Linked List kosong
        cout << "| Tidak ada dokumen yang tersedia." << endl; // Pesan jika tidak ada dokumen
    cout << "========================================================================================" << endl; // Garis penutup tabel
}

// === Fungsi Searching Dokumen Berdasarkan Nama ===
// Fungsi untuk mencari dokumen berdasarkan nama dalam Linked List
void cariDokumen(string nama) {
    Dokumen* bantu = head;                 // Pointer bantu yang dimulai dari 'head' Linked List
    bool ketemu = false;                   // Flag boolean untuk menandai apakah dokumen ditemukan
    while (bantu) {                        // Melakukan iterasi selama pointer bantu belum mencapai akhir Linked List
        if (bantu->nama == nama) {         // Membandingkan nama dokumen di node saat ini dengan nama yang dicari
            cout << "\n Dokumen Ditemukan:" << endl; // Menampilkan pesan dokumen ditemukan
            cout << " Nama     : " << bantu->nama << endl;     // Menampilkan detail dokumen
            cout << " Kategori : " << bantu->kategori << endl;
            cout << " Ukuran   : " << bantu->ukuran << " KB" << endl;
            cout << " Tanggal  : " << bantu->tanggal << endl;
            push(topCari, nama);           // Menambahkan nama dokumen yang ditemukan ke stack riwayat pencarian
            ketemu = true;                 // Set flag 'ketemu' menjadi true
            break;                         // Keluar dari loop karena dokumen sudah ditemukan
        }
        bantu = bantu->next;               // Menggeser pointer bantu ke dokumen berikutnya
    }
    if (!ketemu) cout << "\n Dokumen tidak ditemukan." << endl; // Jika dokumen tidak ditemukan setelah seluruh Linked List ditelusuri
}

// === MAIN PROGRAM ===
// Fungsi utama (entry point) dari program
int main() {
    int pilih;                             // Variabel untuk menyimpan pilihan menu pengguna
    string nama;                           // Variabel untuk menyimpan input nama dokumen dari pengguna
    string tanggal = waktuSekarang();      // Mengambil tanggal dan waktu saat ini menggunakan fungsi waktuSekarang()

    // Tambahkan 5 dokumen awal saat program dimulai
    tambahDokumen("Laporan Keuangan", "Keuangan", tanggal, 120);
    tambahDokumen("Rencana Proyek", "Manajemen", tanggal, 98);
    tambahDokumen("Notulen Rapat", "Administrasi", tanggal, 85);
    tambahDokumen("Proposal Penelitian", "Akademik", tanggal, 150);
    tambahDokumen("Jadwal Kegiatan", "Event", tanggal, 72);

    do {                                   // Memulai loop do-while untuk menampilkan menu dan memproses pilihan pengguna
        // Menampilkan menu utama aplikasi manajemen dokumen
        cout << "\n================ MENU MANAJEMEN DOKUMEN ================" << endl;
        cout << "1. Tampilkan Semua Dokumen" << endl;
        cout << "2. Lihat Dokumen Berdasarkan Nama (Tree - Inorder Traversal)" << endl;
        cout << "3. Urutkan Dokumen Berdasarkan Ukuran (Sorting Bubble Sort)" << endl;
        cout << "4. Cari Dokumen (Searching)" << endl;
        cout << "5. Lihat Riwayat Pencarian (Stack - LIFO)" << endl;
        cout << "6. Pop dari Riwayat Pencarian (Pop LIFO)" << endl;
        cout << "7. Tambah ke Antrian Cetak (Enqueue FIFO)" << endl;
        cout << "8. Lihat Antrian Cetak (FIFO)" << endl;
        cout << "9. Proses Antrian Cetak (Dequeue FIFO)" << endl;
        cout << "10. Lihat Hasil Proses Cetak" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu [0-10]: "; cin >> pilih; // Meminta pengguna untuk memasukkan pilihan menu
        cin.ignore();                          // Membersihkan input buffer untuk mengatasi masalah newline dengan getline()

        switch (pilih) {                       // Menggunakan switch-case untuk menangani pilihan menu
            case 1: tampilDokumen(); break;    // Pilihan 1: Menampilkan semua dokumen
            case 2:                            // Pilihan 2: Menampilkan dokumen berdasarkan nama (menggunakan BST in-order traversal)
                cout << "\n Daftar Dokumen Urut Nama (Tree - Inorder Traversal):" << endl;
                inorder(root); break;          // Memanggil fungsi inorder untuk menampilkan BST
            case 3: bubbleSort(); tampilDokumen(); break; // Pilihan 3: Mengurutkan dokumen berdasarkan ukuran dan menampilkan hasilnya
            case 4:                            // Pilihan 4: Mencari dokumen
                cout << "Masukkan nama dokumen: ";
                getline(cin, nama);            // Membaca nama dokumen yang dicari (bisa mengandung spasi)
                cariDokumen(nama); break;      // Memanggil fungsi cariDokumen
            case 5: tampilRiwayat(topCari, "Riwayat Pencarian"); break; // Pilihan 5: Menampilkan riwayat pencarian (stack)
            case 6: pop(topCari); break;       // Pilihan 6: Melakukan operasi POP dari riwayat pencarian
            case 7:                            // Pilihan 7: Menambahkan dokumen ke antrian cetak
                cout << "Masukkan nama dokumen untuk antrian cetak: ";
                getline(cin, nama);            // Membaca nama dokumen untuk antrian cetak
                enqueue(nama); break;          // Memanggil fungsi enqueue
            case 8: tampilQueue(); break;      // Pilihan 8: Menampilkan antrian cetak
            case 9: dequeue(); break;          // Pilihan 9: Memproses (dequeue) elemen dari antrian cetak
            case 10: tampilRiwayat(topCetak, "Hasil Proses Cetak"); break; // Pilihan 10: Menampilkan hasil proses cetak (stack)
            case 0: cout << "\n Terima kasih!" << endl; break; // Pilihan 0: Keluar dari program
            default: cout << " Pilihan tidak valid." << endl; // Pilihan tidak valid
        }
    } while (pilih != 0);                      // Loop berlanjut selama pilihan pengguna bukan 0 (keluar)

    return 0;                                  // Mengembalikan 0 menandakan program berakhir dengan sukses
}