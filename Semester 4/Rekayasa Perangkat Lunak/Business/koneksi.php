<?php
// Tentukan nama dan jalur file database SQLite lo
// File ini akan otomatis dibuat di folder yang sama dengan koneksi.php
$database_file = __DIR__ . '/agro_kates_rpl.db';

try {
    // Koneksi menggunakan PDO (PHP Data Objects) khusus SQLite
    $koneksi = new PDO("sqlite:" . $database_file);
    
    // Aktifkan error mode biar kalau query lo typo langsung ketahuan erornya
    $koneksi->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
} catch (PDOException $e) {
    die("Koneksi ke SQLite Gagal, Bro!: " . $e->getMessage());
}
?>