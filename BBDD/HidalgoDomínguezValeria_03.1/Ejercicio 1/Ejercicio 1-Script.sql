-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema 3Ejercicio
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema 3Ejercicio
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `3Ejercicio` DEFAULT CHARACTER SET utf8 ;
USE `3Ejercicio` ;

-- -----------------------------------------------------
-- Table `3Ejercicio`.`GUSTOS`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `3Ejercicio`.`GUSTOS` (
  `CODIGO GUSTOS` INT NOT NULL AUTO_INCREMENT,
  `ULTIMA ACTIVIDAD` VARCHAR(45) NULL,
  `TIPO` VARCHAR(45) NULL,
  `PAREJAS CON LA MISMA PREFERENCIA` INT NULL,
  PRIMARY KEY (`CODIGO GUSTOS`),
  UNIQUE INDEX `CODIGO GUSTOS_UNIQUE` (`CODIGO GUSTOS` ASC) INVISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `3Ejercicio`.`USUARIO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `3Ejercicio`.`USUARIO` (
  `CÓDIGO` VARCHAR(9) NOT NULL,
  `EMAIL` VARCHAR(45) NULL,
  `FOTO` VARCHAR(45) NULL,
  `NOMBRE` VARCHAR(20) NULL,
  `DIRECCIÓN` VARCHAR(45) NULL,
  `CIUDAD` VARCHAR(45) NULL,
  `PAÍS` VARCHAR(20) NULL,
  `SEXO` SET("MUJER", "HOMBRE", "OTRO") NULL,
  `ORIENTACION SEXUAL` SET("MUJER", "HOMBRE", "OTRO") NULL,
  `PASSWORD` VARCHAR(12) NULL,
  `GUSTOS_CODIGO GUSTOS` INT NOT NULL,
  PRIMARY KEY (`CÓDIGO`),
  UNIQUE INDEX `PASSWORD_UNIQUE` (`PASSWORD` ASC) VISIBLE,
  UNIQUE INDEX `EMAIL_UNIQUE` (`EMAIL` ASC) VISIBLE,
  INDEX `fk_USUARIO_GUSTOS_idx` (`GUSTOS_CODIGO GUSTOS` ASC) VISIBLE,
  CONSTRAINT `fk_USUARIO_GUSTOS`
    FOREIGN KEY (`GUSTOS_CODIGO GUSTOS`)
    REFERENCES `3Ejercicio`.`GUSTOS` (`CODIGO GUSTOS`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `3Ejercicio`.`CITAS`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `3Ejercicio`.`CITAS` (
  `CODIGO CITA` INT NOT NULL AUTO_INCREMENT,
  `QUIEN CITA` VARCHAR(20) NULL,
  `LUGAR` VARCHAR(45) NULL,
  `FRACASO` SET("SI", "NO") NULL,
  `HORA` DATE NULL,
  PRIMARY KEY (`CODIGO CITA`),
  UNIQUE INDEX `CODIGO CITA_UNIQUE` (`CODIGO CITA` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `3Ejercicio`.`REALIZA`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `3Ejercicio`.`REALIZA` (
  `USUARIO_CÓDIGO` VARCHAR(9) NOT NULL,
  `CITAS_CODIGO CITA` INT NOT NULL,
  PRIMARY KEY (`USUARIO_CÓDIGO`, `CITAS_CODIGO CITA`),
  INDEX `fk_USUARIO_has_CITAS_CITAS1_idx` (`CITAS_CODIGO CITA` ASC) VISIBLE,
  INDEX `fk_USUARIO_has_CITAS_USUARIO1_idx` (`USUARIO_CÓDIGO` ASC) VISIBLE,
  CONSTRAINT `fk_USUARIO_has_CITAS_USUARIO1`
    FOREIGN KEY (`USUARIO_CÓDIGO`)
    REFERENCES `3Ejercicio`.`USUARIO` (`CÓDIGO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_USUARIO_has_CITAS_CITAS1`
    FOREIGN KEY (`CITAS_CODIGO CITA`)
    REFERENCES `3Ejercicio`.`CITAS` (`CODIGO CITA`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
