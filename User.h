/* 
 * File:   User.h
 * Author: ivans
 *
 * Created on May 6, 2024, 8:08 PM
 */

#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "Date.h"
#include "Food.h"
#include "Meal.h"
#include "Exercise.h"
#include "Tracker.h"

class User {
public:
    User();
    User(string name, string gender, int age, double weight, double height);
    void EditPersonalInfo(string name, string gender, int age, double weight, double height);
    void SetDailyTarget(double dailyTargetCalories);
    void ViewPersonalInfo();
    double CalculateBMI();
    void CheckDailyCalories(Date currentDate);
    void CheckDailyCaloriesBurnt(Date currentDate);
    void AddFood(Food* food);
    void RemoveFood(string foodName);
    void SearchAndViewFood(string foodName);
    void CreateMeal(Date mealDate, MealType mealType, Food* food);
    void DeleteMeal(Date mealDate, MealType mealType);
    double ViewMonthlyCaloriesOfYear(int month, int year);
    void UserAddExercise(Exercise* exercise);
    double ViewMonthlyCaloriesBurntOfYear(int month, int year);
    vector<Food*> ViewAddedFood();
    Food* GetFoodForMeal(string foodName);
    string GetUserName();
    string GetUserGender();
    int GetUserAge();
    double GetUserWeight();
    double GetUserHeight();
    int GetUserDailyTarget();

    User(const User& orig);
    virtual ~User();
private:
    string _name;
    string _gender;
    int _age;
    double _weight;
    double _height;
    double _dailyTargetCalories;
    Tracker _tracker;
    vector<Food*>* _addedFood = new vector<Food*>;


};

#endif /* USER_H */