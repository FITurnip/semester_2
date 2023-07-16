/*
 Navicat Premium Data Transfer

 Source Server         : koneksi01
 Source Server Type    : MySQL
 Source Server Version : 100427
 Source Host           : localhost:3306
 Source Schema         : db_ujicoba

 Target Server Type    : MySQL
 Target Server Version : 100427
 File Encoding         : 65001

 Date: 20/03/2023 18:33:38
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for t_departments
-- ----------------------------
DROP TABLE IF EXISTS `t_departments`;
CREATE TABLE `t_departments`  (
  `dept_id` int(6) NOT NULL AUTO_INCREMENT,
  `dept_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `dept_head` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`dept_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 9 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_departments
-- ----------------------------
INSERT INTO `t_departments` VALUES (2, 'Content', 'Eduardo');
INSERT INTO `t_departments` VALUES (3, 'Engineering', 'Maggie');
INSERT INTO `t_departments` VALUES (4, 'IT', 'Richard');
INSERT INTO `t_departments` VALUES (5, 'Finance', 'Lily');
INSERT INTO `t_departments` VALUES (6, 'HRD', 'John');
INSERT INTO `t_departments` VALUES (7, 'LAW', 'Budi');
INSERT INTO `t_departments` VALUES (8, 'Production', 'Umar');

-- ----------------------------
-- Table structure for t_employees
-- ----------------------------
DROP TABLE IF EXISTS `t_employees`;
CREATE TABLE `t_employees`  (
  `employee_id` int(6) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `dept_id` int(6) NULL DEFAULT NULL,
  `job_level_id` int(6) NULL DEFAULT NULL,
  `year_hired` varchar(4) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`employee_id`) USING BTREE,
  INDEX `fk_nabila`(`dept_id`) USING BTREE,
  INDEX `fk_job`(`job_level_id`) USING BTREE,
  CONSTRAINT `fk_job` FOREIGN KEY (`job_level_id`) REFERENCES `t_job_levels` (`job_level_id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `fk_nabila` FOREIGN KEY (`dept_id`) REFERENCES `t_departments` (`dept_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = InnoDB AUTO_INCREMENT = 39 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_employees
-- ----------------------------
INSERT INTO `t_employees` VALUES (33, 'Qiqi Ceupan', 8, 4, '2025');
INSERT INTO `t_employees` VALUES (35, 'Komar', 5, 5, '2030');
INSERT INTO `t_employees` VALUES (36, 'Mayones', 2, 5, '2000');
INSERT INTO `t_employees` VALUES (38, 'Wira', 2, 5, '2000');

-- ----------------------------
-- Table structure for t_job_levels
-- ----------------------------
DROP TABLE IF EXISTS `t_job_levels`;
CREATE TABLE `t_job_levels`  (
  `job_level_id` int(6) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `min_salary` decimal(10, 2) NULL DEFAULT NULL,
  `max_salary` decimal(10, 2) NULL DEFAULT NULL,
  PRIMARY KEY (`job_level_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_job_levels
-- ----------------------------
INSERT INTO `t_job_levels` VALUES (1, 'Executive', 100000.00, 170000.00);
INSERT INTO `t_job_levels` VALUES (2, 'Manager', 70000.00, 110000.00);
INSERT INTO `t_job_levels` VALUES (3, 'Contributor', 35000.00, 80000.00);
INSERT INTO `t_job_levels` VALUES (4, 'Staff', 25000.00, 35000.00);
INSERT INTO `t_job_levels` VALUES (5, 'Clerk', 15000.00, 20000.00);
INSERT INTO `t_job_levels` VALUES (6, 'Support', 20000.00, 25000.00);

SET FOREIGN_KEY_CHECKS = 1;
