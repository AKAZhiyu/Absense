CREATE DATABASE tt;
USE tt;

CREATE TABLE Students(
    id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(100),
    gender VARCHAR(10),
    password VARCHAR(100),
    major VARCHAR(100),
    class VARCHAR(100),
    age INT,
    PRIMARY KEY (id)
);

CREATE TABLE Teachers(
    id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(100),
    gender VARCHAR(10),
    password VARCHAR(100),
    college VARCHAR(100),
    title VARCHAR(100),
    age INT,
    PRIMARY KEY (id)
);

CREATE TABLE Courses(
    id INT NOT NULL AUTO_INCREMENT,
    course_name VARCHAR(100),
    credits INT,
    PRIMARY KEY (id)
);

CREATE TABLE Teaching (
    teacher_id INT,
    course_id INT,
    class_time VARCHAR(50),
    location VARCHAR(100),
    FOREIGN KEY (teacher_id) REFERENCES Teachers(id),
    FOREIGN KEY (course_id) REFERENCES Courses(id),
    PRIMARY KEY (teacher_id, course_id)
);

INSERT INTO Students (name, gender, password, major, class, age) VALUES
('张三', '男', 'password123', '计算机科学', '计算机一班', 20),
('李四', '男', 'password123', '物理学', '物理一班', 21),
('王五', '女', 'password123', '化学', '化学一班', 20),
('赵六', '男', 'password123', '生物学', '生物一班', 22),
('孙七', '女', 'password123', '数学', '数学一班', 19);

INSERT INTO Students (id, name, gender, password, major, class, age) VALUES
(10001, '张三', '男', 'password', '计算机科学', '计算机一班', 20);

INSERT INTO Teachers (name, gender, password, college, title, age) VALUES
('钱一', '男', 'password123', '计算机学院', '副教授', 45),
('周二', '男', 'password123', '物理学院', '讲师', 40),
('吴三', '女', 'password123', '化学学院', '教授', 50),
('郑四', '男', 'password123', '生物学院', '助教', 35),
('王五', '女', 'password123', '数学学院', '副教授', 42);


INSERT INTO Courses (course_name, credits) VALUES
('计算机科学基础', 3),
('物理学基础', 2),
('有机化学', 4),
('微生物学', 3),
('高等数学', 5);

INSERT INTO Teaching (teacher_id, course_id, class_time, location) VALUES
(1, 1, '周一 9:00-11:00', '教学楼A101'),
(2, 2, '周二 13:00-15:00', '教学楼A102'),
(3, 3, '周三 9:00-11:00', '实验楼B201'),
(4, 4, '周四 13:00-15:00', '实验楼B202'),
(5, 5, '周五 9:00-11:00', '教学楼A103');

CREATE TABLE CourseSelection (
    student_id INT,
    course_id INT,
    selection_date DATE,
    FOREIGN KEY (student_id) REFERENCES Students(id),
    FOREIGN KEY (course_id) REFERENCES Courses(id),
    PRIMARY KEY (student_id, course_id)
);
INSERT INTO CourseSelection (student_id, course_id, selection_date) VALUES
(1, 1, '2023-06-25'),
(1, 2, '2023-06-24'),
(2, 1, '2023-06-25'),
(2, 2, '2023-06-24'),
(3, 1, '2023-06-25'),
(3, 2, '2023-06-24'),
(4, 1, '2023-06-25'),
(4, 2, '2023-06-24'),
(5, 1, '2023-06-25'),
(5, 2, '2023-06-24'),
(10001, 2, '2023-06-23'),
(10001, 3, '2023-06-23'),
(10001, 4, '2023-06-23'),
(10001, 1, '2023-06-23');


CREATE TABLE Absences (
    absence_id INT NOT NULL AUTO_INCREMENT,
    student_id INT,
    course_id INT,
    absence_date DATE,
    type ENUM('Sick', 'Leave', 'Unexcused'),
    FOREIGN KEY (student_id, course_id) REFERENCES CourseSelection(student_id, course_id),
    PRIMARY KEY (absence_id)
);
ALTER TABLE Absences
CHANGE type type ENUM('Sick', 'Leave', 'Unexcused', 'Late', 'Early Leave');


INSERT INTO Absences (student_id, course_id, absence_date, type) VALUES
(1, 1, '2023-06-25', 'Sick'),
(2, 2, '2023-06-24', 'Leave'),
(10001, 1, '2023-06-24', 'Leave'),
(10001, 2, '2023-06-24', 'Leave'),
(10001, 3, '2023-06-24', 'Leave'),
(10001, 4, '2023-06-24', 'Leave'),
(3, 1, '2023-06-23', 'Unexcused');


CREATE VIEW DetailedAbsences AS
SELECT  a.student_id,
        c.id AS course_id,
        c.course_name,
        a.absence_date,
        t.class_time,
        a.type
FROM Absences AS a
JOIN Courses AS c ON a.course_id = c.id
JOIN teaching AS t ON t.course_id = c.id;

CREATE VIEW StudentCourseView AS
SELECT s.id AS student_id, s.name AS student_name, s.major AS student_major,
       c.id AS course_id, c.course_name, cs.selection_date
FROM Students AS s
JOIN CourseSelection AS cs ON s.id = cs.student_id
JOIN Courses AS c ON cs.course_id = c.id;


update students set password = "password" where id = 10001;

INSERT INTO Absences (student_id, course_id, absence_date, type) VALUES
(10001, 1, '2023-06-01', 'Unexcused'),
(10001, 2, '2023-06-02', 'Unexcused'),
(10001, 3, '2023-06-03', 'Sick'),
(10001, 4, '2023-06-20', 'Sick');

INSERT INTO Absences (student_id, course_id, absence_date, type) VALUES
(10001, 2, '2023-06-11', 'Late'),
(10001, 2, '2023-06-12', 'Early Leave'),
(10001, 2, '2023-06-13', 'Late'),
(10001, 3, '2023-06-10', 'Late');
