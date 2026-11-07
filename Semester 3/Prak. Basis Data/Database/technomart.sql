-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:8889
-- Generation Time: Oct 20, 2025 at 10:09 AM
-- Server version: 8.0.40
-- PHP Version: 8.3.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `technomart`
--

-- --------------------------------------------------------

--
-- Table structure for table `cabang`
--

CREATE TABLE `cabang` (
  `id_cabang` char(6) COLLATE utf8mb4_general_ci NOT NULL,
  `nama_cabang` varchar(50) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `kota` varchar(30) COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `cabang`
--

INSERT INTO `cabang` (`id_cabang`, `nama_cabang`, `kota`) VALUES
('CBG001', 'TechnoMart Jakarta', 'Jakarta'),
('CBG002', 'TechnoMart Depok', 'Depok'),
('CBG003', 'TechnoMart Bekasi', 'Bekasi');

-- --------------------------------------------------------

--
-- Table structure for table `penjualan`
--

CREATE TABLE `penjualan` (
  `id_transaksi` int NOT NULL,
  `id_cabang` char(6) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `tanggal_transaksi` date DEFAULT NULL,
  `total_penjualan` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `penjualan`
--

INSERT INTO `penjualan` (`id_transaksi`, `id_cabang`, `tanggal_transaksi`, `total_penjualan`) VALUES
(1, 'CBG001', '2025-10-01', 3500000),
(2, 'CBG001', '2025-10-02', 2700000),
(3, 'CBG001', '2025-10-03', 4100000),
(4, 'CBG001', '2025-10-04', 3300000),
(5, 'CBG002', '2025-10-01', 4200000),
(6, 'CBG002', '2025-10-02', 3100000),
(7, 'CBG002', '2025-10-03', 2950000),
(8, 'CBG002', '2025-10-04', 3800000),
(9, 'CBG003', '2025-10-01', 2500000),
(10, 'CBG003', '2025-10-02', 3900000),
(11, 'CBG003', '2025-10-03', 3400000),
(12, 'CBG003', '2025-10-04', 2800000);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cabang`
--
ALTER TABLE `cabang`
  ADD PRIMARY KEY (`id_cabang`);

--
-- Indexes for table `penjualan`
--
ALTER TABLE `penjualan`
  ADD PRIMARY KEY (`id_transaksi`),
  ADD KEY `id_cabang` (`id_cabang`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `penjualan`
--
ALTER TABLE `penjualan`
  MODIFY `id_transaksi` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `penjualan`
--
ALTER TABLE `penjualan`
  ADD CONSTRAINT `penjualan_ibfk_1` FOREIGN KEY (`id_cabang`) REFERENCES `cabang` (`id_cabang`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
