-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema 6Ejercicio
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema 6Ejercicio
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `6Ejercicio` DEFAULT CHARACTER SET utf8 ;
USE `6Ejercicio` ;

-- -----------------------------------------------------
-- Table `6Ejercicio`.`MODULO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`MODULO` (
  `idMODULO` INT NOT NULL,
  PRIMARY KEY (`idMODULO`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`PROFESOR`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`PROFESOR` (
  `DNI` VARCHAR(9) NOT NULL,
  `NOMBRE` VARCHAR(20) NULL,
  `DIRECCION` VARCHAR(45) NULL,
  `TELEFONO*` VARCHAR(9) NULL,
  `MODULO_idMODULO` INT NOT NULL,
  PRIMARY KEY (`DNI`),
  UNIQUE INDEX `DNI_UNIQUE` (`DNI` ASC) VISIBLE,
  INDEX `fk_PROFESOR_MODULO_idx` (`MODULO_idMODULO` ASC) VISIBLE,
  CONSTRAINT `fk_PROFESOR_MODULO`
    FOREIGN KEY (`MODULO_idMODULO`)
    REFERENCES `6Ejercicio`.`MODULO` (`idMODULO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`ALUMNO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`ALUMNO` (
  `EXPEDIENTE` INT NOT NULL,
  `APELLIDOS` VARCHAR(45) NULL,
  `FECHA_NACIMIENTO` DATE NULL,
  PRIMARY KEY (`EXPEDIENTE`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`DELEGADO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`DELEGADO` (
  `idDELEGADO` INT NOT NULL,
  `ALUMNO_EXPEDIENTE` INT NOT NULL,
  PRIMARY KEY (`idDELEGADO`),
  INDEX `fk_DELEGADO_ALUMNO1_idx` (`ALUMNO_EXPEDIENTE` ASC) VISIBLE,
  CONSTRAINT `fk_DELEGADO_ALUMNO1`
    FOREIGN KEY (`ALUMNO_EXPEDIENTE`)
    REFERENCES `6Ejercicio`.`ALUMNO` (`EXPEDIENTE`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`MODULO_has_ALUMNO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`MODULO_has_ALUMNO` (
  `MODULO_idMODULO` INT NOT NULL,
  `ALUMNO_EXPEDIENTE` INT NOT NULL,
  PRIMARY KEY (`MODULO_idMODULO`, `ALUMNO_EXPEDIENTE`),
  INDEX `fk_MODULO_has_ALUMNO_ALUMNO1_idx` (`ALUMNO_EXPEDIENTE` ASC) VISIBLE,
  INDEX `fk_MODULO_has_ALUMNO_MODULO1_idx` (`MODULO_idMODULO` ASC) VISIBLE,
  CONSTRAINT `fk_MODULO_has_ALUMNO_MODULO1`
    FOREIGN KEY (`MODULO_idMODULO`)
    REFERENCES `6Ejercicio`.`MODULO` (`idMODULO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_MODULO_has_ALUMNO_ALUMNO1`
    FOREIGN KEY (`ALUMNO_EXPEDIENTE`)
    REFERENCES `6Ejercicio`.`ALUMNO` (`EXPEDIENTE`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
