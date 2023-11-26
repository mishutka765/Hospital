-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: newschema
-- ------------------------------------------------------
-- Server version	8.2.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `doctor`
--

DROP TABLE IF EXISTS `doctor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `doctor` (
  `docID` int NOT NULL AUTO_INCREMENT,
  `docName` varchar(64) NOT NULL,
  `docSurname` varchar(64) NOT NULL,
  `docMiddleName` varchar(64) DEFAULT NULL,
  `docSpeciality` varchar(255) DEFAULT NULL,
  `docEmploymentDate` date DEFAULT NULL,
  `docExpirienceYears` int DEFAULT NULL,
  `docRating` int DEFAULT NULL,
  `docMaxDayClients` int DEFAULT NULL,
  `docWorkingDays` varchar(255) DEFAULT NULL,
  `docWorkingHoursStart` time DEFAULT NULL,
  `docWorkingHoursEnd` time DEFAULT NULL,
  `docReviews` text,
  `docWorkPlace` int DEFAULT NULL,
  PRIMARY KEY (`docID`),
  KEY `docWorkPlace` (`docWorkPlace`),
  CONSTRAINT `doctor_ibfk_1` FOREIGN KEY (`docWorkPlace`) REFERENCES `hospital` (`hospitalID`),
  CONSTRAINT `doctor_chk_1` CHECK ((`docRating` between 0 and 10)),
  CONSTRAINT `doctor_chk_2` CHECK ((`docMaxDayClients` between 0 and 40))
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doctor`
--

LOCK TABLES `doctor` WRITE;
/*!40000 ALTER TABLE `doctor` DISABLE KEYS */;
INSERT INTO `doctor` VALUES (1,'Alexandr','Pushkin','Sergeevich','Cardiologist','2023-01-15',10,9,20,'Monday','08:00:00','14:30:00','Excellent doctor',3),(2,'Evgeny','Uvarov','Viktorovich','Hematologist','2022-11-05',7,8,18,'Tuesday','09:00:00','16:30:00','Great with kids',6),(3,'Lev','Sokolov','Petrovich','Cardiologist','2022-01-01',5,9,20,'Tuesday','09:00:00','17:00:00','Doctor1 Reviews',6),(4,'Valery ','Smirnov','Mikhailovich','Oculist','2022-02-01',6,8,18,'Friday','08:30:00','16:30:00','Doctor2 Reviews',5),(5,'Pyotr','Denisov','Denisovich','Neurologist','2022-03-01',7,7,16,'Monday','08:00:00','16:00:00','Doctor3 Reviews',5),(6,'Timofey','Romanov','Viktorovich','Dentist','2022-04-01',8,8,20,'Wednesday','09:00:00','17:00:00','Doctor4 Reviews',4),(7,'Nikolay','Baranov','Yegorovich','Dentist','2022-05-01',9,9,18,'Friday','09:30:00','17:30:00','Doctor5 Reviews',4),(8,'Nikolay ','Matveev','Nikolaevich','Obstetrician-gynecologist','2022-06-01',10,10,22,'Thursday','10:00:00','18:00:00','Doctor6 Reviews',3),(9,'Nikolay ','Medvedev','Vasilievich','Gastroenterologist','2022-07-01',6,9,19,'Wednesday','08:30:00','17:30:00','Doctor7 Reviews',3),(10,'Anton ','Egorov','Antonovich','Oncologist','2022-08-01',7,7,16,'Monday','08:00:00','16:00:00','Doctor8 Reviews',2),(11,'Doctor9','Lastname9','Middle9','Speciality9','2022-09-01',8,8,20,NULL,'09:30:00','17:30:00','Doctor9 Reviews',2),(12,'Viktor','Xvoyka','Pavlovich','Cardiologist','2022-10-01',9,10,21,'Friday','10:30:00','18:30:00','Doctor10 Reviews',3);
/*!40000 ALTER TABLE `doctor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `doctorworkingdays`
--

DROP TABLE IF EXISTS `doctorworkingdays`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `doctorworkingdays` (
  `doctorID` int NOT NULL,
  `workingDay` enum('Monday','Tuesday','Wednesday','Thursday','Friday','Saturday') NOT NULL,
  PRIMARY KEY (`doctorID`,`workingDay`),
  CONSTRAINT `doctorworkingdays_ibfk_1` FOREIGN KEY (`doctorID`) REFERENCES `doctor` (`docID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doctorworkingdays`
--

LOCK TABLES `doctorworkingdays` WRITE;
/*!40000 ALTER TABLE `doctorworkingdays` DISABLE KEYS */;
INSERT INTO `doctorworkingdays` VALUES (1,'Monday'),(1,'Tuesday'),(1,'Wednesday'),(2,'Tuesday'),(2,'Thursday'),(3,'Wednesday'),(3,'Friday'),(4,'Monday'),(4,'Wednesday'),(5,'Tuesday'),(5,'Thursday'),(6,'Wednesday'),(6,'Friday'),(7,'Monday'),(7,'Tuesday'),(8,'Wednesday'),(8,'Thursday'),(9,'Monday'),(9,'Wednesday');
/*!40000 ALTER TABLE `doctorworkingdays` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hospital`
--

DROP TABLE IF EXISTS `hospital`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `hospital` (
  `hospitalID` int NOT NULL AUTO_INCREMENT,
  `hospitalIsPrivate` tinyint(1) DEFAULT NULL,
  `hospitalAddress` varchar(255) DEFAULT NULL,
  `hospitalDistrict` varchar(255) DEFAULT NULL,
  `hospitalName` varchar(255) DEFAULT NULL,
  `hospitalRating` int DEFAULT NULL,
  PRIMARY KEY (`hospitalID`),
  CONSTRAINT `hospital_chk_1` CHECK ((`hospitalRating` between 0 and 10))
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hospital`
--

LOCK TABLES `hospital` WRITE;
/*!40000 ALTER TABLE `hospital` DISABLE KEYS */;
INSERT INTO `hospital` VALUES (1,0,'Chumachenko Street, 21A, Zaporizhzhia, Zaporizhia region, 69000','Kommunarsky','Communal non-profit enterprise \"City Hospital No. 1\" of the ZMR',9),(2,0,'456 Elm St, CityB, DistrictB','Shevchenkivskyi','City Hospital No. 8',7),(3,0,'Оріхівське шосе, 10, Запоріжжя, Запорізька область, 69000','Kommunarsky','Zaporizhia Regional Clinical Hospital',8),(4,0,'Optimistic Street, 1, Zaporizhzhia, Zaporizhia region, 69000','Zavodskoy','City Hospital No. 4',5),(5,1,'Liza Chaikina Street, 69, Zaporizhzhia, Zaporizhia region, 69061','Zavodskoy','The First Private Polyclinic - Branch No. 3 \"Livoberezhnaya\"',5),(6,1,'Dniprovska Street, 24, Zaporizhzhia, Zaporizhia region, 69063','Oleksandrivskyi ','St. Nicholas Clinic (Department of Family Medicine)',10);
/*!40000 ALTER TABLE `hospital` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `userID` int NOT NULL AUTO_INCREMENT,
  `userName` varchar(64) NOT NULL,
  `userSurname` varchar(64) NOT NULL,
  `userMiddleName` varchar(64) DEFAULT NULL,
  `userPhone` varchar(25) DEFAULT NULL,
  `userPassword` varchar(64) NOT NULL,
  `userAge` int DEFAULT NULL,
  `userBirthDate` date DEFAULT NULL,
  `userFamilyDoctor` int DEFAULT NULL,
  PRIMARY KEY (`userID`),
  KEY `userFamilyDoctor_idx` (`userFamilyDoctor`),
  CONSTRAINT `userFamilyDoctor` FOREIGN KEY (`userFamilyDoctor`) REFERENCES `doctor` (`docID`)
) ENGINE=InnoDB AUTO_INCREMENT=66 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (58,'Egor','Panchenko','Olexandrovich','+380974966536','t0ktzX',19,'2004-01-21',NULL),(61,'Oleg','Rozin','Viktorovich','+380976544376','nVGsqX',39,'1984-06-22',1),(62,'Viktor','Karas','Petrovich','+380934511265','VrSvLX',9,'2014-06-10',1),(63,'Petya','Samogon','Alexandrovich','+380965433256','t0ktzX',28,'1995-10-12',1),(64,'Kolya','Gurov','Petrovich','+380 975 96 67 31','blhyqX',33,'1990-07-05',1),(65,'Fedya','Karapityan','Olegovich','+380 87 234 45 12','nVGsqX',33,'1990-07-11',1);
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `visits`
--

DROP TABLE IF EXISTS `visits`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `visits` (
  `visitID` int NOT NULL AUTO_INCREMENT,
  `userID` int DEFAULT NULL,
  `doctorID` int DEFAULT NULL,
  `visitDate` date DEFAULT NULL,
  `visitTime` time DEFAULT NULL,
  `diagnosis` varchar(255) DEFAULT NULL,
  `prescription` text,
  `visitStatus` tinyint DEFAULT '0' COMMENT '1 planned, 2 - past',
  PRIMARY KEY (`visitID`),
  KEY `userID_idx` (`userID`),
  KEY `doctorID_idx` (`doctorID`),
  CONSTRAINT `doctorID` FOREIGN KEY (`doctorID`) REFERENCES `doctor` (`docID`),
  CONSTRAINT `userID` FOREIGN KEY (`userID`) REFERENCES `user` (`userID`)
) ENGINE=InnoDB AUTO_INCREMENT=41 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `visits`
--

LOCK TABLES `visits` WRITE;
/*!40000 ALTER TABLE `visits` DISABLE KEYS */;
INSERT INTO `visits` VALUES (1,58,12,'2023-11-17','16:00:00','DefDiagnosis','Defprescription',1),(2,58,12,'2023-11-17','10:30:00','Migren','Defprescription',1),(3,58,12,'2023-11-17','13:30:00','DefDiagnosis','Defprescription',1),(28,61,12,'2023-11-17','14:30:00','BolitZivot','Defprescription',1),(29,61,12,'2023-11-17','14:00:00','DefDiagnosis','Defprescription',1),(30,61,4,'2023-11-17','09:00:00','Oko','Defprescription',1),(31,61,3,'2023-11-21','09:00:00','DefDiagnosis','Defprescription',1),(32,61,5,'2023-11-20','08:30:00','DefDiagnosis','Defprescription',1),(33,61,7,'2023-11-17','17:30:00','DefDiagnosis','Defprescription',1),(34,58,6,'2023-11-22','17:00:00','DefDiagnosis','Defprescription',1),(35,58,6,'2023-11-15','11:30:00','DefDiagnosis','Defprescription',1),(36,58,6,'2024-01-17','09:00:00','DefDiagnosis','Defprescription',1),(37,58,12,'2023-12-01','15:30:00','DefDiagnosis','Defprescription',1),(38,58,12,'2023-12-01','18:30:00','DefDiagnosis','Defprescription',1),(39,58,12,'2023-12-01','18:00:00','DefDiagnosis','Defprescription',1),(40,65,12,'2023-11-17','15:00:00','Golova','Defprescription',1);
/*!40000 ALTER TABLE `visits` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-11-14 10:45:32
