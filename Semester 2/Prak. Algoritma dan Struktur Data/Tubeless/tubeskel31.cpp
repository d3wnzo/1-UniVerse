#include <iostream>         
#include <iomanip>           
#include <ctime>            
using namespace std;         

// === Struktur Data Linked List untuk Dokumen ===
struct Dokumen {
    string nama, kategori, tanggal; 
    int ukuran;                     
    Dokumen* next;                 
};
Dokumen* head = NULL;              // Pointer global 'head' yang menunjuk ke elemen pertama (kepala) dari Linked List, diinisialisasi NULL (kosong)

// === Stack (Riwayat Pencarian) ===
struct Stack {
    string nama;                    
    Stack* next;                    
};
Stack* topCari = NULL;             // Pointer global 'topCari' yang menunjuk ke elemen teratas (top) dari Stack Riwayat Pencarian, diinisialisasi NULL (kosong)

// === Queue (Antrian Cetak) ===
struct QueueNode {
    string nama;                    
    QueueNode* next;              
};
QueueNode* front = NULL;           // Pointer global 'front' yang menunjuk ke elemen terdepan (first-in) dari Queue, diinisialisasi NULL
QueueNode* rear = NULL;            // Pointer global 'rear' yang menunjuk ke elemen terbelakang (last-in) dari Queue, diinisialisasi NULL

// === Stack (Hasil Proses Cetak) ===
struct Stack* topCetak = NULL;     // Pointer global 'topCetak' yang menunjuk ke elemen teratas (top) dari Stack Hasil Proses Cetak, diinisialisasi NULL (kosong)

// === Tree (mengurutkan berdasarkan nama) ===
struct TreeNode {
    string nama;                    
    TreeNode* left;                 
    TreeNode* right;                
};
TreeNode* root = NULL;             // Pointer global 'root' yang menunjuk ke akar (root) dari BST, diinisialisasi NULL

// === Fungsi Mendapatkan Waktu Sekarang dalam Format String ===
string waktuSekarang() {
    time_t now = time(0);                  
    tm* ltm = localtime(&now);             
    char buffer[30];                       
    // Memformat struktur tm ke string "dd-mm-yyyy HH:MM:SS" dan menyimpannya ke buffer
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", ltm);
    return string(buffer);                 
}

// === Fungsi Stack: PUSH ===
void push(Stack*& top, string nama) {
    Stack* baru = new Stack{nama, top};    // Membuat node Stack baru, dengan 'nama' yang diberikan, dan pointer 'next' menunjuk ke 'top' yang lama
    top = baru;                            // Mengupdate pointer 'top' untuk menunjuk ke node yang baru dibuat (node ini sekarang adalah bagian atas stack)
}

// === Fungsi Stack: POP ===
// Fungsi untuk menghapus elemen dari bagian atas stack (operasi POP)
void pop(Stack*& top) {
    if (!top) {                            // Memeriksa apakah stack kosong (jika 'top' adalah NULL)
        cout << "\n   Riwayat pencarian kosong!" << endl; 
        return;                            
    }
    Stack* hapus = top;                    // Menyimpan pointer ke node yang akan dihapus (yaitu node yang sedang ditunjuk oleh 'top')
    cout << "\n Menghapus dari Riwayat (Pop LIFO): " << top->nama << endl;
    top = top->next;                      
    delete hapus;                          
}

// === Tampilkan Isi Stack ===
// Fungsi untuk menampilkan semua elemen yang ada di dalam stack, dari atas ke bawah
void tampilRiwayat(Stack* top, string label) {
    cout << "\n " << label << "\n==============================" << endl; 
    Stack* bantu = top;                    // Membuat pointer bantu yang dimulai dari 'top' stack
    int no = 1;                            
    while (bantu) {                        // Melakukan iterasi selama pointer bantu belum mencapai akhir stack (NULL)
        cout << no++ << ". " << bantu->nama << endl; 
        bantu = bantu->next;               // Menggeser pointer bantu ke elemen berikutnya di stack
    }
    if (no == 1) cout << "   Riwayat kosong." << endl; // Jika loop tidak berjalan (no tetap 1), berarti stack kosong
}

// === Fungsi Queue: ENQUEUE ===
// Fungsi untuk menambahkan elemen baru ke bagian belakang queue (operasi ENQUEUE)
void enqueue(string nama) {
    QueueNode* baru = new QueueNode{nama, NULL}; 
    if (!rear) front = rear = baru;        // Memeriksa apakah queue kosong; jika kosong, node baru menjadi 'front' sekaligus 'rear'
    else {
        rear->next = baru;                 // Jika tidak kosong, pointer 'next' dari 'rear' saat ini menunjuk ke node baru
        rear = baru;                       // Mengupdate pointer 'rear' untuk menunjuk ke node baru (node ini sekarang di belakang queue)
    }
    cout << " Ditambahkan ke Antrian Cetak: " << nama << endl; 
}

// === Fungsi Queue: DEQUEUE ===
// Fungsi untuk menghapus elemen dari bagian depan queue (operasi DEQUEUE)
void dequeue() {
    if (!front) {                         
        cout << "\n   Antrian kosong!" << endl;   
        return;                           
    }
    QueueNode* hapus = front;              // Menyimpan pointer ke node yang akan dihapus (yaitu node yang sedang ditunjuk oleh 'front')
    cout << "\n Memproses Antrian (Dequeue FIFO): " << front->nama << endl; 
    push(topCetak, front->nama);           
    front = front->next;                   
    if (!front) rear = NULL;               
    delete hapus;                         
}

// === Tampilkan Isi Queue ===
// Fungsi untuk menampilkan semua elemen yang ada di dalam queue, dari depan ke belakang
void tampilQueue() {
    cout << "\n Antrian Cetak:" << endl;         
    QueueNode* bantu = front;              
    int no = 1;                            
    while (bantu) {                        
        cout << no++ << ". " << bantu->nama << endl; 
        bantu = bantu->next;               
    }
    if (no == 1) cout << "   Antrian kosong." << endl; 
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
void bubbleSort() {
    if (!head || !head->next) return;      // Jika Linked List kosong atau hanya berisi satu elemen, tidak perlu diurutkan
    bool swapped;                          // Variabel boolean untuk melacak apakah ada penukaran yang terjadi dalam satu pass
    do {                                   // Loop do-while untuk melakukan pass pengurutan
        swapped = false;                  
        Dokumen* ptr = head;               // Pointer bantu yang dimulai dari 'head'
        while (ptr->next) {                // Melakukan iterasi selama pointer bantu belum mencapai elemen terakhir
            if (ptr->ukuran > ptr->next->ukuran) { // Membandingkan ukuran dokumen saat ini dengan dokumen berikutnya
                // Jika ukuran dokumen saat ini lebih besar, tukar seluruh data kedua dokumen
                swap(ptr->nama, ptr->next->nama);
                swap(ptr->kategori, ptr->next->kategori);
                swap(ptr->tanggal, ptr->next->tanggal);
                swap(ptr->ukuran, ptr->next->ukuran);
                swapped = true;           
            }
            ptr = ptr->next;               
        }
    } while (swapped);                     
    cout << "\n Dokumen berhasil diurutkan berdasarkan ukuran." << endl; 
}

// === Tambah Dokumen Baru ===
void tambahDokumen(string nama, string kategori, string tanggal, int ukuran) {
    // Membuat node Dokumen baru dan menyisipkannya di awal Linked List (insert at head)
    Dokumen* baru = new Dokumen{nama, kategori, tanggal, ukuran, head};
    head = baru;                           // Mengupdate 'head' untuk menunjuk ke dokumen yang baru ditambahkan
    root = insertTree(root, nama);         // Memasukkan nama dokumen ke Binary Search Tree (BST) juga
    cout << "\n Dokumen berhasil ditambahkan: " << nama << endl; 
}

// === Tampilkan Semua Dokumen ===
void tampilDokumen() {
    cout << "\n Daftar Dokumen\n";        
    cout << "========================================================================================" << endl; 
    
    cout << "   No   Nama Dokumen             Kategori         Ukuran (KB)   Tanggal                 " << endl;
    cout << "========================================================================================" << endl; 
    Dokumen* bantu = head;                 // Pointer bantu yang dimulai dari 'head' Linked List
    int no = 1;                           
    while (bantu) {                        // Melakukan iterasi selama pointer bantu belum mencapai akhir Linked List (NULL)
        cout << "| " << setw(2) << no++ << " | "; 
        cout << setw(25) << left << bantu->nama;   
        cout << "| " << setw(14) << left << bantu->kategori; 
        cout << "| " << setw(11) << left << bantu->ukuran;   
        cout << "| " << setw(19) << left << bantu->tanggal << "|" << endl; 
        bantu = bantu->next;               // Menggeser pointer bantu ke dokumen berikutnya
    }
    if (no == 1)                          
        cout << "| Tidak ada dokumen yang tersedia." << endl; 
    cout << "========================================================================================" << endl; 
}

// === Fungsi Searching Dokumen Berdasarkan Nama ===
void cariDokumen(string nama) {
    Dokumen* bantu = head;                 
    bool ketemu = false;                   
    while (bantu) {                       
        if (bantu->nama == nama) {         // Membandingkan nama dokumen di node saat ini dengan nama yang dicari
            cout << "\n Dokumen Ditemukan:" << endl; 
            cout << " Nama     : " << bantu->nama << endl;     
            cout << " Kategori : " << bantu->kategori << endl;
            cout << " Ukuran   : " << bantu->ukuran << " KB" << endl;
            cout << " Tanggal  : " << bantu->tanggal << endl;
            push(topCari, nama);           // Menambahkan nama dokumen yang ditemukan ke stack riwayat pencarian
            ketemu = true;                
            break;                        
        }
        bantu = bantu->next;               
    }
    if (!ketemu) cout << "\n Dokumen tidak ditemukan." << endl; 
}

// === MAIN PROGRAM ===
int main() {
    int pilih;                             
    string nama;                           
    string tanggal = waktuSekarang();     

    
    tambahDokumen("Laporan Keuangan", "Keuangan", tanggal, 120);
    tambahDokumen("Rencana Proyek", "Manajemen", tanggal, 98);
    tambahDokumen("Notulen Rapat", "Administrasi", tanggal, 85);
    tambahDokumen("Proposal Penelitian", "Akademik", tanggal, 150);
    tambahDokumen("Jadwal Kegiatan", "Event", tanggal, 72);

    do {                                   // Memulai loop do-while untuk menampilkan menu dan memproses pilihan pengguna
       
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
        cout << "Pilih menu [0-10]: "; cin >> pilih; 
        cin.ignore();                          

        switch (pilih) {                       
            case 1: tampilDokumen(); break;    
            case 2:                            
                cout << "\n Daftar Dokumen Urut Nama (Tree - Inorder Traversal):" << endl;
                inorder(root); break;          // Memanggil fungsi inorder untuk menampilkan BST
            case 3: bubbleSort(); tampilDokumen(); break; 
            case 4:                            
                cout << "Masukkan nama dokumen: ";
                getline(cin, nama);            // Membaca nama dokumen yang dicari (bisa mengandung spasi)
                cariDokumen(nama); break;      // Memanggil fungsi cariDokumen
            case 5: tampilRiwayat(topCari, "Riwayat Pencarian"); break; 
            case 6: pop(topCari); break;      
            case 7:                           
                cout << "Masukkan nama dokumen untuk antrian cetak: ";
                getline(cin, nama);            
                enqueue(nama); break;          // Memanggil fungsi enqueue
            case 8: tampilQueue(); break;     
            case 9: dequeue(); break;          
            case 10: tampilRiwayat(topCetak, "Hasil Proses Cetak"); break; 
            case 0: cout << "\n Terima kasih!" << endl; break; 
            default: cout << " Pilihan tidak valid." << endl; 
        }
    } while (pilih != 0);                      // Loop berlanjut selama pilihan pengguna bukan 0 (keluar)

    return 0;                                 
}