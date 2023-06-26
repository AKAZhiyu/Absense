void changePassword::on_pushButton_confirm_clicked()
{
    QString input_password = ui->lineEdit_origin->text();
    if (input_password != QString::fromStdString(p->getPasswd())) {
        QMessageBox::warning(this, "Login", "密码错误");
    } else {
        if (ui->lineEdit_new->text() != ui->lineEdit_confirm->text()) {
            QMessageBox::warning(this, "Login", "两次密码不一致");
        } else {
            std::string new_password = (ui->lineEdit_new->text()).toStdString();

            QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
            db.setDatabaseName("mydb");
            db.setUserName("myusername");
            db.setPassword("mypassword");
            if (!db.open()) {
                QMessageBox::warning(this, "Login", "数据库连接失败");
            }
            p->setPassword(new_password);
        }
    }
}
