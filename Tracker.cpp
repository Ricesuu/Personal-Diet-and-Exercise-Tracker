/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tracker.cpp
 * Author: ivans
 * 
 * Created on May 6, 2024, 8:09 PM
 */

#include "Tracker.h"

//Default constructor
Tracker::Tracker() {
}

//Method to return the meals consumed
vector<Meal*> Tracker::GetMealsConsumed() {
    return _mealsConsumed;
}

//Method to add meal to the meals consumed
void Tracker::AddMeal(Meal* meal) {
    _mealsConsumed.push_back(meal);
}

//Method to remove meal from the meals consumed
void Tracker::RemoveMeal(Meal* meal) {
    for (int i = 0; i < _mealsConsumed.size(); i++) {
        if (_mealsConsumed[i] == meal) {
            _mealsConsumed.erase(_mealsConsumed.begin() + i);
        }
    }
}

//Method to return the exercises done
vector<Exercise*> Tracker::GetExercisesDone() {
    return _exercisesDone;
}

//Method to add exercise to the exercises done
void Tracker::AddExercise(Exercise* exercise) {
    _exercisesDone.push_back(exercise);
}

//Method to remove exercise from the exercises done
double Tracker::CalculateDailyCaloriesConsumed(Date dailyDate) {
    double totalDailyCaloriesConsumed = 0;
    for (int i = 0; i < _mealsConsumed.size(); i++) {
        if (_mealsConsumed[i]->MealDate() == dailyDate) {
            totalDailyCaloriesConsumed += _mealsConsumed[i]->CalculateTotalCalories();
        }
    }
    return totalDailyCaloriesConsumed;
}

//Method to calculate the total calories burnt in a day
double Tracker::CalculateDailyCaloriesBurnt(Date dailyDate) {
    double totalDailyCaloriesBurnt = 0;
    for (int i = 0; i < _exercisesDone.size(); i++) {
        if (_exercisesDone[i]->GetExerciseDate() == dailyDate) {
            totalDailyCaloriesBurnt += _exercisesDone[i]->CalcBurntCalories();
        }
    }
    return totalDailyCaloriesBurnt;
}

//Method to calculate the total calories consumed in a month
double Tracker::CalculateMonthlyCaloriesConsumed(Date monthlyDate) {
    double totalMonthlyCaloriesConsumed = 0;
    for (int i = 0; i < _mealsConsumed.size(); i++) {
        if (_mealsConsumed[i]->MealDate().month == monthlyDate.month && _mealsConsumed[i]->MealDate().year == monthlyDate.year) {
            totalMonthlyCaloriesConsumed += _mealsConsumed[i]->CalculateTotalCalories();
        }
    }
    return totalMonthlyCaloriesConsumed;
}

//Method to calculate the total calories burnt in a month
double Tracker::CalculateMonthlyCaloriesBurnt(Date monthlyDate) {
    double totalMonthlyCaloriesBurnt = 0;
    for (int i = 0; i < _exercisesDone.size(); i++) {
        if (_exercisesDone[i]->GetExerciseDate().month == monthlyDate.month && _exercisesDone[i]->GetExerciseDate().year == monthlyDate.year) {
            totalMonthlyCaloriesBurnt += _exercisesDone[i]->CalcBurntCalories();
        }
    }
    return totalMonthlyCaloriesBurnt;
}

Tracker::Tracker(const Tracker& orig) {
}

Tracker::~Tracker() {
}

