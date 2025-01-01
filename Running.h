/* 
 * File:   Running.h
 * Author: ivans
 *
 * Created on May 6, 2024, 8:12 PM
 */

#ifndef RUNNING_H
#define RUNNING_H
#include "Exercise.h"

class Running:public Exercise{
public:
    Running();
    Running(Date exerciseDate, int durationOfExercise, int distanceCoveredInKM);
    virtual double CalcBurntCalories() override;
    Running(const Running& orig);
    virtual ~Running();
private:
    int _distanceCoveredInKM;
};

#endif /* RUNNING_H */

