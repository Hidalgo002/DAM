CREATE DATABASE  IF NOT EXISTS `BBDD` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `BBDD`;
-- MySQL dump 10.13  Distrib 8.0.22, for macos10.15 (x86_64)
--
-- Host: 127.0.0.1    Database: BBDD
-- ------------------------------------------------------
-- Server version	8.0.22

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
-- Table structure for table `Cliente`
--

DROP TABLE IF EXISTS `Cliente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Cliente` (
  `n_cliente` int NOT NULL,
  `nombre` varchar(45) DEFAULT NULL,
  `direccion` varchar(45) DEFAULT NULL,
  `telefono` int DEFAULT NULL,
  `poblacion` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`n_cliente`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Cliente`
--

LOCK TABLES `Cliente` WRITE;
/*!40000 ALTER TABLE `Cliente` DISABLE KEYS */;
INSERT INTO `Cliente` VALUES (0,'Ana','Calle Amarillo',912685941,'Madrid'),(1,'Ana','Calle Azul',912340123,'Toledo'),(2,'Santiago','Calle Amarillo',912685941,'Toledo'),(3,'Luis','Calle verde',987345123,'Barcelona'),(4,'Luis','Calle Amarillo',912685941,'Barcelona'),(5,'Maria','Calle roja',912685941,'Sevilla'),(6,'Mercedes','Calle Azul',912685941,'Valladolid'),(7,'Marcos','Calle Azul',982323212,'Toledo'),(8,'Mercedes','Calle roja',982323212,'Toledo'),(9,'Ana','Calle Amarillo',912340123,'Toledo'),(10,'Santiago','Calle roja',912340123,'Sevilla'),(11,'Teo','Calle rosa',987345123,'Sevilla'),(12,'Lorena','Calle Azul',987345123,'Barcelona'),(13,'Maria','Calle Azul',912340123,'Valladolid'),(14,'Mercedes','Calle Azul',912340123,'Barcelona'),(15,'Lorena','Calle Azul',982323212,'Toledo'),(16,'Pablo','Calle Azul',912340123,'Sevilla'),(17,'Ana','Calle rosa',982323212,'Madrid'),(18,'Mercedes','Calle Azul',982323212,'Toledo'),(19,'Teo','Calle verde',987345123,'Madrid'),(20,'Marcos','Calle roja',912340123,'Valladolid'),(21,'Miguel','Calle verde',987345123,'Barcelona'),(22,'Teo','Calle verde',912685941,'Madrid'),(23,'Pablo','Calle roja',982323212,'Toledo'),(24,'Pablo','Calle Amarillo',982323212,'Sevilla'),(25,'Lorena','Calle Azul',982323212,'Valladolid'),(26,'Marcos','Calle Amarillo',912685941,'Toledo'),(27,'Marcos','Calle rosa',912685941,'Barcelona'),(28,'Maria','Calle Azul',912340123,'Barcelona'),(29,'Lorena','Calle verde',982323212,'Sevilla'),(30,'Luis','Calle verde',912340123,'Toledo'),(31,'Marcos','Calle Amarillo',912340123,'Madrid'),(32,'Santiago','Calle rosa',912685941,'Barcelona'),(33,'Marcos','Calle roja',912340123,'Madrid'),(34,'Pablo','Calle roja',982323212,'Sevilla'),(35,'Miguel','Calle Amarillo',912685941,'Sevilla'),(36,'Ana','Calle verde',919293349,'Valladolid'),(37,'Miguel','Calle Azul',919293349,'Sevilla'),(38,'Pablo','Calle roja',987345123,'Madrid'),(39,'Pablo','Calle Amarillo',912340123,'Madrid'),(40,'Santiago','Calle roja',982323212,'Valladolid'),(41,'Maria','Calle Azul',987345123,'Madrid'),(42,'Teo','Calle verde',982323212,'Sevilla'),(43,'Marcos','Calle Amarillo',987345123,'Barcelona'),(44,'Marcos','Calle Azul',982323212,'Barcelona'),(45,'Mercedes','Calle Amarillo',912685941,'Valladolid'),(46,'Lorena','Calle rosa',982323212,'Barcelona'),(47,'Miguel','Calle Azul',982323212,'Toledo'),(48,'Lorena','Calle roja',987345123,'Valladolid'),(49,'Ana','Calle Amarillo',987345123,'Sevilla'),(50,'Pablo','Calle verde',987345123,'Valladolid');
/*!40000 ALTER TABLE `Cliente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Producto`
--

DROP TABLE IF EXISTS `Producto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Producto` (
  `cod_producto` int NOT NULL,
  `nombre` varchar(45) DEFAULT NULL,
  `precio` int DEFAULT NULL,
  PRIMARY KEY (`cod_producto`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Producto`
--

LOCK TABLES `Producto` WRITE;
/*!40000 ALTER TABLE `Producto` DISABLE KEYS */;
INSERT INTO `Producto` VALUES (1,'abrigo',3907),(2,'abrigo',4701),(3,'abrigo',1847),(4,'vestido',2287),(5,'libro',4559),(6,'libro',310),(7,'camiseta',3760),(8,'libro',244),(9,'vestido',87),(10,'camiseta',3849),(11,'camiseta',4718),(12,'camiseta',1388),(13,'lapiz',3812),(14,'lapiz',3399),(15,'libro',4069),(16,'vestido',2951),(17,'libro',3669),(18,'ordenador',2597),(19,'libro',2677),(20,'abrigo',79),(21,'lapiz',3700),(22,'abrigo',4949),(23,'camiseta',3673),(24,'libro',4218),(25,'pantalon',1727),(26,'vestido',4120),(27,'camiseta',96),(28,'libro',1865),(29,'libro',4839),(30,'pantalon',1806),(31,'ordenador',1408),(32,'libro',4589),(33,'abrigo',114),(34,'vestido',3297),(35,'libro',4774),(36,'pantalon',1381),(37,'lapiz',118),(38,'camiseta',2286),(39,'ordenador',2876),(40,'vestido',255);
/*!40000 ALTER TABLE `Producto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `venta`
--

DROP TABLE IF EXISTS `venta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `venta` (
  `Cliente_n_cliente` int NOT NULL,
  `Producto_cod_producto` int NOT NULL,
  `cantidad` varchar(45) DEFAULT NULL,
  `id_venta` int NOT NULL,
  PRIMARY KEY (`Cliente_n_cliente`,`Producto_cod_producto`,`id_venta`),
  KEY `fk_Cliente_has_Producto_Producto1_idx` (`Producto_cod_producto`),
  KEY `fk_Cliente_has_Producto_Cliente_idx` (`Cliente_n_cliente`),
  CONSTRAINT `fk_Cliente_has_Producto_Cliente` FOREIGN KEY (`Cliente_n_cliente`) REFERENCES `Cliente` (`n_cliente`),
  CONSTRAINT `fk_Cliente_has_Producto_Producto1` FOREIGN KEY (`Producto_cod_producto`) REFERENCES `Producto` (`cod_producto`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `venta`
--

LOCK TABLES `venta` WRITE;
/*!40000 ALTER TABLE `venta` DISABLE KEYS */;
INSERT INTO `venta` VALUES (2,12,'3',5),(3,15,'13',4),(4,13,'3',4),(4,15,'24',6),(4,23,'3',6),(8,17,'25',5),(9,8,'25',9),(10,4,'21',1),(10,17,'28',7),(14,19,'21',9),(14,24,'14',8),(15,16,'25',8),(18,24,'12',2),(19,9,'8',3),(19,25,'16',0),(22,29,'9',2),(23,3,'4',7),(46,13,'3',4);
/*!40000 ALTER TABLE `venta` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-06-22  0:16:10
