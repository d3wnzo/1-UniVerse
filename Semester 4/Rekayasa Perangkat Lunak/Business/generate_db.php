<?php
include 'koneksi.php';

try {
    // 1. Buat Tabel Users
    $koneksi->exec("CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nama TEXT NOT NULL,
        username TEXT NOT NULL UNIQUE,
        password TEXT NOT NULL,
        role TEXT NOT NULL
    )");

    // 2. Buat Tabel Produk
    $koneksi->exec("CREATE TABLE IF NOT EXISTS produk (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nama_produk TEXT NOT NULL,
        stok INTEGER DEFAULT 0
    )");

    // 3. Buat Tabel Restock
    $koneksi->exec("CREATE TABLE IF NOT EXISTS restock (
        id_restock INTEGER PRIMARY KEY AUTOINCREMENT,
        petani_id INTEGER,
        produk_id INTEGER,
        jumlah_beli INTEGER,
        status_kirim TEXT DEFAULT 'Menunggu Pembayaran'
    )");

    // 4. Masukkan Data Dummy Biar Bisa Langsung Tes Login & Alur
    // Kita cek dulu biar datanya gak double kalau script ini dijalankan ulang
    $check = $koneksi->query("SELECT COUNT(*) FROM users")->fetchColumn();
    if ($check == 0) {
        $koneksi->exec("INSERT INTO users (nama, username, password, role) VALUES 
            ('Pak Tani', 'petani1', '123', 'petani'),
            ('Bang Kurir', 'kurir1', '123', 'pengirim'),
            ('Bos Owner', 'owner1', '123', 'pemilik')");
            
        $koneksi->exec("INSERT INTO produk (nama_produk, stok) VALUES ('Bibit Pepaya Calina', 100)");
        $koneksi->exec("INSERT INTO restock (petani_id, produk_id, jumlah_beli, status_kirim) VALUES (1, 1, 20, 'Sudah Bayar')");
    }

    echo "⚡ Database dan Tabel SQLite Berhasil Dibuat, Bro! File 'agro_kates_rpl.db' sudah muncul.";

} catch (PDOException $e) {
    echo "Gagal membuat database: " . $e->getMessage();
}
?>