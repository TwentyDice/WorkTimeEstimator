#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <worktimes.h>

// i need this so i can use the QTime Object
#include <QTime>
#include <math.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    WorkTimes wTimes;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void updateTime();

    void on_timeStart_userTimeChanged(const QTime &time);
    void on_timeBreak_userTimeChanged(const QTime &time);
    void on_timeWork_userTimeChanged(const QTime &time);
};
#endif // MAINWINDOW_H
