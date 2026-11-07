-- --------------------------------------------------------
-- Host:                         
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

-- Dumping data for table akademik_1.dosen: ~0 rows (approximately)

-- Dumping data for table akademik_1.krs: ~0 rows (approximately)

-- Dumping data for table akademik_1.mahasiswa: ~2 rows (approximately)
INSERT INTO `mahasiswa` (`npm`, `nama`, `email`, `prodi`, `angkatan`, `ipk`) VALUES
	('452402', 'Andika Prasetyo', 'akuy@kampus.ac.id', 'Teknik Informatika', '2024', 3.72),
	('452403', 'Fariz Fahreza', 'sully@kampus.ac.id', 'Teknik Informatika', '2024', 3.29);

-- Dumping data for table akademik_1.mata_kuliah: ~0 rows (approximately)

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
