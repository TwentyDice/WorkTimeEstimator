#include "worktimes.h"

WorkTimes::WorkTimes(){};

WorkTimes::WorkTimes(QTime startTime, QTime breakTime, QTime plannedWorkTime)
{
    setStartTime(startTime);
    setBreakTime(breakTime);
    setPlannedWorkTime(plannedWorkTime);

}

void WorkTimes::setStartTime(QTime time){

    if (time != getStartTime()){
        startTime = time;
        setGoHomeTimeSpot();
    }
}

void WorkTimes::setBreakTime(QTime time){

    if (time != getBreakTime()){
        breakTime = time;
        setGoHomeTimeSpot();
    }
}

void WorkTimes::setPlannedWorkTime(QTime time){

    if (time != getBreakTime()){
        plannedWorkTime = time;
        setGoHomeTimeSpot();
    }
}

QTime WorkTimes::getStartTime(){

    return this->startTime;

}

QTime WorkTimes::getBreakTime(){

    return breakTime;

}

QTime WorkTimes::getPlannedWorkTime(){

    return plannedWorkTime;

}

void WorkTimes::setGoHomeTimeSpot(){

        int hours=0;
        int minutes=0;
        int seconds=0;

        QTime startTime = getStartTime();
        QTime breakTime = getBreakTime();
        QTime plannedWorkTime = getPlannedWorkTime();

        seconds = (startTime.second() + breakTime.second() + plannedWorkTime.second());

        minutes =
                (startTime.minute() + breakTime.minute() + plannedWorkTime.minute())
                + std::floor(seconds / 60);

        seconds = seconds % 60;

        hours =
                (startTime.hour() + breakTime.hour() + plannedWorkTime.hour())
                 + std::floor(minutes / 60);

        minutes = minutes % 60;

        hours = hours % 24;

        goHomeTimeSpot.setHMS(hours,minutes,seconds,0);

    }

QTime WorkTimes::getGoHomeTimeSpot(){

        return goHomeTimeSpot;

    }

QTime WorkTimes::getWorkTimeTilHome (){

        QTime currentTime = QTime::currentTime();
//        currentTime.setHMS(7,0,0,0);


        QTime workTimeTilHome = getGoHomeTimeSpot();

        int hours=0;
        int minutes=0;
        int seconds=0;

        // day overlap

        seconds += workTimeTilHome.second()- currentTime.second();
        if (seconds < 0){
            minutes--;
            seconds += 60;
        }

        minutes += workTimeTilHome.minute() - currentTime.minute();
        if (minutes < 0){
            hours--;
            minutes += 60;
        }

        hours += workTimeTilHome.hour() - currentTime.hour();
        // now hours overflow

        if (hours < 0){hours += 23;
        }

        workTimeTilHome.setHMS(
                    workTimeTilHome.hour() - currentTime.hour(),
                    workTimeTilHome.minute() - currentTime.minute(),
                    workTimeTilHome.second()- currentTime.second(),
                    0);


        workTimeTilHome.setHMS(hours,minutes,seconds,0);

        return workTimeTilHome;
    }

bool WorkTimes::canIGoHomeYet(){

//        QTime breakTime = this->getBreakTime();
//        QTime workTime = this->getPlannedWorkTime();

//        QTime bTime = breakTime + workTime;


//        QTime goHomeSpot = this->getGoHomeTimeSpot();
//        QTime tilHomeTime = this->getWorkTimeTilHome();

//        if (tilHomeTime > goHomeSpot ){
//            return true;
//        }
//        else {
//            return false;
//        }

    return false;

    }
