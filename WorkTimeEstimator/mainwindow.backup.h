#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// i need this so i can use the QTime Object
#include <QTime>
#include <math.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void on_timeStart_userTimeChanged(const QTime &time);
    void on_timeBreak_userTimeChanged(const QTime &time);
    void on_timeWork_userTimeChanged(const QTime &time);
};
#endif // MAINWINDOW_H
