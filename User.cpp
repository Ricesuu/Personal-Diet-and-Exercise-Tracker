/* 
 * File:   User.cpp
 * Author: ivans
 * 
 * Created on May 6, 2024, 8:08 PM
 */

#include "User.h"
#include <iostream>

//Default constructor
User::User() {
}

//Pass-by-Value constructor
User::User(string name, string gender, int age, double weight, double height){
    _name = name;
    _gender = gender;
    _age = age;
    _weight = weight;
    _height = height;
    _dailyTargetCalories = 0;
}

//Method to edit personal information
void User::EditPersonalInfo(string name, string gender, int age, double weight, double height){
    _name = name;
    _gender = gender;
    _age = age;
    _weight = weight;
    _height = height;
    cout << "\nYour personal information has been updated to: " <<"\n";
    ViewPersonalInfo();
}

//Method to set daily target calories
void User::SetDailyTarget(double dailyTargetCalories){
    _dailyTargetCalories = dailyTargetCalories;
    cout << "\nYour Daily Target has been set to " << dailyTargetCalories << " kcal" <<"\n";
}

//Method to view personal information
void User::ViewPersonalInfo() {
    cout << "Name: " << _name <<"\n";
    cout << "Gender: " << _gender <<"\n";
    cout << "Age: " << _age <<"\n";
    cout << "Weight: " << _weight << " kg" <<"\n";
    cout << "Height: " << _height << " cm" <<"\n";
    cout << "Daily Target Calories: " << _dailyTargetCalories << " kcal" <<"\n";
}

//Method to calculate BMI
double User::CalculateBMI(){
    return _weight / ((_height / 100.0) * (_height / 100.0));
}

//Method to check daily calories and if exceeded daily target
void User::CheckDailyCalories(Date currentDate){
    double dailyCaloriesConsumed = _tracker.CalculateDailyCaloriesConsumed(currentDate);
    cout << "\nDaily Calories Consumed: " << dailyCaloriesConsumed << " kcal" <<"\n";

    if (dailyCaloriesConsumed > _dailyTargetCalories) {
        cout << "You have exceeded your daily calorie limit of " << _dailyTargetCalories << " kcal.\n";
    } else {
        cout << "You have not exceeded your daily calorie limit of " << _dailyTargetCalories << " kcal.\n";
    }
}

//Method to check daily calories burnt
void User::CheckDailyCaloriesBurnt(Date currentDate){
    cout << "Daily Calories Burnt: " << _tracker.CalculateDailyCaloriesBurnt(currentDate) << " kcal" <<"\n";
}

//Method to add food to food vector
void User::AddFood(Food* food){
    for (int i = 0; i < _addedFood->size(); i++) {
        if ((*_addedFood)[i]->GetFoodName() == food->GetFoodName()) {
            return;
        }
    }
    _addedFood->push_back(food);
}

//Method to remove a food from vector
void User::RemoveFood(string foodName){
    for (int i = 0; i < _addedFood->size(); i++) {
        if ((*_addedFood)[i]->GetFoodName() == foodName) {
            _addedFood->erase(_addedFood->begin() + i);
            break;
        }
    }
}

//Method to search and view food
void User::SearchAndViewFood(string foodName){
    for (int i = 0; i < _addedFood->size(); i++) {
        if ((*_addedFood)[i]->GetFoodName() == foodName) {
            cout << "Your food has been found" <<"\n";
            cout << "Food Name: " << (*_addedFood)[i]->GetFoodName() <<"\n";
            cout << "Calories: " << (*_addedFood)[i]->GetCalories() << " kcal" <<"\n";
            cout << "Carbs: " << (*_addedFood)[i]->GetCarbs() << " g" <<"\n";
            cout << "Protein: " << (*_addedFood)[i]->GetProtein() << " g" <<"\n";
            cout << "Fat: " << (*_addedFood)[i]->GetFat() << " g" <<"\n";
            return;
        }
    }
    cout << "Your food does not exist" <<"\n";
}

//Method to create a meal
void User::CreateMeal(Date mealDate, MealType mealType, Food* food){
    Meal* meal = new Meal(mealDate, mealType);
    meal->FoodNom(food);
    _tracker.AddMeal(meal);
}

//Method to delete a meal
void User::DeleteMeal(Date mealDate, MealType mealType){
    for (int i = 0; i < _tracker.GetMealsConsumed().size(); i++) {
        if (_tracker.GetMealsConsumed()[i]->MealDate() == mealDate && _tracker.GetMealsConsumed()[i]->GetMealType() == mealType) {
            _tracker.RemoveMeal(_tracker.GetMealsConsumed()[i]);
        }
    }
}

//Method to view monthly calories consumed
double User::ViewMonthlyCaloriesOfYear(int month, int year){
    Date monthlyDate;
    monthlyDate.month = month;
    monthlyDate.year = year;
    return _tracker.CalculateMonthlyCaloriesConsumed(monthlyDate);
}

//Method to view monthly calories burnt
double User::ViewMonthlyCaloriesBurntOfYear(int month, int year){
    Date monthlyDate;
    monthlyDate.month = month;
    monthlyDate.year = year;
    return _tracker.CalculateMonthlyCaloriesBurnt(monthlyDate);
}

//Method to add exercise
void User::UserAddExercise(Exercise* exercise) {
    _tracker.AddExercise(exercise);
}

//Method to view all added food
vector<Food*> User::ViewAddedFood(){
    return *_addedFood;
}

//Method to get food for meal
Food* User::GetFoodForMeal(string foodName){
    for (int i = 0; i < _addedFood->size(); i++) {
        if ((*_addedFood)[i]->GetFoodName() == foodName) {
            cout << "Your food has been found" <<"\n";
            return (*_addedFood)[i];
        }
    }
    cout << "Your food does not exist" <<"\n";
}

//Method to get user's name
string User::GetUserName(){
    return _name;
}

//Method to get user's gender
string User::GetUserGender(){
    return _gender;
}

//Method to get user's age
int User::GetUserAge(){
    return _age;
}

//Method to get user's weight
double User::GetUserWeight(){
    return _weight;
}

//Method to get user's height
double User::GetUserHeight(){
    return _height;
}

//Method to get user's daily target
int User::GetUserDailyTarget(){
    return _dailyTargetCalories;
}

User::User(const User& orig) {
}

User::~User() {
}

