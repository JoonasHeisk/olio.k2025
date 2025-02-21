#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <string>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCountClick();
    void onResetClick();

private:
    Ui::MainWindow *ui;
    int counter;
};
#endif // MAINWINDOW_H
