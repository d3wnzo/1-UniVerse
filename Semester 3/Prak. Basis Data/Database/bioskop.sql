-- phpMyAdmin SQL Dump
-- version 6.0.0-dev+20250506.60eb56b50d
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Nov 02, 2025 at 04:40 PM
-- Server version: 8.4.3
-- PHP Version: 8.3.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bioskop`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `id_admin` int NOT NULL,
  `nama_admin` varchar(100) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `password` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`id_admin`, `nama_admin`, `email`, `password`) VALUES
(1, 'Admin 1', 'admin1@mail.com', 'admin123'),
(2, 'Admin 2', 'admin2@mail.com', 'admin123'),
(3, 'Admin 3', 'admin3@mail.com', 'admin123'),
(4, 'Admin 4', 'admin4@mail.com', 'admin123'),
(5, 'Admin 5', 'admin5@mail.com', 'admin123'),
(6, 'Admin 6', 'admin6@mail.com', 'admin123'),
(7, 'Admin 7', 'admin7@mail.com', 'admin123'),
(8, 'Admin 8', 'admin8@mail.com', 'admin123'),
(9, 'Admin 9', 'admin9@mail.com', 'admin123'),
(10, 'Admin 10', 'admin10@mail.com', 'admin123');

-- --------------------------------------------------------

--
-- Table structure for table `detail_pesanan`
--

CREATE TABLE `detail_pesanan` (
  `id_detail` int NOT NULL,
  `id_pesanan` int DEFAULT NULL,
  `id_kursi` int DEFAULT NULL,
  `harga_tiket` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `detail_pesanan`
--

INSERT INTO `detail_pesanan` (`id_detail`, `id_pesanan`, `id_kursi`, `harga_tiket`) VALUES
(1, 1, 1, 50000.00),
(2, 1, 2, 50000.00),
(3, 2, 3, 55000.00),
(4, 3, 4, 40000.00),
(5, 3, 5, 40000.00),
(6, 4, 6, 60000.00),
(7, 4, 7, 60000.00),
(8, 5, 8, 45000.00),
(9, 6, 9, 65000.00),
(10, 7, 10, 70000.00);

-- --------------------------------------------------------

--
-- Table structure for table `e_tiket`
--

CREATE TABLE `e_tiket` (
  `id_tiket` int NOT NULL,
  `id_detail` int DEFAULT NULL,
  `kode_tiket` varchar(50) DEFAULT NULL,
  `waktu_terbit` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `e_tiket`
--

INSERT INTO `e_tiket` (`id_tiket`, `id_detail`, `kode_tiket`, `waktu_terbit`) VALUES
(1, 1, 'TKT-A1', '2025-11-02 16:11:00'),
(2, 2, 'TKT-A2', '2025-11-02 16:11:00'),
(3, 3, 'TKT-B1', '2025-11-02 16:11:00'),
(4, 4, 'TKT-B2', '2025-11-02 16:11:00'),
(5, 5, 'TKT-C1', '2025-11-02 16:11:00'),
(6, 6, 'TKT-C2', '2025-11-02 16:11:00'),
(7, 7, 'TKT-D1', '2025-11-02 16:11:00'),
(8, 8, 'TKT-D2', '2025-11-02 16:11:00'),
(9, 9, 'TKT-E1', '2025-11-02 16:11:00'),
(10, 10, 'TKT-E2', '2025-11-02 16:11:00');

-- --------------------------------------------------------

--
-- Table structure for table `film`
--

CREATE TABLE `film` (
  `id_film` int NOT NULL,
  `judul` varchar(100) DEFAULT NULL,
  `durasi` int DEFAULT NULL,
  `genre` varchar(50) DEFAULT NULL,
  `sutradara` varchar(100) DEFAULT NULL,
  `rating_umur` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `film`
--

INSERT INTO `film` (`id_film`, `judul`, `durasi`, `genre`, `sutradara`, `rating_umur`) VALUES
(1, 'Avengers: Endgame', 180, 'Action', 'Russo Brothers', '13+'),
(2, 'The Batman', 175, 'Action', 'Matt Reeves', '13+'),
(3, 'Frozen II', 120, 'Animation', 'Jennifer Lee', 'SU'),
(4, 'Top Gun: Maverick', 130, 'Action', 'Joseph Kosinski', '13+'),
(5, 'Spirited Away', 125, 'Fantasy', 'Hayao Miyazaki', 'SU'),
(6, 'Inception', 148, 'Sci-Fi', 'Christopher Nolan', '13+'),
(7, 'Joker', 122, 'Drama', 'Todd Phillips', '17+'),
(8, 'Parasite', 132, 'Thriller', 'Bong Joon Ho', '17+'),
(9, 'Interstellar', 169, 'Sci-Fi', 'Christopher Nolan', '13+'),
(10, 'Inside Out', 100, 'Animation', 'Pete Docter', 'SU');

-- --------------------------------------------------------

--
-- Table structure for table `jadwal_tayang`
--

CREATE TABLE `jadwal_tayang` (
  `id_jadwal` int NOT NULL,
  `id_film` int DEFAULT NULL,
  `id_studio` int DEFAULT NULL,
  `tanggal_tayang` date DEFAULT NULL,
  `waktu_mulai` time DEFAULT NULL,
  `waktu_selesai` time DEFAULT NULL,
  `harga_dasar` decimal(10,2) DEFAULT NULL,
  `dibuat_oleh` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `jadwal_tayang`
--

INSERT INTO `jadwal_tayang` (`id_jadwal`, `id_film`, `id_studio`, `tanggal_tayang`, `waktu_mulai`, `waktu_selesai`, `harga_dasar`, `dibuat_oleh`) VALUES
(1, 1, 1, '2025-11-02', '10:00:00', '13:00:00', 50000.00, 1),
(2, 2, 2, '2025-11-02', '14:00:00', '17:00:00', 55000.00, 2),
(3, 3, 3, '2025-11-02', '18:00:00', '20:00:00', 40000.00, 3),
(4, 4, 4, '2025-11-03', '10:00:00', '12:30:00', 60000.00, 4),
(5, 5, 5, '2025-11-03', '13:00:00', '15:00:00', 45000.00, 5),
(6, 6, 6, '2025-11-03', '15:30:00', '18:00:00', 65000.00, 6),
(7, 7, 7, '2025-11-04', '10:00:00', '12:00:00', 70000.00, 7),
(8, 8, 8, '2025-11-04', '12:30:00', '15:00:00', 55000.00, 8),
(9, 9, 9, '2025-11-04', '15:30:00', '18:00:00', 60000.00, 9),
(10, 10, 10, '2025-11-04', '18:30:00', '21:00:00', 50000.00, 10);

-- --------------------------------------------------------

--
-- Table structure for table `kursi`
--

CREATE TABLE `kursi` (
  `id_kursi` int NOT NULL,
  `id_studio` int DEFAULT NULL,
  `kode_kursi` varchar(10) DEFAULT NULL,
  `posisi_baris` char(1) DEFAULT NULL,
  `posisi_kolom` int DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `kursi`
--

INSERT INTO `kursi` (`id_kursi`, `id_studio`, `kode_kursi`, `posisi_baris`, `posisi_kolom`) VALUES
(1, 1, 'A1', 'A', 1),
(2, 1, 'A2', 'A', 2),
(3, 2, 'B1', 'B', 1),
(4, 2, 'B2', 'B', 2),
(5, 3, 'C1', 'C', 1),
(6, 3, 'C2', 'C', 2),
(7, 4, 'D1', 'D', 1),
(8, 4, 'D2', 'D', 2),
(9, 5, 'E1', 'E', 1),
(10, 5, 'E2', 'E', 2);

-- --------------------------------------------------------

--
-- Table structure for table `pengguna`
--

CREATE TABLE `pengguna` (
  `id_pengguna` int NOT NULL,
  `nama` varchar(100) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `password` varchar(100) DEFAULT NULL,
  `no_hp` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `pengguna`
--

INSERT INTO `pengguna` (`id_pengguna`, `nama`, `email`, `password`, `no_hp`) VALUES
(1, 'Andi', 'andi@mail.com', 'pass123', '0811111111'),
(2, 'Budi', 'budi@mail.com', 'pass123', '0812222222'),
(3, 'Citra', 'citra@mail.com', 'pass123', '0813333333'),
(4, 'Dewi', 'dewi@mail.com', 'pass123', '0814444444'),
(5, 'Eko', 'eko@mail.com', 'pass123', '0815555555'),
(6, 'Fani', 'fani@mail.com', 'pass123', '0816666666'),
(7, 'Gilang', 'gilang@mail.com', 'pass123', '0817777777'),
(8, 'Hana', 'hana@mail.com', 'pass123', '0818888888'),
(9, 'Indra', 'indra@mail.com', 'pass123', '0819999999'),
(10, 'Joko', 'joko@mail.com', 'pass123', '0810000000');

-- --------------------------------------------------------

--
-- Table structure for table `pesanan`
--

CREATE TABLE `pesanan` (
  `id_pesanan` int NOT NULL,
  `id_pengguna` int DEFAULT NULL,
  `id_jadwal` int DEFAULT NULL,
  `tanggal_pesan` datetime DEFAULT NULL,
  `total_harga` decimal(10,2) DEFAULT NULL,
  `status_pesanan` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `pesanan`
--

INSERT INTO `pesanan` (`id_pesanan`, `id_pengguna`, `id_jadwal`, `tanggal_pesan`, `total_harga`, `status_pesanan`) VALUES
(1, 1, 1, '2025-11-02 16:11:00', 100000.00, 'dibayar'),
(2, 2, 2, '2025-11-02 16:11:00', 55000.00, 'dibayar'),
(3, 3, 3, '2025-11-02 16:11:00', 80000.00, 'pending'),
(4, 4, 4, '2025-11-02 16:11:00', 120000.00, 'dibayar'),
(5, 5, 5, '2025-11-02 16:11:00', 45000.00, 'batal'),
(6, 6, 6, '2025-11-02 16:11:00', 65000.00, 'dibayar'),
(7, 7, 7, '2025-11-02 16:11:00', 70000.00, 'pending'),
(8, 8, 8, '2025-11-02 16:11:00', 110000.00, 'dibayar'),
(9, 9, 9, '2025-11-02 16:11:00', 60000.00, 'dibayar'),
(10, 10, 10, '2025-11-02 16:11:00', 50000.00, 'dibayar');

-- --------------------------------------------------------

--
-- Table structure for table `studio`
--

CREATE TABLE `studio` (
  `id_studio` int NOT NULL,
  `nama_studio` varchar(50) DEFAULT NULL,
  `kapasitas` int DEFAULT NULL,
  `lokasi` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

--
-- Dumping data for table `studio`
--

INSERT INTO `studio` (`id_studio`, `nama_studio`, `kapasitas`, `lokasi`) VALUES
(1, 'Studio 1', 50, 'Lantai 1'),
(2, 'Studio 2', 60, 'Lantai 1'),
(3, 'Studio 3', 80, 'Lantai 2'),
(4, 'Studio 4', 100, 'Lantai 2'),
(5, 'Studio 5', 40, 'Lantai 3'),
(6, 'Studio 6', 70, 'Lantai 3'),
(7, 'Studio 7', 90, 'Lantai 4'),
(8, 'Studio 8', 120, 'Lantai 4'),
(9, 'Studio 9', 50, 'Lantai 5'),
(10, 'Studio 10', 150, 'Lantai 5');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`id_admin`);

--
-- Indexes for table `detail_pesanan`
--
ALTER TABLE `detail_pesanan`
  ADD PRIMARY KEY (`id_detail`),
  ADD UNIQUE KEY `id_pesanan` (`id_pesanan`,`id_kursi`),
  ADD KEY `id_kursi` (`id_kursi`);

--
-- Indexes for table `e_tiket`
--
ALTER TABLE `e_tiket`
  ADD PRIMARY KEY (`id_tiket`),
  ADD UNIQUE KEY `kode_tiket` (`kode_tiket`),
  ADD KEY `id_detail` (`id_detail`);

--
-- Indexes for table `film`
--
ALTER TABLE `film`
  ADD PRIMARY KEY (`id_film`);

--
-- Indexes for table `jadwal_tayang`
--
ALTER TABLE `jadwal_tayang`
  ADD PRIMARY KEY (`id_jadwal`),
  ADD KEY `id_film` (`id_film`),
  ADD KEY `id_studio` (`id_studio`),
  ADD KEY `dibuat_oleh` (`dibuat_oleh`);

--
-- Indexes for table `kursi`
--
ALTER TABLE `kursi`
  ADD PRIMARY KEY (`id_kursi`),
  ADD KEY `id_studio` (`id_studio`);

--
-- Indexes for table `pengguna`
--
ALTER TABLE `pengguna`
  ADD PRIMARY KEY (`id_pengguna`);

--
-- Indexes for table `pesanan`
--
ALTER TABLE `pesanan`
  ADD PRIMARY KEY (`id_pesanan`),
  ADD KEY `id_pengguna` (`id_pengguna`),
  ADD KEY `id_jadwal` (`id_jadwal`);

--
-- Indexes for table `studio`
--
ALTER TABLE `studio`
  ADD PRIMARY KEY (`id_studio`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `id_admin` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `detail_pesanan`
--
ALTER TABLE `detail_pesanan`
  MODIFY `id_detail` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `e_tiket`
--
ALTER TABLE `e_tiket`
  MODIFY `id_tiket` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `film`
--
ALTER TABLE `film`
  MODIFY `id_film` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `jadwal_tayang`
--
ALTER TABLE `jadwal_tayang`
  MODIFY `id_jadwal` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `kursi`
--
ALTER TABLE `kursi`
  MODIFY `id_kursi` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `pengguna`
--
ALTER TABLE `pengguna`
  MODIFY `id_pengguna` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `pesanan`
--
ALTER TABLE `pesanan`
  MODIFY `id_pesanan` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `studio`
--
ALTER TABLE `studio`
  MODIFY `id_studio` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `detail_pesanan`
--
ALTER TABLE `detail_pesanan`
  ADD CONSTRAINT `detail_pesanan_ibfk_1` FOREIGN KEY (`id_pesanan`) REFERENCES `pesanan` (`id_pesanan`) ON DELETE CASCADE,
  ADD CONSTRAINT `detail_pesanan_ibfk_2` FOREIGN KEY (`id_kursi`) REFERENCES `kursi` (`id_kursi`) ON DELETE CASCADE;

--
-- Constraints for table `e_tiket`
--
ALTER TABLE `e_tiket`
  ADD CONSTRAINT `e_tiket_ibfk_1` FOREIGN KEY (`id_detail`) REFERENCES `detail_pesanan` (`id_detail`) ON DELETE CASCADE;

--
-- Constraints for table `jadwal_tayang`
--
ALTER TABLE `jadwal_tayang`
  ADD CONSTRAINT `jadwal_tayang_ibfk_1` FOREIGN KEY (`id_film`) REFERENCES `film` (`id_film`) ON DELETE CASCADE,
  ADD CONSTRAINT `jadwal_tayang_ibfk_2` FOREIGN KEY (`id_studio`) REFERENCES `studio` (`id_studio`) ON DELETE CASCADE,
  ADD CONSTRAINT `jadwal_tayang_ibfk_3` FOREIGN KEY (`dibuat_oleh`) REFERENCES `admin` (`id_admin`) ON DELETE CASCADE;

--
-- Constraints for table `kursi`
--
ALTER TABLE `kursi`
  ADD CONSTRAINT `kursi_ibfk_1` FOREIGN KEY (`id_studio`) REFERENCES `studio` (`id_studio`) ON DELETE CASCADE;

--
-- Constraints for table `pesanan`
--
ALTER TABLE `pesanan`
  ADD CONSTRAINT `pesanan_ibfk_1` FOREIGN KEY (`id_pengguna`) REFERENCES `pengguna` (`id_pengguna`) ON DELETE CASCADE,
  ADD CONSTRAINT `pesanan_ibfk_2` FOREIGN KEY (`id_jadwal`) REFERENCES `jadwal_tayang` (`id_jadwal`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
