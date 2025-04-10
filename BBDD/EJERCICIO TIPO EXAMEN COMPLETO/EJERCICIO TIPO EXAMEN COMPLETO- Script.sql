-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema EJERCICIO TIPO EXAMEN COMPLETO.
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema EJERCICIO TIPO EXAMEN COMPLETO.
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.` DEFAULT CHARACTER SET utf8 ;
USE `EJERCICIO TIPO EXAMEN COMPLETO.` ;

-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`ASIGNATURA`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`ASIGNATURA` (
  `idASIGNATURA` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`idASIGNATURA`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`PROFESOR`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`PROFESOR` (
  `DNI` VARCHAR(9) NOT NULL,
  `NOMBRE` VARCHAR(20) NULL,
  `TIPO DE VIA` ENUM('CALLE', 'TRAVESIA', 'AVDA') NULL,
  `NOMBRE DE CALLE` VARCHAR(100) NULL,
  `CORNIDADOR_DNI` VARCHAR(9) NULL,
  PRIMARY KEY (`DNI`),
  INDEX `fk_PROFESOR_PROFESOR1_idx` (`CORNIDADOR_DNI` ASC) VISIBLE,
  CONSTRAINT `fk_PROFESOR_PROFESOR1`
    FOREIGN KEY (`CORNIDADOR_DNI`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`PROFESOR` (`DNI`)
    ON DELETE SET NULL
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`TELEFONO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`TELEFONO` (
  `idTELEFONO` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `NUMERO` INT(9) NULL,
  `PROFESOR_DNI` VARCHAR(9) NOT NULL,
  PRIMARY KEY (`idTELEFONO`),
  INDEX `fk_TELEFONO_PROFESOR1_idx` (`PROFESOR_DNI` ASC) VISIBLE,
  CONSTRAINT `fk_TELEFONO_PROFESOR1`
    FOREIGN KEY (`PROFESOR_DNI`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`PROFESOR` (`DNI`)
    ON DELETE NO ACTION
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`EXAMEN`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`EXAMEN` (
  `idEXAMEN` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `DESCRIPCIÓN` TEXT NULL,
  `TIPO` ENUM('PRACTICO', 'TEORICO') NOT NULL,
  PRIMARY KEY (`idEXAMEN`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`PREGUNTAS`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`PREGUNTAS` (
  `idPREGUNTAS` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `DESCRIPCION` TEXT NULL,
  `EXAMEN_idEXAMEN` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idPREGUNTAS`, `EXAMEN_idEXAMEN`),
  INDEX `fk_PREGUNTAS_EXAMEN1_idx` (`EXAMEN_idEXAMEN` ASC) VISIBLE,
  CONSTRAINT `fk_PREGUNTAS_EXAMEN1`
    FOREIGN KEY (`EXAMEN_idEXAMEN`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`EXAMEN` (`idEXAMEN`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`NORMAS`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`NORMAS` (
  `idNORMAS` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `ENUNCIADO_NORAMS` VARCHAR(45) NOT NULL,
  `EXAMEN_idEXAMEN` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idNORMAS`),
  INDEX `fk_NORMAS_EXAMEN1_idx` (`EXAMEN_idEXAMEN` ASC) VISIBLE,
  CONSTRAINT `fk_NORMAS_EXAMEN1`
    FOREIGN KEY (`EXAMEN_idEXAMEN`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`EXAMEN` (`idEXAMEN`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`IMPARTE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`IMPARTE` (
  `ASIGNATURA_idASIGNATURA` INT UNSIGNED NOT NULL,
  `PROFESOR_DNI` VARCHAR(9) NOT NULL,
  `AÑO` DATE NULL,
  PRIMARY KEY (`ASIGNATURA_idASIGNATURA`, `PROFESOR_DNI`),
  INDEX `fk_ASIGNATURA_has_PROFESOR_PROFESOR1_idx` (`PROFESOR_DNI` ASC) VISIBLE,
  INDEX `fk_ASIGNATURA_has_PROFESOR_ASIGNATURA_idx` (`ASIGNATURA_idASIGNATURA` ASC) VISIBLE,
  CONSTRAINT `fk_ASIGNATURA_has_PROFESOR_ASIGNATURA`
    FOREIGN KEY (`ASIGNATURA_idASIGNATURA`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`ASIGNATURA` (`idASIGNATURA`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  CONSTRAINT `fk_ASIGNATURA_has_PROFESOR_PROFESOR1`
    FOREIGN KEY (`PROFESOR_DNI`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`PROFESOR` (`DNI`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `EJERCICIO TIPO EXAMEN COMPLETO.`.`CREA`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `EJERCICIO TIPO EXAMEN COMPLETO.`.`CREA` (
  `ASIGNATURA_idASIGNATURA` INT UNSIGNED NULL,
  `EXAMEN_idEXAMEN` INT UNSIGNED NOT NULL,
  `PROFESOR_DNI` VARCHAR(9) NOT NULL,
  PRIMARY KEY (`ASIGNATURA_idASIGNATURA`, `EXAMEN_idEXAMEN`),
  INDEX `fk_ASIGNATURA_has_EXAMEN_EXAMEN1_idx` (`EXAMEN_idEXAMEN` ASC) VISIBLE,
  INDEX `fk_ASIGNATURA_has_EXAMEN_ASIGNATURA1_idx` (`ASIGNATURA_idASIGNATURA` ASC) VISIBLE,
  INDEX `fk_ASIGNATURA_has_EXAMEN_PROFESOR1_idx` (`PROFESOR_DNI` ASC) VISIBLE,
  CONSTRAINT `fk_ASIGNATURA_has_EXAMEN_ASIGNATURA1`
    FOREIGN KEY (`ASIGNATURA_idASIGNATURA`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`ASIGNATURA` (`idASIGNATURA`)
    ON DELETE SET NULL
    ON UPDATE CASCADE,
  CONSTRAINT `fk_ASIGNATURA_has_EXAMEN_EXAMEN1`
    FOREIGN KEY (`EXAMEN_idEXAMEN`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`EXAMEN` (`idEXAMEN`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  CONSTRAINT `fk_ASIGNATURA_has_EXAMEN_PROFESOR1`
    FOREIGN KEY (`PROFESOR_DNI`)
    REFERENCES `EJERCICIO TIPO EXAMEN COMPLETO.`.`PROFESOR` (`DNI`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
