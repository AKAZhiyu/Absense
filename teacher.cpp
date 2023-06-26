#include "teacher.h"
#include "ui_teacher.h"
#include"pass.h"
#include <QMessageBox>
Teacher::Teacher(Tea* teacher, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teacher),
    teacher(teacher)
{
    ui->setupUi(this);
    ui->searchEdit->hide();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("SchoolDB");
    db.setUserName("root");
    db.setPassword("zzx20030628");
    m = new QSqlTableModel;
    model = new QSqlQueryModel;

    if (!db.open()) {
        // 错误处理
        QMessageBox::warning(this, "Login", "数据库连接错误！");
        this->close();
    }
    QString welcome = "您好，" + QString::fromStdString(teacher->getName()) + "老师";
    ui->label_welcome->setText(welcome);
    ui->label_name->setText(QString::fromStdString(teacher->getName()));
    ui->label_gender->setText(QString::fromStdString(teacher->getGender()));
    ui->label_position->setText(QString::fromStdString(teacher->getPosition()));
    ui->label_college->setText(QString::fromStdString(teacher->getFaculty()));
    ui->label_id->setText(QString::number(teacher->getId()));
    ui->label_age->setText(QString::number(teacher->getAge()));


}

Teacher::~Teacher()
{
    delete ui;
}

void Teacher::on_exitButton_clicked()
{
    this->close();
    emit notifyParent();
}


void Teacher::on_pushButton_pass_clicked()
{
    pass* passs = new pass(teacher);
    passs->show();
}

void Teacher::printMyCourse()
{
    QSqlQuery query;
    query.prepare("SELECT Courses.* FROM Teaching INNER JOIN Courses ON Teaching.course_id = Courses.id WHERE Teaching.teacher_id = ?");
    query.addBindValue(teacher->getId());
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);

}

void Teacher::printAllCourse()
{
    m->setTable("Courses");
    ui->tableView->setModel(m);
    m->select();
}

void Teacher::printAllStudent()
{
    m->setTable("Students");
    ui->tableView->setModel(m);
    m->select();
}

void Teacher::printAllAbsense()
{
    m->setTable("DetailedAbsences");
    ui->tableView->setModel(m);
    m->select();
}

void Teacher::printAllMyStudent()
{
    QSqlQuery query;
    query.prepare("SELECT DISTINCT Students.id, Students.name "
                  "FROM Teaching "
                  "JOIN CourseSelection ON Teaching.course_id = CourseSelection.course_id "
                  "JOIN Students ON CourseSelection.student_id = Students.id "
                  "WHERE Teaching.teacher_id = ?");
    query.addBindValue(teacher->getId());
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

void Teacher::printAllMyStudentAbsence()
{
    QSqlQuery query;
    query.prepare("SELECT Students.id, Students.name, Absences.absence_date, Absences.type "
                  "FROM Teaching "
                  "JOIN CourseSelection ON Teaching.course_id = CourseSelection.course_id "
                  "JOIN Students ON CourseSelection.student_id = Students.id "
                  "JOIN Absences ON Absences.student_id = Students.id AND Absences.course_id = CourseSelection.course_id "
                  "WHERE Teaching.teacher_id = :teacher_id");
    query.bindValue(":teacher_id", teacher->getId());
    query.exec();
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

void Teacher::searchCourseByName(QString name)
{
    QSqlQuery query;
    QString pattern = "%" + name + "%";

    query.prepare("SELECT Courses.* "
                  "FROM Courses "
                  "WHERE  Courses.course_name LIKE :pattern");
    query.bindValue(":pattern", pattern);

    query.exec();
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

void Teacher::searchStudentByName(const QString &name)
{

    QSqlQuery query;
    QString pattern = "%" + name + "%";

    query.prepare("SELECT Students.* "
                  "FROM Students "
                  "WHERE  Students.name LIKE :pattern");
    query.bindValue(":pattern", pattern);

    query.exec();
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

void Teacher::searchCourseById(const QString &id)
{
    QSqlQuery query;
    QString pattern = "%" + id + "%";

    query.prepare("SELECT Courses.* "
                  "FROM Courses "
                  "WHERE  Courses.id LIKE :pattern");
    query.bindValue(":pattern", pattern);

    query.exec();
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

void Teacher::searchStudentById(const QString &id)
{
    QSqlQuery query;
    QString pattern = "%" + id + "%";

    query.prepare("SELECT Students.* "
                  "FROM Students "
                  "WHERE  Students.id LIKE :pattern");
    query.bindValue(":pattern", pattern);

    query.exec();
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

void Teacher::searchAbsenceById(const QString &id)
{
    QSqlQuery query;
    QString pattern = "%" + id + "%";

    query.prepare("select * from DetailedAbsences WHERE student_id LIKE :pattern");
    query.bindValue(":pattern", pattern);

    query.exec();
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

void Teacher::searchAbsenceByName(const QString &name)
{
    QSqlQuery query;
    QString pattern = "%" + name + "%";

    query.prepare("select DetailedAbsences.*, STUDENTS.NAME  from DetailedAbsences JOIN STUDENTS ON STUDENTS.ID = DetailedAbsences.student_id WHERE STUDENTS.NAME LIKE :pattern");
    query.bindValue(":pattern", pattern);

    query.exec();
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
}

bool Teacher::studentIdIsDuplicate(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM Students WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            // 如果查询返回至少一行结果，说明给定的ID已经存在
            return true;
        } else {
            // 如果查询没有返回结果，说明给定的ID不存在
            return false;
        }
    } else {
        return false;
    }
}

void Teacher::on_searchButton_clicked()
{
    if (ui->searchBox->currentIndex() == 0) {
        printMyCourse();
    } else if (ui->searchBox->currentIndex() == 1) {
        printAllCourse();
    } else if (ui->searchBox->currentIndex() == 2) {
        printAllStudent();
    } else if (ui->searchBox->currentIndex() == 3) {
        printAllMyStudent();
    } else if (ui->searchBox->currentIndex() == 4) {
        printAllAbsense();
    } else if (ui->searchBox->currentIndex() == 5) {
        printAllMyStudentAbsence();
    } else if (ui->searchBox->currentIndex() == 6) {
        searchCourseByName(ui->searchEdit->text());
    } else if (ui->searchBox->currentIndex() == 7) {
        searchCourseById(ui->searchEdit->text());
    } else if (ui->searchBox->currentIndex() == 8) {
        searchStudentByName(ui->searchEdit->text());
    } else if (ui->searchBox->currentIndex() == 9) {
        searchStudentById(ui->searchEdit->text());
    } else if (ui->searchBox->currentIndex() == 10) {
        searchAbsenceById(ui->searchEdit->text());
    } else if (ui->searchBox->currentIndex() == 11) {
        searchAbsenceByName(ui->searchEdit->text());
    }
}


void Teacher::on_searchBox_currentIndexChanged(int index)
{
    if (index >= 0 && index <= 5) {
        ui->searchEdit->hide();
    } else {
        ui->searchEdit->show();
    }
}


void Teacher::on_addStudentButton_clicked()
{
    QString id = ui->idAddEdit->text();
    if (studentIdIsDuplicate(id)) {
        QMessageBox::warning(this, "Add", "学生学号重复！");
    } else {
        QString name = ui->nameAddEdit->text();  // 从界面获取学生姓名
    //    QString gender = ui->genderAddEdit->text();  // 从界面获取学生性别
        QString gender = ui->genderBox->currentText();
        QString password = "123";  // 从界面获取学生密码
        QString major = ui->majorAddEdit->text();  // 从界面获取学生专业
        QString classId = ui->classAddEdit->text();  // 从界面获取学生班级
        int age = ui->ageAddEdit->text().toInt();  // 从界面获取学生年龄

        QSqlQuery query;
        query.prepare("INSERT INTO Students (id, name, gender, password, major, class, age) VALUES (:id, :name, :gender, :password, :major, :class, :age)");
        query.bindValue(":id", id);
        query.bindValue(":name", name);
        query.bindValue(":gender", gender);
        query.bindValue(":password", password);
        query.bindValue(":major", major);
        query.bindValue(":class", classId);
        query.bindValue(":age", age);

        if (query.exec()) {
            QMessageBox::information(this, "Add", "学生信息已成功添加,初始密码123！");
        } else {
            QMessageBox::warning(this, "Add", "添加学生信息失败！");
        }
    }
}


void Teacher::on_AbsenseButton_clicked()
{
    QString studentId = ui->sIdAbsenseEdit->text();  // 从界面获取学生ID
    QString courseId = ui->cIdEdit->text();  // 从界面获取课程ID
    QString absenseDate = ui->dateEdit->text();  // 从界面获取缺勤日期
    QString type = ui->absenseTypeBox->currentText();  // 从界面获取缺勤类型

    QSqlQuery query;

    if (ui->absenseBox->currentIndex() == 0) { //增加
        query.prepare("INSERT INTO Absences (student_id, course_id, absence_date, type) VALUES (:studentId, :courseId, :absenseDate, :type)");
        query.bindValue(":studentId", studentId);
        query.bindValue(":courseId", courseId);
        query.bindValue(":absenseDate", absenseDate);
        query.bindValue(":type", type);

    } else if (ui->absenseBox->currentIndex() == 1) { //删除
        query.prepare("DELETE FROM Absences WHERE student_id = :studentId AND course_id = :courseId AND absence_date = :absenseDate");
        query.bindValue(":studentId", studentId);
        query.bindValue(":courseId", courseId);
        query.bindValue(":absenseDate", absenseDate);

    } else if (ui->absenseBox->currentIndex() == 2) { //修改
        query.prepare("UPDATE Absences SET type = :typeNew WHERE student_id = :studentId AND course_id = :courseId AND absence_date = :absenseDate");
        query.bindValue(":studentId", studentId);
        query.bindValue(":courseId", courseId);
        query.bindValue(":absenseDate", absenseDate);
        query.bindValue(":typeNew", type);

    }
    if (query.exec()) {
        QMessageBox::information(this, "Absense", "操作成功！");
    } else {
        QMessageBox::warning(this, "Absense", "Database操作失败！" );
    }
}

