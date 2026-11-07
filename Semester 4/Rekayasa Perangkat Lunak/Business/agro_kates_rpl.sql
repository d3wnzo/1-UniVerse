CREATE DATABASE IF NOT EXISTS agro_kates_rpl;
USE agro_kates_rpl;

-- Hapus tabel lama biar bener-bener reset dari 0
DROP TABLE IF EXISTS pengiriman_konsumen, pembayaran, restock, produk, users;

-- 1. Tabel Users (6 Aktor, Login Pake Email & Password 123)
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nama VARCHAR(100) NOT NULL,
    username VARCHAR(100) NOT NULL UNIQUE, -- Kolom email
    password VARCHAR(255) NOT NULL,
    role VARCHAR(50) NOT NULL
);

-- 2. Tabel Produk
CREATE TABLE produk (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nama_produk VARCHAR(100) NOT NULL,
    stok INT DEFAULT 0
);

-- 3. LOGISTIK MASUK: Petani -> Perusahaan (Diantar oleh 'pengirim_bibit')
CREATE TABLE restock (
    id_restock INT AUTO_INCREMENT PRIMARY KEY,
    petani_id INT NOT NULL,
    pengirim_id INT NOT NULL, -- Merujuk ke user role 'pengirim_bibit'
    produk_id INT NOT NULL,
    jumlah_beli INT NOT NULL, -- Dalam Kg
    status_kirim VARCHAR(100) DEFAULT 'Menunggu Pembayaran'
);

-- 4. Tabel Pembayaran (Keuangan Restock)
CREATE TABLE pembayaran (
    id_bayar INT AUTO_INCREMENT PRIMARY KEY,
    id_restock INT NOT NULL,
    total_bayar INT NOT NULL,
    status_bayar VARCHAR(50) DEFAULT 'Belum Bayar'
);

-- 5. LOGISTIK KELUAR: Perusahaan -> Konsumen Akhir (Diantar oleh 'kurir_ekspedisi')
CREATE TABLE pengiriman_konsumen (
    id_pengiriman INT AUTO_INCREMENT PRIMARY KEY,
    konsumen_id INT NOT NULL, -- Merujuk ke user role 'konsumen'
    kurir_id INT NOT NULL,    -- Merujuk ke user role 'kurir_ekspedisi'
    produk_id INT NOT NULL,
    jumlah_kirim INT NOT NULL, -- Dalam Kg
    alamat_tujuan TEXT NOT NULL,
    status_pengiriman VARCHAR(100) DEFAULT 'Sedang Dikirim'
);

-- ========================================================
-- INJECT DATA DUMMY BARU (PASSWORD SEMUA '123')
-- ========================================================
INSERT INTO users (nama, username, password, role) VALUES 
('Budi Konsumen', 'konsumen@gmail.com', '123', 'konsumen'),
('Andi Karyawan', 'karyawan@gmail.com', '123', 'karyawan'),
('Bos Owner', 'owner@gmail.com', '123', 'pemilik'),
('Pak Tani Pepaya', 'petani@gmail.com', '123', 'petani'),
('Sandi Ekspedisi', 'kurir@gmail.com', '123', 'kurir_ekspedisi'),
('Randi Pengirim', 'pengirim@gmail.com', '123', 'pengirim_bibit');

INSERT INTO produk (id, nama_produk, stok) VALUES 
(1, 'Bibit Pepaya Calina Unggul', 100);

-- Dummy Restock (Petani ID 4, Pengirim ID 6)
INSERT INTO restock (petani_id, pengirim_id, produk_id, jumlah_beli, status_kirim) VALUES 
(4, 6, 1, 50, 'Dalam Perjalanan');

-- Dummy Pengiriman Konsumen (Konsumen ID 1, Kurir ID 5)
INSERT INTO pengiriman_konsumen (konsumen_id, kurir_id, produk_id, jumlah_kirim, alamat_tujuan) VALUES 
(1, 5, 1, 10, 'Jl. Raya Pajajaran No. 10, Bogor');