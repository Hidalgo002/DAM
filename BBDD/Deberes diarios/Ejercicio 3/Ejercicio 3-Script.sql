-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema 5Ejercicio
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema 5Ejercicio
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `5Ejercicio` DEFAULT CHARACTER SET utf8 ;
USE `5Ejercicio` ;

-- -----------------------------------------------------
-- Table `5Ejercicio`.`CLIENTE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `5Ejercicio`.`CLIENTE` (
  `RFC` INT NOT NULL,
  `NOMBRE` VARCHAR(20) NULL,
  `APELLIDO` VARCHAR(20) NULL,
  `F.N.` DATE NULL,
  `TELEFONO` VARCHAR(9) NULL,
  PRIMARY KEY (`RFC`),
  UNIQUE INDEX `TELEFONO_UNIQUE` (`TELEFONO` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `5Ejercicio`.`PROVEEDORES`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `5Ejercicio`.`PROVEEDORES` (
  `RFC` INT NOT NULL,
  `NOMBRE` VARCHAR(20) NULL,
  `DIRECCION` VARCHAR(45) NULL,
  PRIMARY KEY (`RFC`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `5Ejercicio`.`PRODUCTO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `5Ejercicio`.`PRODUCTO` (
  `CODIGO` VARCHAR(10) NOT NULL,
  `NOMBRE` VARCHAR(20) NULL,
  `PRECIO` FLOAT NULL,
  PRIMARY KEY (`CODIGO`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `5Ejercicio`.`COMPRA`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `5Ejercicio`.`COMPRA` (
  `CLIENTE_RFC` INT NOT NULL,
  `PRODUCTO_CODIGO` VARCHAR(10) NOT NULL,
  PRIMARY KEY (`CLIENTE_RFC`, `PRODUCTO_CODIGO`),
  INDEX `fk_CLIENTE_has_PRODUCTO_PRODUCTO1_idx` (`PRODUCTO_CODIGO` ASC) VISIBLE,
  INDEX `fk_CLIENTE_has_PRODUCTO_CLIENTE_idx` (`CLIENTE_RFC` ASC) VISIBLE,
  CONSTRAINT `fk_CLIENTE_has_PRODUCTO_CLIENTE`
    FOREIGN KEY (`CLIENTE_RFC`)
    REFERENCES `5Ejercicio`.`CLIENTE` (`RFC`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_CLIENTE_has_PRODUCTO_PRODUCTO1`
    FOREIGN KEY (`PRODUCTO_CODIGO`)
    REFERENCES `5Ejercicio`.`PRODUCTO` (`CODIGO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `5Ejercicio`.`SUMINISTRA`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `5Ejercicio`.`SUMINISTRA` (
  `PROVEEDORES_RFC` INT NOT NULL,
  `PRODUCTO_CODIGO` VARCHAR(10) NOT NULL,
  PRIMARY KEY (`PROVEEDORES_RFC`, `PRODUCTO_CODIGO`),
  INDEX `fk_PROVEEDORES_has_PRODUCTO_PRODUCTO1_idx` (`PRODUCTO_CODIGO` ASC) VISIBLE,
  INDEX `fk_PROVEEDORES_has_PRODUCTO_PROVEEDORES1_idx` (`PROVEEDORES_RFC` ASC) VISIBLE,
  CONSTRAINT `fk_PROVEEDORES_has_PRODUCTO_PROVEEDORES1`
    FOREIGN KEY (`PROVEEDORES_RFC`)
    REFERENCES `5Ejercicio`.`PROVEEDORES` (`RFC`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_PROVEEDORES_has_PRODUCTO_PRODUCTO1`
    FOREIGN KEY (`PRODUCTO_CODIGO`)
    REFERENCES `5Ejercicio`.`PRODUCTO` (`CODIGO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
