-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: May 17, 2015 at 09:30 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `drupal_colony`
--

-- --------------------------------------------------------

--
-- Table structure for table `chars`
--

CREATE TABLE IF NOT EXISTS `chars` (
  `id` int(8) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  `familyid` int(8) NOT NULL,
  `creator` int(8) NOT NULL,
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `char_demographic`
--

CREATE TABLE IF NOT EXISTS `char_demographic` (
  `cid` int(11) NOT NULL,
  `gender` char(1) NOT NULL,
  `ethnicities` varchar(32) NOT NULL,
  KEY `cid` (`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `char_dem_ethnicity`
--

CREATE TABLE IF NOT EXISTS `char_dem_ethnicity` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(16) NOT NULL,
  `subrace` varchar(16) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `char_dem_ethnicity`
--

INSERT INTO `char_dem_ethnicity` (`id`, `name`, `subrace`) VALUES
(1, 'Germanic', '1'),
(2, 'Brittonic', '1'),
(3, 'Slavic', '1'),
(4, 'Iberian', '1'),
(5, 'Iranian', '1'),
(6, 'Jewish', '2'),
(7, 'Arabic', '2'),
(8, 'Ethiopian', '2'),
(9, 'Coptic', '3');

-- --------------------------------------------------------

--
-- Table structure for table `char_dem_race`
--

CREATE TABLE IF NOT EXISTS `char_dem_race` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(16) NOT NULL,
  `species` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `char_dem_race`
--

INSERT INTO `char_dem_race` (`id`, `name`, `species`) VALUES
(1, 'Caucasoid', 1),
(2, 'Mongoloid', 1),
(3, 'Negroid', 1);

-- --------------------------------------------------------

--
-- Table structure for table `char_dem_species`
--

CREATE TABLE IF NOT EXISTS `char_dem_species` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `name` varchar(16) NOT NULL,
  `sentience` varchar(16) NOT NULL DEFAULT 'SAPIENS',
  `body` varchar(16) NOT NULL DEFAULT 'HUMANOID',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `char_dem_species`
--

INSERT INTO `char_dem_species` (`id`, `name`, `sentience`, `body`) VALUES
(1, 'human', 'SAPIENS', 'HUMANOID'),
(2, 'elf', 'SAPIENS', 'HUMANOID'),
(3, 'dog', 'CANIS', 'BEAST');

-- --------------------------------------------------------

--
-- Table structure for table `char_dem_subrace`
--

CREATE TABLE IF NOT EXISTS `char_dem_subrace` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `name` varchar(16) NOT NULL,
  `race` int(6) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=14 ;

--
-- Dumping data for table `char_dem_subrace`
--

INSERT INTO `char_dem_subrace` (`id`, `name`, `race`) VALUES
(1, 'Aryan', 1),
(2, 'Semitic', 1),
(3, 'Hamitic', 1),
(4, 'Mongol', 2),
(5, 'Han', 2),
(6, 'Yamato', 2),
(7, 'Amerindian', 2),
(8, 'Eskaleut', 2),
(9, 'Maori', 2),
(10, 'Bantu', 3),
(11, 'Berber', 3),
(12, 'Khoisan', 3),
(13, 'Austroneisian', 3);

-- --------------------------------------------------------

--
-- Table structure for table `char_families`
--

CREATE TABLE IF NOT EXISTS `char_families` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(16) NOT NULL,
  `color` varchar(6) NOT NULL DEFAULT '',
  `creator` int(8) NOT NULL,
  `created` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`),
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `char_permissions`
--

CREATE TABLE IF NOT EXISTS `char_permissions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `cid` int(8) NOT NULL,
  `userid` int(8) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
