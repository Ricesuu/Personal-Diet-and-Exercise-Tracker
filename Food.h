/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Food.h
 * Author: ivans
 *
 * Created on May 7, 2024, 10:22 PM
 */

#ifndef FOOD_H
#define FOOD_H
#include <string>
using namespace std;

class Food {
public:
    Food();
    Food(string foodName, double foodCalories, double foodCarbs, double foodProtein, double foodFat);
    string GetFoodName();
    double GetCalories();
    double GetCarbs();
    double GetProtein();
    double GetFat();
    Food(const Food& orig);
    virtual ~Food();
private:
    string _foodName;
    double _foodCalories;
    double _foodCarbs;
    double _foodProtein;
    double _foodFat;
};

#endif /* FOOD_H */

