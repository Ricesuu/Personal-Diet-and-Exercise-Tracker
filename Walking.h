/* 
 * File:   Walking.h
 * Author: ivans
 *
 * Created on May 6, 2024, 8:11 PM
 */

#ifndef WALKING_H
#define WALKING_H
#include "Exercise.h"

class Walking:public Exercise{
public:
    Walking();
    Walking(Date exerciseDate, int durationOfExercise, int stepsTaken);
    virtual double CalcBurntCalories() override;
    Walking(const Walking& orig);
    virtual ~Walking();
private:
    int _stepsTaken;
};

#endif /* WALKING_H */

