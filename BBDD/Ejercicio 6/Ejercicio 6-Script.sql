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
-- Table `6Ejercicio`.`HARDWARE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`HARDWARE` (
  `idHARDWARE` INT UNSIGNED NOT NULL,
  `TIPO` VARCHAR(20) NULL,
  `BIEN_NACIONAL` TINYINT(10) NULL,
  PRIMARY KEY (`idHARDWARE`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`CARACTERISITCAS_HARDWARE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`CARACTERISITCAS_HARDWARE` (
  `idCARACTERISITCAS_H` INT UNSIGNED NOT NULL,
  `MARCA` ENUM('ENIVIDIA', 'AMD', 'HP') NULL,
  `SERIAL` VARCHAR(17) NULL,
  `MODELO` VARCHAR(20) NULL,
  `OBSERVACIONES` TEXT(50) NULL,
  PRIMARY KEY (`idCARACTERISITCAS_H`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`SOFTWARE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`SOFTWARE` (
  `idSOFTWARE` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `TIPO` ENUM('SO', 'PROGRAMA') NULL,
  PRIMARY KEY (`idSOFTWARE`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`CARACTERISTICAS_SOFTWARE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`CARACTERISTICAS_SOFTWARE` (
  `idCARACTERISTICAS_S` INT UNSIGNED NOT NULL,
  `LICENCIA` VARCHAR(20) NULL,
  `VERSION` TINYINT NULL,
  `OTROS` VARCHAR(45) NULL,
  `OBSERVACIONES` TEXT NULL,
  PRIMARY KEY (`idCARACTERISTICAS_S`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`EQUIPO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`EQUIPO` (
  `CODIGO_EQUIPO` INT UNSIGNED NOT NULL,
  `RESPONABLE` VARCHAR(45) NULL,
  `UBICACIÓN` ENUM('INFO1', 'INFO2', 'INFO3') NULL,
  PRIMARY KEY (`CODIGO_EQUIPO`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`USUARIO`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`USUARIO` (
  `idUSUARIO` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `TIPO` SET("ADMIN", "USUARIO") NULL,
  `CEDULA` VARCHAR(45) NULL,
  `EMAIL` VARCHAR(320) NULL,
  `NOMBRE` VARCHAR(15) NULL,
  `APELLIDOS` VARCHAR(30) NULL,
  `PASSWORD` VARCHAR(10) NULL,
  PRIMARY KEY (`idUSUARIO`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`HISTORIAL`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`HISTORIAL` (
  `idHISTORIAL` INT NOT NULL,
  `FECHA_ENTRADA` DATE NULL,
  `FECHA_SALIDA` DATE NULL,
  `OBSERVACIONES` TEXT(50) NULL,
  `STATUS` ENUM('EN_PROCESO', 'PARADO') NULL,
  `EQUIPO_CODIGO_EQUIPO` INT NOT NULL,
  PRIMARY KEY (`idHISTORIAL`),
  INDEX `fk_HISTORIAL_EQUIPO_idx` (`EQUIPO_CODIGO_EQUIPO` ASC) VISIBLE,
  CONSTRAINT `fk_HISTORIAL_EQUIPO`
    FOREIGN KEY (`EQUIPO_CODIGO_EQUIPO`)
    REFERENCES `6Ejercicio`.`EQUIPO` (`CODIGO_EQUIPO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`INTERVIENE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`INTERVIENE` (
  `USUARIO_idUSUARIO` INT UNSIGNED NOT NULL,
  `EQUIPO_CODIGO_EQUIPO` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`USUARIO_idUSUARIO`, `EQUIPO_CODIGO_EQUIPO`),
  INDEX `fk_USUARIO_has_EQUIPO_EQUIPO1_idx` (`EQUIPO_CODIGO_EQUIPO` ASC) VISIBLE,
  INDEX `fk_USUARIO_has_EQUIPO_USUARIO1_idx` (`USUARIO_idUSUARIO` ASC) VISIBLE,
  CONSTRAINT `fk_USUARIO_has_EQUIPO_USUARIO1`
    FOREIGN KEY (`USUARIO_idUSUARIO`)
    REFERENCES `6Ejercicio`.`USUARIO` (`idUSUARIO`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  CONSTRAINT `fk_USUARIO_has_EQUIPO_EQUIPO1`
    FOREIGN KEY (`EQUIPO_CODIGO_EQUIPO`)
    REFERENCES `6Ejercicio`.`EQUIPO` (`CODIGO_EQUIPO`)
    ON DELETE RESTRICT
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`POSEE_SW`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`POSEE_SW` (
  `EQUIPO_CODIGO_EQUIPO` INT UNSIGNED NOT NULL,
  `CARACTERISTICAS_SOFTWARE_idCARACTERISTICAS_S` INT UNSIGNED NOT NULL,
  `SOFTWARE_idSOFTWARE` INT NULL,
  PRIMARY KEY (`EQUIPO_CODIGO_EQUIPO`, `CARACTERISTICAS_SOFTWARE_idCARACTERISTICAS_S`),
  INDEX `fk_EQUIPO_has_CARACTERISTICAS_SOFTWARE_CARACTERISTICAS_SOFT_idx` (`CARACTERISTICAS_SOFTWARE_idCARACTERISTICAS_S` ASC) VISIBLE,
  INDEX `fk_EQUIPO_has_CARACTERISTICAS_SOFTWARE_EQUIPO1_idx` (`EQUIPO_CODIGO_EQUIPO` ASC) VISIBLE,
  INDEX `fk_POSEE_SW_SOFTWARE1_idx` (`SOFTWARE_idSOFTWARE` ASC) VISIBLE,
  CONSTRAINT `fk_EQUIPO_has_CARACTERISTICAS_SOFTWARE_EQUIPO1`
    FOREIGN KEY (`EQUIPO_CODIGO_EQUIPO`)
    REFERENCES `6Ejercicio`.`EQUIPO` (`CODIGO_EQUIPO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_EQUIPO_has_CARACTERISTICAS_SOFTWARE_CARACTERISTICAS_SOFTWA1`
    FOREIGN KEY (`CARACTERISTICAS_SOFTWARE_idCARACTERISTICAS_S`)
    REFERENCES `6Ejercicio`.`CARACTERISTICAS_SOFTWARE` (`idCARACTERISTICAS_S`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_POSEE_SW_SOFTWARE1`
    FOREIGN KEY (`SOFTWARE_idSOFTWARE`)
    REFERENCES `6Ejercicio`.`SOFTWARE` (`idSOFTWARE`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `6Ejercicio`.`POSEE_HW`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `6Ejercicio`.`POSEE_HW` (
  `HARDWARE_idHARDWARE` INT UNSIGNED NULL,
  `CARACTERISITCAS_HARDWARE_idCARACTERISITCAS_H` INT UNSIGNED NOT NULL,
  `INTERVIENE_USUARIO_idUSUARIO` INT UNSIGNED NOT NULL,
  `INTERVIENE_EQUIPO_CODIGO_EQUIPO` INT NOT NULL,
  PRIMARY KEY (`CARACTERISITCAS_HARDWARE_idCARACTERISITCAS_H`, `INTERVIENE_USUARIO_idUSUARIO`, `INTERVIENE_EQUIPO_CODIGO_EQUIPO`),
  INDEX `fk_HARDWARE_has_CARACTERISITCAS_HARDWARE_CARACTERISITCAS_HA_idx` (`CARACTERISITCAS_HARDWARE_idCARACTERISITCAS_H` ASC) VISIBLE,
  INDEX `fk_HARDWARE_has_CARACTERISITCAS_HARDWARE_HARDWARE1_idx` (`HARDWARE_idHARDWARE` ASC) VISIBLE,
  INDEX `fk_HARDWARE_has_CARACTERISITCAS_HARDWARE_INTERVIENE1_idx` (`INTERVIENE_USUARIO_idUSUARIO` ASC, `INTERVIENE_EQUIPO_CODIGO_EQUIPO` ASC) VISIBLE,
  CONSTRAINT `fk_HARDWARE_has_CARACTERISITCAS_HARDWARE_HARDWARE1`
    FOREIGN KEY (`HARDWARE_idHARDWARE`)
    REFERENCES `6Ejercicio`.`HARDWARE` (`idHARDWARE`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_HARDWARE_has_CARACTERISITCAS_HARDWARE_CARACTERISITCAS_HARD1`
    FOREIGN KEY (`CARACTERISITCAS_HARDWARE_idCARACTERISITCAS_H`)
    REFERENCES `6Ejercicio`.`CARACTERISITCAS_HARDWARE` (`idCARACTERISITCAS_H`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_HARDWARE_has_CARACTERISITCAS_HARDWARE_INTERVIENE1`
    FOREIGN KEY (`INTERVIENE_USUARIO_idUSUARIO` , `INTERVIENE_EQUIPO_CODIGO_EQUIPO`)
    REFERENCES `6Ejercicio`.`INTERVIENE` (`USUARIO_idUSUARIO` , `EQUIPO_CODIGO_EQUIPO`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
