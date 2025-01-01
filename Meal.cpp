/* 
 * File:   Meal.cpp
 * Author: ivans
 * 
 * Created on May 6, 2024, 8:09 PM
 */

#include "Meal.h"

//Default constructor
Meal::Meal() {
    _totalCaloriesOfMeal = 0;
}

//Pass-by-Value constructor
Meal::Meal(Date mealDate, MealType mealType){
    _mealDate = mealDate;
    _mealType = mealType;
    _foodAte = vector<Food*>();
}

//Method to return the food in Meal
vector<Food*> Meal::FoodAte() {
    return _foodAte;
}

//Method to return the date of meal
Date Meal::MealDate() {
    return _mealDate;
}

//Method to return the type of meal
MealType Meal::GetMealType() {
    return _mealType;
}

//Method to add food to the meal
void Meal::FoodNom(Food* food) {
    _foodAte.push_back(food);
}

//Method to calculate the total calories of the meal
double Meal::CalculateTotalCalories() {
    for (int i = 0; i < _foodAte.size(); i++) {
        _totalCaloriesOfMeal += _foodAte[i]->GetCalories();
    }
    return _totalCaloriesOfMeal;
}

Meal::Meal(const Meal& orig) {
}

Meal::~Meal() {
}

