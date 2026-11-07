-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 06, 2025 at 12:31 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `perusahaan`
--

-- --------------------------------------------------------

--
-- Table structure for table `programmer`
--

CREATE TABLE `programmer` (
  `id_programmer` int(11) NOT NULL,
  `nama_programmer` varchar(100) DEFAULT NULL,
  `bahasa_favorit` varchar(50) DEFAULT NULL,
  `pengalaman_tahun` int(11) DEFAULT NULL,
  `gaji` double DEFAULT NULL,
  `status_kerja` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `programmer`
--

INSERT INTO `programmer` (`id_programmer`, `nama_programmer`, `bahasa_favorit`, `pengalaman_tahun`, `gaji`, `status_kerja`) VALUES
(1, 'Andi Pratama', 'Python', 5, 12000000, 'Tetap'),
(2, 'Rani Lestari', 'Java', 3, 9000000, 'Kontrak'),
(3, 'Budi Santoso', 'C++', 7, 15000000, 'Tetap'),
(4, 'Sinta Dewi', 'JavaScript', 2, 8000000, 'Magang'),
(5, 'Dika Rahman', 'PHP', 4, 9500000, 'Kontrak'),
(6, 'Nadia Putri', 'Kotlin', 6, 13500000, 'Tetap'),
(7, 'Agus Saputra', 'Python', 1, 7000000, 'Magang'),
(8, 'Fajar Hidayat', 'C#', 5, 11000000, 'Kontrak'),
(9, 'Maya Anjani', 'Go', 3, 10000000, 'Kontrak'),
(10, 'Ridho Firmansyah', 'Ruby', 8, 16000000, 'Tetap'),
(11, 'Lina Kurnia', 'Swift', 4, 9500000, 'Kontrak'),
(12, 'Taufik Hidayat', 'Python', 10, 18000000, 'Tetap'),
(13, 'Wulan Sari', 'JavaScript', 2, 8500000, 'Magang'),
(14, 'Bayu Nugraha', 'PHP', 5, 10500000, 'Kontrak'),
(15, 'Sari Anggraini', 'C++', 6, 14000000, 'Tetap'),
(16, 'Yusuf Adi', 'Rust', 3, 9500000, 'Kontrak'),
(17, 'Nanda Fitria', 'Python', 4, 12000000, 'Tetap'),
(18, 'Reza Setiawan', 'Java', 8, 15500000, 'Tetap'),
(19, 'Hani Oktaviani', 'Dart', 2, 8500000, 'Magang'),
(20, 'Iqbal Ramadhan', 'PHP', 5, 9500000, 'Kontrak'),
(21, 'Dewi Laras', 'Python', 6, 12500000, 'Tetap'),
(22, 'Aditya Putra', 'Java', 2, 8000000, 'Magang'),
(23, 'Cahyo Prasetyo', 'C++', 9, 16500000, 'Tetap'),
(24, 'Rika Anggraini', 'JavaScript', 3, 9000000, 'Kontrak'),
(25, 'Farhan Malik', 'Go', 4, 10000000, 'Tetap'),
(26, 'Vina Sari', 'PHP', 1, 7500000, 'Magang'),
(27, 'Hendra Saputra', 'Python', 7, 14000000, 'Tetap'),
(28, 'Siti Nur', 'C#', 5, 11000000, 'Kontrak'),
(29, 'Rizki Aulia', 'Ruby', 3, 9500000, 'Magang'),
(30, 'Amir Fauzi', 'Kotlin', 6, 13000000, 'Tetap'),
(31, 'Putri Ayu', 'Python', 2, 8500000, 'Magang'),
(32, 'Bayu Wicaksono', 'PHP', 4, 9800000, 'Kontrak'),
(33, 'Intan Permata', 'JavaScript', 5, 10500000, 'Tetap'),
(34, 'Galih Pratama', 'C++', 8, 15500000, 'Tetap'),
(35, 'Rendi Hidayat', 'Python', 3, 9500000, 'Kontrak'),
(36, 'Siska Dewi', 'Dart', 1, 7000000, 'Magang'),
(37, 'Arif Maulana', 'C#', 6, 12000000, 'Tetap'),
(38, 'Feni Rahayu', 'PHP', 2, 8500000, 'Magang'),
(39, 'Vito Santoso', 'Go', 5, 10500000, 'Kontrak'),
(40, 'Nina Anggraini', 'Python', 4, 11500000, 'Tetap'),
(41, 'Yoga Pratama', 'Java', 7, 14500000, 'Tetap'),
(42, 'Lia Oktaviani', 'Swift', 3, 9500000, 'Kontrak'),
(43, 'Bayu Adi', 'C++', 2, 8500000, 'Magang'),
(44, 'Fahri Ramadhan', 'Python', 5, 12000000, 'Tetap'),
(45, 'Tasya Sari', 'PHP', 6, 13000000, 'Tetap'),
(46, 'Raka Setiawan', 'Ruby', 3, 9000000, 'Kontrak'),
(47, 'Dina Permatasari', 'JavaScript', 4, 10000000, 'Tetap'),
(48, 'Ilham Prasetyo', 'Go', 2, 8500000, 'Magang'),
(49, 'Putra Nugroho', 'C#', 7, 14500000, 'Tetap'),
(50, 'Anisa Rahma', 'Python', 3, 9500000, 'Kontrak'),
(51, 'Rizal Fikri', 'Dart', 2, 8000000, 'Magang'),
(52, 'Vivi Anggraini', 'PHP', 5, 10500000, 'Tetap'),
(53, 'Galuh Pratama', 'Java', 8, 16000000, 'Tetap');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `programmer`
--
ALTER TABLE `programmer`
  ADD PRIMARY KEY (`id_programmer`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `programmer`
--
ALTER TABLE `programmer`
  MODIFY `id_programmer` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=54;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
