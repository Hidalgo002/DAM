-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema 4Ejercicio
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema 4Ejercicio
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `4Ejercicio` DEFAULT CHARACTER SET utf8 ;
USE `4Ejercicio` ;

-- -----------------------------------------------------
-- Table `4Ejercicio`.`CAMION`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `4Ejercicio`.`CAMION` (
  `MATRICULA` VARCHAR(7) NOT NULL,
  `POTENCIA` VARCHAR(20) NULL,
  `MODELO` VARCHAR(20) NULL,
  `TIPO` VARCHAR(20) NULL,
  PRIMARY KEY (`MATRICULA`),
  UNIQUE INDEX `MATRICULA_UNIQUE` (`MATRICULA` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `4Ejercicio`.`CAMIONERO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `4Ejercicio`.`CAMIONERO` (
  `RFC` VARCHAR(9) NOT NULL,
  `POBLACIÓN` VARCHAR(45) NULL,
  `NOMBRE` VARCHAR(20) NULL,
  `TELEFONO` VARCHAR(9) NULL,
  `DIRECCION` VARCHAR(45) NULL,
  `SALARIO` FLOAT NULL,
  `CAMION_MATRICULA` VARCHAR(7) NOT NULL,
  PRIMARY KEY (`RFC`),
  UNIQUE INDEX `RFC_UNIQUE` (`RFC` ASC) VISIBLE,
  UNIQUE INDEX `TELEFONO_UNIQUE` (`TELEFONO` ASC) VISIBLE,
  INDEX `fk_CAMIONERO_CAMION_idx` (`CAMION_MATRICULA` ASC) VISIBLE,
  CONSTRAINT `fk_CAMIONERO_CAMION`
    FOREIGN KEY (`CAMION_MATRICULA`)
    REFERENCES `4Ejercicio`.`CAMION` (`MATRICULA`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `4Ejercicio`.`CIUDAD`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `4Ejercicio`.`CIUDAD` (
  `CODIGO` INT NOT NULL,
  `NOMBRE` VARCHAR(20) NULL,
  PRIMARY KEY (`CODIGO`),
  UNIQUE INDEX `CODIGO_UNIQUE` (`CODIGO` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `4Ejercicio`.`PAQUETE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `4Ejercicio`.`PAQUETE` (
  `CODIGO` INT NOT NULL,
  `DESCRIPCION` VARCHAR(150) NULL,
  `DESTINATARIO` VARCHAR(45) NULL,
  `DIRECCION` VARCHAR(45) NULL,
  `CIUDAD_CODIGO` INT NOT NULL,
  PRIMARY KEY (`CODIGO`),
  UNIQUE INDEX `CODIGO_UNIQUE` (`CODIGO` ASC) VISIBLE,
  INDEX `fk_PAQUETE_CIUDAD1_idx` (`CIUDAD_CODIGO` ASC) VISIBLE,
  CONSTRAINT `fk_PAQUETE_CIUDAD1`
    FOREIGN KEY (`CIUDAD_CODIGO`)
    REFERENCES `4Ejercicio`.`CIUDAD` (`CODIGO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `4Ejercicio`.`DISTRUBYE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `4Ejercicio`.`DISTRUBYE` (
  `CAMIONERO_RFC` VARCHAR(9) NOT NULL,
  `PAQUETE_CODIGO` INT NOT NULL,
  PRIMARY KEY (`CAMIONERO_RFC`, `PAQUETE_CODIGO`),
  INDEX `fk_CAMIONERO_has_PAQUETE_PAQUETE1_idx` (`PAQUETE_CODIGO` ASC) VISIBLE,
  INDEX `fk_CAMIONERO_has_PAQUETE_CAMIONERO1_idx` (`CAMIONERO_RFC` ASC) VISIBLE,
  CONSTRAINT `fk_CAMIONERO_has_PAQUETE_CAMIONERO1`
    FOREIGN KEY (`CAMIONERO_RFC`)
    REFERENCES `4Ejercicio`.`CAMIONERO` (`RFC`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_CAMIONERO_has_PAQUETE_PAQUETE1`
    FOREIGN KEY (`PAQUETE_CODIGO`)
    REFERENCES `4Ejercicio`.`PAQUETE` (`CODIGO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
