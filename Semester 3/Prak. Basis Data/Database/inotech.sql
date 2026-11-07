-- phpMyAdmin SQL Dump
-- version 6.0.0-dev+20250506.60eb56b50d
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Oct 20, 2025 at 05:44 AM
-- Server version: 8.4.3
-- PHP Version: 8.4.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `inotech`
--

-- --------------------------------------------------------

--
-- Table structure for table `departemen`
--

CREATE TABLE `departemen` (
  `id_departemen` int NOT NULL,
  `id_karyawan` int DEFAULT NULL,
  `nama_departemen` varchar(50) COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `departemen`
--

INSERT INTO `departemen` (`id_departemen`, `id_karyawan`, `nama_departemen`) VALUES
(101, 1, 'IT'),
(102, 2, 'HRD'),
(103, 3, NULL),
(104, 4, 'Marketing'),
(105, 5, 'Produksi'),
(106, 6, 'Logistik'),
(107, 7, NULL),
(108, 8, 'Administrasi'),
(109, 9, 'Customer Service'),
(110, 10, 'Keuangan');

-- --------------------------------------------------------

--
-- Table structure for table `karyawan`
--

CREATE TABLE `karyawan` (
  `id_karyawan` int NOT NULL,
  `nama_karyawan` varchar(50) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `jenis_kelamin` varchar(50) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `gaji` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `karyawan`
--

INSERT INTO `karyawan` (`id_karyawan`, `nama_karyawan`, `jenis_kelamin`, `gaji`) VALUES
(1, 'Chaerul', 'Laki-laki', 7000000.00),
(2, 'Budi', 'Laki-laki', 6500000.00),
(3, 'Soja', 'Perempuan', NULL),
(4, 'Zahra', 'Perempuan', 6100000.00),
(5, 'Akbar', 'Laki-laki', 6300000.00),
(6, 'Reva', 'Perempuan', 5800000.00),
(7, 'Himel', 'Laki-laki', NULL),
(8, 'Vika', 'Perempuan', 5700000.00),
(9, 'Fahran', 'Laki-laki', 6400000.00),
(10, 'Jovan', 'Laki-laki', 6800000.00),
(11, 'Budi Bogor', 'Laki-laki', 6200000.00),
(12, 'Pembalap UP', 'Laki-laki', 6600000.00),
(13, 'PPW', 'Perempuan', 5900000.00);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `departemen`
--
ALTER TABLE `departemen`
  ADD PRIMARY KEY (`id_departemen`),
  ADD KEY `id_karyawan` (`id_karyawan`);

--
-- Indexes for table `karyawan`
--
ALTER TABLE `karyawan`
  ADD PRIMARY KEY (`id_karyawan`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `departemen`
--
ALTER TABLE `departemen`
  ADD CONSTRAINT `departemen_ibfk_1` FOREIGN KEY (`id_karyawan`) REFERENCES `karyawan` (`id_karyawan`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
