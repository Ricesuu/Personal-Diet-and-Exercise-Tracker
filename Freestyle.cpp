/* 
 * File:   Freestyle.cpp
 * Author: ivans
 * 
 * Created on May 6, 2024, 8:12 PM
 */

#include "Freestyle.h"

// Default constructor
Freestyle::Freestyle() {
    _heartRateBPM = 0;
}

// Pass-by-Value constructor
Freestyle::Freestyle(Date exerciseDate, int durationOfExercise, int heartRateBPM) {
    _exerciseDate = exerciseDate;
    _durationOfExercise = durationOfExercise;
    _heartRateBPM = heartRateBPM;
}

// Method to calculate the calories burned
double Freestyle::CalcBurntCalories() {
    // Estimate of calories burned per minute for an average heart rate
    double caloriesBurnedPerMinute = 0.07 * _heartRateBPM; 
    return caloriesBurnedPerMinute * _durationOfExercise;
}

Freestyle::Freestyle(const Freestyle& orig) {
}

Freestyle::~Freestyle() {
}

