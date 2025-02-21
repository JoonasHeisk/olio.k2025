#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberClickedHandler();
    void addSubMulDivClickHandler();
    void clearAndEnterClickHandler();

private:
    void resetLineEdits();

    Ui::MainWindow *ui;
    QString number1, number2;
    int state;
    float result;
    short operand;
};

#endif
