-- MySQL dump 10.13  Distrib 8.0.40, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: exbbdd2025
-- ------------------------------------------------------
-- Server version	8.0.40

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
-- Table structure for table `equipo`
--

DROP TABLE IF EXISTS `equipo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `equipo` (
  `CODIGO` int unsigned NOT NULL AUTO_INCREMENT,
  `CIUDAD` enum('MADRID','BARCELONA','SEVILLA') DEFAULT NULL,
  `AFORO` tinyint DEFAULT NULL,
  `ANO_FUNDACION` year DEFAULT NULL,
  `NOM_ESTADIO` varchar(45) DEFAULT NULL,
  `NOM_EQUIPO` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`CODIGO`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `equipo`
--

LOCK TABLES `equipo` WRITE;
/*!40000 ALTER TABLE `equipo` DISABLE KEYS */;
INSERT INTO `equipo` VALUES (1,'MADRID',15,1990,'METROPOLITANO','SOCIEDAD'),(2,'BARCELONA',100,1970,'METROPOLITANO','SOCIEDAD'),(5,'MADRID',100,1990,'METROPOLITANO','SOCIEDAD');
/*!40000 ALTER TABLE `equipo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `gol`
--

DROP TABLE IF EXISTS `gol`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `gol` (
  `MINUTO_GOL` time NOT NULL,
  `DESCRIPCION` text,
  `JUGADOR_CODIGO` int unsigned NOT NULL,
  PRIMARY KEY (`MINUTO_GOL`,`JUGADOR_CODIGO`),
  KEY `fk_GOL_JUGADOR1_idx` (`JUGADOR_CODIGO`),
  CONSTRAINT `fk_GOL_JUGADOR1` FOREIGN KEY (`JUGADOR_CODIGO`) REFERENCES `jugador` (`CODIGO`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `gol`
--

LOCK TABLES `gol` WRITE;
/*!40000 ALTER TABLE `gol` DISABLE KEYS */;
INSERT INTO `gol` VALUES ('12:52:30','Gol desde mitad de campo',50);
/*!40000 ALTER TABLE `gol` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `jugador`
--

DROP TABLE IF EXISTS `jugador`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `jugador` (
  `CODIGO` int unsigned NOT NULL AUTO_INCREMENT,
  `NOMBRE` varchar(20) DEFAULT NULL,
  `NACIONALIDAD` enum('ESPANOLA','BRITANICA','PORTUGUESA') DEFAULT NULL,
  `FEC_NAC` date DEFAULT NULL,
  `POSICION` enum('DEFENSA','PORTERO','CENTROCAMPISTA') DEFAULT NULL,
  `EQUIPO_CODIGO` int unsigned NOT NULL,
  PRIMARY KEY (`CODIGO`,`EQUIPO_CODIGO`),
  KEY `fk_JUGADOR_EQUIPO1_idx` (`EQUIPO_CODIGO`),
  CONSTRAINT `fk_JUGADOR_EQUIPO1` FOREIGN KEY (`EQUIPO_CODIGO`) REFERENCES `equipo` (`CODIGO`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=51 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `jugador`
--

LOCK TABLES `jugador` WRITE;
/*!40000 ALTER TABLE `jugador` DISABLE KEYS */;
INSERT INTO `jugador` VALUES (50,'JUAN','ESPANOLA','2018-12-12','DEFENSA',1);
/*!40000 ALTER TABLE `jugador` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `partido`
--

DROP TABLE IF EXISTS `partido`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `partido` (
  `CODIGO` int unsigned NOT NULL AUTO_INCREMENT,
  `FECHA` date DEFAULT NULL,
  `GOL_CASA` varchar(45) DEFAULT NULL,
  `GOL_FUERA` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`CODIGO`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `partido`
--

LOCK TABLES `partido` WRITE;
/*!40000 ALTER TABLE `partido` DISABLE KEYS */;
INSERT INTO `partido` VALUES (8,'2024-01-01','NO GOL','GOL'),(25,'2018-05-05','GOL','NO GOL');
/*!40000 ALTER TABLE `partido` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `presidente`
--

DROP TABLE IF EXISTS `presidente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `presidente` (
  `DNI` varchar(9) NOT NULL,
  `NOMBRE` varchar(20) DEFAULT NULL,
  `APELLIDO` varchar(50) DEFAULT NULL,
  `DIREC` varchar(90) DEFAULT NULL,
  `ANO_ELECCION` year DEFAULT NULL,
  `EQUIPO_CODIGO` int unsigned NOT NULL,
  PRIMARY KEY (`DNI`),
  KEY `fk_PRESIDENTE_EQUIPO1_idx` (`EQUIPO_CODIGO`),
  CONSTRAINT `fk_PRESIDENTE_EQUIPO1` FOREIGN KEY (`EQUIPO_CODIGO`) REFERENCES `equipo` (`CODIGO`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `presidente`
--

LOCK TABLES `presidente` WRITE;
/*!40000 ALTER TABLE `presidente` DISABLE KEYS */;
INSERT INTO `presidente` VALUES ('12345678K','Carmelo','Rios','Calle Juncal',2008,1);
/*!40000 ALTER TABLE `presidente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tiene`
--

DROP TABLE IF EXISTS `tiene`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tiene` (
  `GOL_MINUTO_GOL` time NOT NULL,
  `PARTIDO_CODIGO` int unsigned NOT NULL,
  `TIPO` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`GOL_MINUTO_GOL`,`PARTIDO_CODIGO`),
  KEY `fk_GOL_has_PARTIDO_PARTIDO1_idx` (`PARTIDO_CODIGO`),
  KEY `fk_GOL_has_PARTIDO_GOL_idx` (`GOL_MINUTO_GOL`),
  CONSTRAINT `fk_GOL_has_PARTIDO_GOL` FOREIGN KEY (`GOL_MINUTO_GOL`) REFERENCES `gol` (`MINUTO_GOL`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_GOL_has_PARTIDO_PARTIDO1` FOREIGN KEY (`PARTIDO_CODIGO`) REFERENCES `partido` (`CODIGO`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tiene`
--

LOCK TABLES `tiene` WRITE;
/*!40000 ALTER TABLE `tiene` DISABLE KEYS */;
/*!40000 ALTER TABLE `tiene` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-01-24 10:46:23
