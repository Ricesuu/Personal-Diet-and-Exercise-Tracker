/* 
 * File:   Walking.cpp
 * Author: ivans
 * 
 * Created on May 6, 2024, 8:11 PM
 */

#include "Walking.h"
#include "User.h"

// Default constructor
Walking::Walking() {
    _stepsTaken = 0;
}

// Pass-by-Value constructor
Walking::Walking(Date exerciseDate, int durationOfExercise, int stepsTaken):Exercise(exerciseDate, durationOfExercise){
    _exerciseDate = exerciseDate;
    _durationOfExercise = durationOfExercise;
    _stepsTaken = stepsTaken;
}

// Method to calculate the calories burned
double Walking::CalcBurntCalories() {
    // Estimate of calories burned per step for an average person
    double caloriesBurnedPerStep = 0.04; 
    return caloriesBurnedPerStep * _stepsTaken;
}

Walking::Walking(const Walking& orig) {
}

Walking::~Walking() {
}

