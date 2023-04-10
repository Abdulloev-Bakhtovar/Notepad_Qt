#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    filePath ="";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open file");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        ui->statusbar->showMessage("Ошибка при открытие файла",5000);
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);

    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        ui->statusbar->showMessage("Ошибка при открытие файла",5000);
        return;
    }
    QString txt = ui->textEdit->toPlainText();
    QTextStream out(&file);
    out << txt;
    if(file.flush())
    {
        ui->statusbar->showMessage("Успешно сохранено",5000);
    }
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Open file");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","File not open");
        return;
    }
    QString txt = ui->textEdit->toPlainText();
    QTextStream out(&file);
    out << txt;
    if(file.flush())
    {
        ui->statusbar->showMessage("Успешно сохранено",5000);
    }
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepad_triggered()
{
    QMessageBox::information(this,"About notepad 2023", "[Version 1.0.0]\n(c) Корпорация Бахтсофт (Bakhtsoft Corporation).\n2003-2023 Все права защищены.");
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

