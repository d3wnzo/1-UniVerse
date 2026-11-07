-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 24, 2025 at 10:18 AM
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
-- Database: `akademik2`
--

-- --------------------------------------------------------

--
-- Table structure for table `krs`
--

CREATE TABLE `krs` (
  `id_krs` int(11) NOT NULL,
  `nim` varchar(10) DEFAULT NULL,
  `kode_mk` varchar(10) DEFAULT NULL,
  `semester` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `krs`
--

INSERT INTO `krs` (`id_krs`, `nim`, `kode_mk`, `semester`) VALUES
(1, '22001', 'IF101', 1),
(2, '22002', 'IF102', 2),
(3, '22003', 'IF101', 1),
(4, '22004', 'IF103', 2),
(5, '22005', 'IF102', 3),
(6, '22006', 'IF104', 3),
(7, '22007', 'IF105', 1),
(8, '22008', 'IF106', 4),
(9, '22009', 'IF101', 1),
(10, '22010', 'IF107', 3),
(11, '22011', 'IF108', 4),
(12, '22012', 'IF109', 2),
(13, '22013', 'IF110', 3),
(14, '22014', 'SI201', 4),
(15, '22015', 'SI202', 2);

-- --------------------------------------------------------

--
-- Table structure for table `mahasiswa`
--

CREATE TABLE `mahasiswa` (
  `nim` varchar(10) NOT NULL,
  `nama` varchar(100) DEFAULT NULL,
  `prodi` varchar(50) DEFAULT NULL,
  `angkatan` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `mahasiswa`
--

INSERT INTO `mahasiswa` (`nim`, `nama`, `prodi`, `angkatan`) VALUES
('22001', 'Jovan Alfito', 'Informatika', 2021),
('22002', 'Devica Putri', 'Informatika', 2023),
('22003', 'Kezia Anabel', 'Sistem Informasi', 2023),
('22004', 'Akbar Ramadhan', 'Informatika', 2022),
('22005', 'Fahran Maulana', 'Manajemen Informatika', 2020),
('22006', 'Deswita Prisdei', 'Informatika', 2021),
('22007', 'Abiyu Muflih', 'Sistem Informasi', 2024),
('22008', 'Azizah Firdayani', 'Informatika', 2021),
('22009', 'Ahmad Khoiri', 'Informatika', 2019),
('22010', 'Chaerul Cahyadi', 'Sistem Informasi', 2022),
('22011', 'Zahra Tsabita', 'Informatika', 2017),
('22012', 'Revalina Adelia', 'Informatika', 2022),
('22013', 'Pembalap UP', 'Sistem Informasi', 2023),
('22014', 'Salto Sore', 'Informatika', 2021),
('22015', 'Arya Fahreza', 'Manajemen Informatika', 2022);

-- --------------------------------------------------------

--
-- Table structure for table `mata_kuliah`
--

CREATE TABLE `mata_kuliah` (
  `kode_mk` varchar(10) NOT NULL,
  `nama_mk` varchar(100) DEFAULT NULL,
  `sks` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `mata_kuliah`
--

INSERT INTO `mata_kuliah` (`kode_mk`, `nama_mk`, `sks`) VALUES
('IF101', 'Pemrograman Dasar', 3),
('IF102', 'Basis Data', 3),
('IF103', 'Struktur Data', 3),
('IF104', 'Jaringan Komputer', 3),
('IF105', 'Sistem Operasi', 3),
('IF106', 'Pemrograman Web', 3),
('IF107', 'PBO Java', 3),
('IF108', 'Kecerdasan Buatan', 3),
('IF109', 'Analisis Sistem', 3),
('IF110', 'Data Mining', 3),
('MI301', 'Aplikasi Perkantoran', 2),
('MI302', 'Perancangan Sistem Informasi', 3),
('MI303', 'Teknologi Informasi', 2),
('SI201', 'Sistem Informasi Manajemen', 3),
('SI202', 'Analisis Proses Bisnis', 3);

-- --------------------------------------------------------

--
-- Table structure for table `nilai`
--

CREATE TABLE `nilai` (
  `id_nilai` int(11) NOT NULL,
  `id_krs` int(11) DEFAULT NULL,
  `nilai_angka` decimal(5,2) DEFAULT NULL,
  `nilai_huruf` char(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `nilai`
--

INSERT INTO `nilai` (`id_nilai`, `id_krs`, `nilai_angka`, `nilai_huruf`) VALUES
(1, 1, 85.00, 'A'),
(2, 2, 78.00, 'B'),
(3, 3, 90.00, 'A'),
(4, 4, 65.00, 'C'),
(5, 5, 88.00, 'A'),
(6, 6, 72.00, 'B'),
(7, 7, 80.00, 'A'),
(8, 8, 76.00, 'B'),
(9, 9, 69.00, 'C'),
(10, 10, 95.00, 'A'),
(11, 11, 60.00, 'C'),
(12, 12, 82.00, 'B'),
(13, 13, 91.00, 'A'),
(14, 14, 84.00, 'A'),
(15, 15, 77.00, 'B');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
