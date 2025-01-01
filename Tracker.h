/* 
 * File:   Tracker.h
 * Author: ivans
 *
 * Created on May 6, 2024, 8:09 PM
 */

#ifndef TRACKER_H
#define TRACKER_H
#include <vector>
#include "Date.h"
#include "Meal.h"
#include "Exercise.h"

class Tracker {
public:
    Tracker();
    vector<Meal*> GetMealsConsumed();
    void AddMeal(Meal* meal);
    void RemoveMeal(Meal* meal);
    vector<Exercise*> GetExercisesDone();
    void AddExercise(Exercise* exercise);
    double CalculateDailyCaloriesConsumed(Date dailyDate);
    double CalculateDailyCaloriesBurnt(Date dailyDate);
    double CalculateMonthlyCaloriesConsumed(Date monthlyDate);
    double CalculateMonthlyCaloriesBurnt(Date monthlyDate);
    Tracker(const Tracker& orig);
    virtual ~Tracker();
private:
    vector<Meal*> _mealsConsumed;
    vector<Exercise*> _exercisesDone;
};

#endif /* TRACKER_H */

