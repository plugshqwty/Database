//  Калечиц Александра, 5 группа
//  Лаб 2, база данных с авторизацией

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlRecord>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/DB Browser/Flowers.db");

    if(db.open()){
        ui->statusbar->showMessage("Вы успешно подключились к базе данных: " + db.databaseName());}

    QSqlQuery query1("SELECT login FROM user");
    //QVector<QString> names;
    while (query1.next()) {
        names.push_back(query1.value(0).toString());
    }
    QSqlQuery query3("SELECT password FROM user");
  //  QVector<QString> passwords;
    while (query3.next()) {
        passwords.push_back(query3.value(0).toString());
    }
    const QModelIndex index;
}
void MainWindow::connectToDatabase(){
    if(db.open()){
        ui->statusbar->showMessage("Вы успешно подключились к базе данных: " + db.databaseName());

        model=new QSqlTableModel(this, db);
        model->setTable("Flower");
        model->select();
        ui->tableView->setModel(model);

        // Окрашивание таблицы через код
       /* ui->tableView->setStyleSheet("QTableView { background-color: #e2bbe9 ; }"
      "QTableView::item { background-color: #e2bbe9; color: black; }");
        // Изменение стиля заголовков столбцов
        ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: #e2bbe9; color:black; }");
        ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: #e2bbe9; color:black; }");
        ui->tableView->verticalScrollBar()->setStyleSheet(
            "QScrollBar:vertical {"
            "    background-color: #e2bbe9;"
           "    margin: 2px 2px 2px 2px;"
            "}"
            "QScrollBar::handle:vertical {"
            "    background-color: #e2bbe9;"
            "}");*/

        model1=new QSqlTableModel(this, db);
        model1->setTable("Compozitions");
        model1->select();
        ui->tableView_2->setModel(model1);

        model2=new QSqlTableModel(this, db);
        model2->setTable("user");
        model2->select();
        ui->tableView_3->setModel(model2);

        model3=new QSqlTableModel(this, db);
        model3->setTable("order");
        model3->select();
        ui->tableView_4->setModel(model3);

        model4=new QSqlTableModel(this, db);
        model4->setTable("flower_comp");
        model4->select();
        ui->tableView_5->setModel(model4);

    }
    else{
        ui->statusbar->showMessage("При подключении к базе данных произошла ошибка: " + db.lastError().databaseText());
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdd_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model->insertRow(model->rowCount());}
}


void MainWindow::on_pushButton_clicked()
{
    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model1->insertRow(model1->rowCount());}
}


void MainWindow::on_pushButton_2_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model2->insertRow(model2->rowCount());}
}


void MainWindow::on_pushButton_3_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model3->insertRow(model3->rowCount());}
}


void MainWindow::on_pushButton_4_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model4->insertRow(model4->rowCount());}
}


void MainWindow::on_pushButton_5_clicked()

{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
    QModelIndexList rows = ui->tableView->selectionModel()->selectedRows();

    for (const QModelIndex& index: rows){
        model->removeRow(index.row());
    }
    model->submitAll(); }// СОХРАНЕНИЕ

}


void MainWindow::on_pushButton_6_clicked()
{
    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
    QModelIndexList rows = ui->tableView_2->selectionModel()->selectedRows();

    for (const QModelIndex& index: rows){
        model1->removeRow(index.row());
    }
    model1->submitAll();} // СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_7_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
    QModelIndexList rows = ui->tableView_3->selectionModel()->selectedRows();

    for (const QModelIndex& index: rows){
        model2->removeRow(index.row());
    }
    model2->submitAll();} // СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_8_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
    QModelIndexList rows = ui->tableView_4->selectionModel()->selectedRows();

    for (const QModelIndex& index: rows){
        model3->removeRow(index.row());
    }
    model3->submitAll();} // СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_9_clicked()
{
    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
    QModelIndexList rows = ui->tableView_5->selectionModel()->selectedRows();

    for (const QModelIndex& index: rows){
        model4->removeRow(index.row());
    }
    model4->submitAll(); }// СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_10_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
     model->submitAll(); }// СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_11_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model1->submitAll();} // СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_12_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model2->submitAll();} // СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_13_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model3->submitAll();} // СОХРАНЕНИЕ
}


void MainWindow::on_pushButton_14_clicked()
{    if(check==0){
        QMessageBox::critical(this,"Сообщение", "Вы должны войти или зарегистрироваться");
    }
    else{
        model4->submitAll();} // СОХРАНЕНИЕ
}

void MainWindow::on_pushButton_15_clicked()
{  QString login = ui->login->text();
    QString pass = ui->pass->text();
    int k=0;
    login.toStdString();
    pass.toStdString();
    for(int i=0; i<names.size(); i++){
        if(login==names[i]){
            k++;
        }
    }

    if(k!=0){
        for(int i=0; i<names.size(); i++){
            if(login==names[i] && pass==passwords[i]){
                QMessageBox::information(this,"Сообщение", "Вы успешно вошли!");
                check++;
                connectToDatabase();
            }
            if(login==names[i] && pass!=passwords[i]){
                QMessageBox::critical(this,"Сообщение", "Неверный пароль!");
            }
        }
    }

    if(k==0){
        QMessageBox::critical(this,"Сообщение", "Такого пользователя нет, вы должны зарегистрироваться");
    }


}


void MainWindow::on_pushButton_16_clicked()
{  QString login = ui->login->text();
    QString pass = ui->pass->text();
    login.toStdString();
    pass.toStdString();
    int k=0;
    for(int i=0; i<names.size(); i++){
        if(login==names[i]){
            k++;
        }}

    if(k!=0){
        QMessageBox::information(this,"Сообщение", "Вы зарегистрированы, войдите в систему");}

    if(k==0){

        if(!validator.validatePassword(pass)||!validator.validateLogin(login)){
            QMessageBox::critical(this,"Сообщение", "Логин должен состоять не менее,чем из 5 не более, чем из 20 символов, а пароль из 8 и более (должен содержать хотя одну заглавную букву, хотя бы строчную букву и хотя бы одну цифру)");
        }
        if(!validator.validatePassword(pass)&&!validator.validateLogin(login)){
            QMessageBox::critical(this,"Сообщение", "Логин должен состоять не менее,чем из 5 не более, чем из 20 символов, а пароль из 8 и более (должен содержать хотя одну заглавную букву, хотя бы строчную букву и хотя бы одну цифру)");
        }
        if (validator.validatePassword(pass)&&validator.validateLogin(login)){
            {QMessageBox::information(this,"Сообщение", "Вы успешно зарегистрировались!");
                check++;
                connectToDatabase();
                names.push_back(login);
                passwords.push_back(pass);

                QSqlRecord record = model2->record();
                record.setValue("login", login);
                record.setValue("password", pass);
                connectToDatabase();

                // Вставляем новую запись
                if (model2->insertRecord(-1, record)) {
                    qDebug() << "Новая запись успешно добавлена в таблицу 'user'";
                } else {
                    qDebug() << "Ошибка при добавлении новой записи в таблицу 'user':" << model2->lastError().text();
                }
            }

        }

    }


}


