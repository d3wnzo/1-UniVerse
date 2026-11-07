-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               8.4.3 - MySQL Community Server - GPL
-- Server OS:                    Win64
-- HeidiSQL Version:             12.8.0.6908
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for akademik_1
CREATE DATABASE IF NOT EXISTS `akademik_1` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `akademik_1`;

-- Dumping structure for table akademik_1.dosen
CREATE TABLE IF NOT EXISTS `dosen` (
  `nidn` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL,
  `nama` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `email` varchar(120) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`nidn`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Dumping data for table akademik_1.dosen: ~2 rows (approximately)
INSERT INTO `dosen` (`nidn`, `nama`, `email`) VALUES
	('123', 'Fikri Ash, M.T', 'dosen1@gmail.com'),
	('456', 'Bobby Kartanegara, M.Bob', 'dosen2@gmail.com');

-- Dumping structure for table akademik_1.krs
CREATE TABLE IF NOT EXISTS `krs` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `npm` varchar(15) COLLATE utf8mb4_unicode_ci NOT NULL,
  `kode_mk` varchar(12) COLLATE utf8mb4_unicode_ci NOT NULL,
  `semester` tinyint unsigned NOT NULL,
  `tahun_ajaran` varchar(9) COLLATE utf8mb4_unicode_ci NOT NULL,
  `nilai_huruf` char(2) COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `uq_krs` (`npm`,`kode_mk`,`semester`,`tahun_ajaran`),
  KEY `fk_kr_mk` (`kode_mk`),
  CONSTRAINT `fk_kr_mk` FOREIGN KEY (`kode_mk`) REFERENCES `mata_kuliah` (`kode_mk`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `fk_krs_mahasiswa` FOREIGN KEY (`npm`) REFERENCES `mahasiswa` (`npm`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Dumping data for table akademik_1.krs: ~0 rows (approximately)

-- Dumping structure for table akademik_1.mahasiswa
CREATE TABLE IF NOT EXISTS `mahasiswa` (
  `npm` varchar(15) COLLATE utf8mb4_unicode_ci NOT NULL,
  `nama` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `email` varchar(120) COLLATE utf8mb4_unicode_ci NOT NULL,
  `prodi` varchar(80) COLLATE utf8mb4_unicode_ci NOT NULL,
  `angkatan` year NOT NULL,
  `ipk` decimal(3,2) DEFAULT '0.00',
  PRIMARY KEY (`npm`),
  UNIQUE KEY `email` (`email`),
  CONSTRAINT `mahasiswa_chk_1` CHECK ((`ipk` between 0.00 and 4.00))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Dumping data for table akademik_1.mahasiswa: ~3 rows (approximately)
INSERT INTO `mahasiswa` (`npm`, `nama`, `email`, `prodi`, `angkatan`, `ipk`) VALUES
	('4123', 'Akmal Alief Ramadhan', 'bob@gmail.com', 'Teknik Informatika', '2025', 3.50),
	('4456', 'Fikri Ash', 'ucok@yahoo.com', 'Teknik Informatika', '2024', 3.50),
	('4789', 'Nayunda Krisna', 'kokor@gmail.com', 'Teknik Informatika', '2024', 3.20);

-- Dumping structure for table akademik_1.mata_kuliah
CREATE TABLE IF NOT EXISTS `mata_kuliah` (
  `kode_mk` varchar(12) COLLATE utf8mb4_unicode_ci NOT NULL,
  `nama_mk` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL,
  `sks` tinyint unsigned NOT NULL,
  `nidn` varchar(20) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`kode_mk`),
  KEY `fk_mk_dosen` (`nidn`),
  CONSTRAINT `fk_mk_dosen` FOREIGN KEY (`nidn`) REFERENCES `dosen` (`nidn`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- Dumping data for table akademik_1.mata_kuliah: ~2 rows (approximately)
INSERT INTO `mata_kuliah` (`kode_mk`, `nama_mk`, `sks`, `nidn`) VALUES
	('1', 'Pemrograman Berbasis Web', 3, '123'),
	('2', 'Pemrograman Paralel', 3, '456');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
