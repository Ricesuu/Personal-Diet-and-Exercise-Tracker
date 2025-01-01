/* 
 * File:   Running.cpp
 * Author: ivans
 * 
 * Created on May 6, 2024, 8:12 PM
 */

#include "Running.h"

// Default constructor
Running::Running() {
    _distanceCoveredInKM = 0;
}

// Pass-by-Value constructor
Running::Running(Date exerciseDate, int durationOfExercise, int distanceCoveredInKM) {
    _exerciseDate = exerciseDate;
    _durationOfExercise = durationOfExercise;
    _distanceCoveredInKM = distanceCoveredInKM;
}

// Method to calculate the calories burned
double Running::CalcBurntCalories() {
    // Estimate of calories burned per kilometer for average person
    double caloriesBurnedPerKilometer = 100.0; 
    return caloriesBurnedPerKilometer * _distanceCoveredInKM;
}

Running::Running(const Running& orig) {
}

Running::~Running() {
}

