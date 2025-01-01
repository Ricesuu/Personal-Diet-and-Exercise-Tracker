/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exercise.h
 * Author: ivans
 *
 * Created on May 6, 2024, 8:10 PM
 */

#ifndef EXERCISE_H
#define EXERCISE_H
#include "Date.h"

class Exercise {
public:
    Exercise();
    Exercise(Date exerciseDate, int durationOfExercise);
    virtual Date GetExerciseDate();
    virtual int GetDurationOfExercise();
    virtual double CalcBurntCalories() = 0;
    Exercise(const Exercise& orig);
    virtual ~Exercise();
protected:
    Date _exerciseDate;
    int _durationOfExercise;

};

#endif /* EXERCISE_H */

