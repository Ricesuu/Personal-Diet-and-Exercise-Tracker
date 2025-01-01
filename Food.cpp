/* 
 * File:   Food.cpp
 * Author: ivans
 * 
 * Created on May 7, 2024, 10:22 PM
 */

#include "Food.h"

// Default constructor
Food::Food() {
    _foodName = "";
    _foodCalories = 0;
    _foodCarbs = 0;
    _foodProtein = 0;
    _foodFat = 0;
}

// Pass-by-Value constructor
Food::Food(string foodName, double foodCalories, double foodCarbs, double foodProtein, double foodFat) {
    _foodName = foodName;
    _foodCalories = foodCalories;
    _foodCarbs = foodCarbs;
    _foodProtein = foodProtein;
    _foodFat = foodFat;
}

// Method to get the food name
string Food::GetFoodName() {
    return _foodName;
}

// Method to get the food calories
double Food::GetCalories() {
    return _foodCalories;
}

// Method to get the food carbohydrates
double Food::GetCarbs() {
    return _foodCarbs;
}

// Method to get the food protein
double Food::GetProtein() {
    return _foodProtein;
}

// Method to get the food fat
double Food::GetFat() {
    return _foodFat;
}

Food::Food(const Food& orig) {
}

Food::~Food() {
}

