#ifndef WORKTIMES_H
#define WORKTIMES_H

#include <QTime>
#include <math.h>


class WorkTimes
{
public:
    WorkTimes(QTime startTime, QTime breakTime, QTime plannedWorkTime);
    WorkTimes();

private:
    QTime startTime;
    QTime breakTime;
    QTime plannedWorkTime;
    QTime goHomeTimeSpot;

public:
    void setStartTime(QTime time);
    void setBreakTime(QTime time);
    void setPlannedWorkTime(QTime time);

    bool canIGoHomeYet();

    QTime getWorkTimeTilHome();
    QTime getGoHomeTimeSpot();

private:
    void setGoHomeTimeSpot();

    QTime getStartTime();
    QTime getBreakTime();
    QTime getPlannedWorkTime();

//    QTime getWorkTimeTilHome();
//    QTime getGoHomeTimeSpot();
};


#endif // WORKTIMES_H
