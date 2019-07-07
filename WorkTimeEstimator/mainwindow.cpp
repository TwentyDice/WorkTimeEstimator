#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "worktimes.h"

#include <QtWidgets>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    // set default times times
    ui->timeStart->setTime(QTime::currentTime());

    QTime defaultBreakTime;
    defaultBreakTime.QTime::setHMS(0,30,0,0);
    ui->timeBreak->setTime(defaultBreakTime);
    defaultBreakTime.~QTime();

    QTime defaultTimeWork;
    defaultTimeWork.QTime::setHMS(8,0,0,0);
    ui->timeWork->setTime(defaultTimeWork);
    defaultTimeWork.~QTime();

    // create the WorkTimes object
//    WorkTimes wTimes(ui->timeStart->time(),ui->timeBreak->time(),ui->timeWork->time());

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000);

    updateTime();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime(){

    if (wTimes.canIGoHomeYet() == true){
        ui->timeTilGoHome->setText("Go home");
    }
    else {
        QTime leftTime = wTimes.getWorkTimeTilHome();
        ui->timeTilGoHome->setText(leftTime.QTime::toString("hh:mm:ss"));
    }

//    QTime leftTime = wTimes.getWorkTimeTilHome();
//    ui->timeTilGoHome->setText(leftTime.QTime::toString("hh:mm:ss"));

}

void MainWindow::on_timeStart_userTimeChanged(const QTime &time)
{

    wTimes.setStartTime(time);
    ui->timeSpotGoHome->setTime(wTimes.getGoHomeTimeSpot());

}

void MainWindow::on_timeBreak_userTimeChanged(const QTime &time)
{

    wTimes.setBreakTime(time);
    ui->timeSpotGoHome->setTime(wTimes.getGoHomeTimeSpot());

}

void MainWindow::on_timeWork_userTimeChanged(const QTime &time)
{

    wTimes.setPlannedWorkTime(time);
    ui->timeSpotGoHome->setTime(wTimes.getGoHomeTimeSpot());

}
