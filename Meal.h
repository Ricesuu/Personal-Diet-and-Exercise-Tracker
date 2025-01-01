/* 
 * File:   Meal.h
 * Author: ivans
 *
 * Created on May 6, 2024, 8:09 PM
 */

#ifndef MEAL_H
#define MEAL_H
#include <vector>
#include "Food.h"
#include "Date.h"
using namespace std;

enum MealType {
    Breakfast,
    Lunch,
    Dinner,
    Supper
};

class Meal {
public:
    Meal();
    Meal(Date mealDate, MealType mealType);
    vector<Food*> FoodAte(); //View the food in a Meal
    Date MealDate();
    MealType GetMealType();
    void FoodNom(Food* food); //Add food to a Meal
    double CalculateTotalCalories();
    Meal(const Meal& orig);
    virtual ~Meal();

private:
    Date _mealDate;
    MealType _mealType;
    vector<Food*> _foodAte;
    double _totalCaloriesOfMeal;
};

#endif /* MEAL_H */

