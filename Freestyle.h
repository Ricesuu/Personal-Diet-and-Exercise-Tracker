/* 
 * File:   Freestyle.h
 * Author: ivans
 *
 * Created on May 6, 2024, 8:12 PM
 */

#ifndef FREESTYLE_H
#define FREESTYLE_H
#include "Exercise.h"

class Freestyle:public Exercise{
public:
    Freestyle();
    Freestyle(Date exerciseDate, int durationOfExercise, int heartRateBPM);
    virtual double CalcBurntCalories() override;
    Freestyle(const Freestyle& orig);
    virtual ~Freestyle();
private:
    int _heartRateBPM;

};

#endif /* FREESTYLE_H */

