#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , counter(0)
{
    ui->setupUi(this);

    ui->Boksi->setText(QString::number(counter));

    connect(ui->CountNappi, &QPushButton::clicked, this, &MainWindow::onCountClick);
    connect(ui->ResetNappi, &QPushButton::clicked, this, &MainWindow::onResetClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCountClick()
{
    qDebug()<<"Click vastaanotettu";
    counter++;
    ui->Boksi->setText(QString::number(counter));

}

void MainWindow::onResetClick()
{
    qDebug()<<"Click vastaanotettu";
    counter = 0;
    ui->Boksi->setText(QString::number(counter));

}

