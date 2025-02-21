#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    state = 1;
    operand = -1;
    number1 = "";
    number2 = "";

    ui->Vastaus->setReadOnly(true);

    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);

    connect(ui->NP, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->NK, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->NJ, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->NM, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    connect(ui->NClear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->NEnter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{

    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString number = button->text();

    if (state == 1) {
        number1.append(number);
        qDebug() << "number1: " << number1;
    } else if (state == 2) {
        number2.append(number);
        qDebug() << "number2: " << number2;
    }


    if (state == 1) {
        ui->EkaNum->setText(number1);
    } else if (state == 2) {
        ui->TokaNum->setText(number2);
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString operatorText = button->text();

    if (operatorText == "+") {
        operand = 0;
    } else if (operatorText == "-") {
        operand = 1;
    } else if (operatorText == "*") {
        operand = 2;
    } else if (operatorText == "/") {
        operand = 3;
    }


    state = 2;
}

void MainWindow::clearAndEnterClickHandler()
{

    if (sender() == ui->NClear) {
        resetLineEdits();
    }


    if (sender() == ui->NEnter) {
        float num1 = number1.toFloat();
        float num2 = number2.toFloat();

        switch (operand) {
        case 0: // +
            result = num1 + num2;
            break;
        case 1: // -
            result = num1 - num2;
            break;
        case 2: // *
            result = num1 * num2;
            break;
        case 3: // /
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                qDebug() << "Error: Division by zero";
                return;
            }
            break;
        default:
            break;
        }


        ui->Vastaus->setText(QString::number(result));
        qDebug() << "Result: " << result;


        number1 = QString::number(result);
        number2 = "";
        state = 1;
    }
}

void MainWindow::resetLineEdits()
{
    number1 = "";
    number2 = "";
    state = 1;
    ui->EkaNum->clear();
    ui->TokaNum->clear();
    ui->Vastaus->clear();
}
