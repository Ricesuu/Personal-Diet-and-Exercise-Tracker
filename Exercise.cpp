/* 
 * File:   Exercise.cpp
 * Author: ivans
 * 
 * Created on May 6, 2024, 8:10 PM
 */

#include "Exercise.h"


Exercise::Exercise() {
}

// Pass-by-Value constructor
Exercise::Exercise(Date exerciseDate, int durationOfExercise) {
    _exerciseDate = exerciseDate;
    _durationOfExercise = durationOfExercise;
}

// Method to get the exercise date
Date Exercise::GetExerciseDate() {
    return _exerciseDate;
}

// Method to get the duration of the exercise
int Exercise::GetDurationOfExercise() {
    return _durationOfExercise;
}

Exercise::Exercise(const Exercise& orig) {
}

Exercise::~Exercise() {
}

