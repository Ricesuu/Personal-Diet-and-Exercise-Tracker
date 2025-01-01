/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testmealclass.cpp
 * Author: ivans
 *
 * Created on May 10, 2024, 9:46:50 PM
 */

#include "testmealclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testmealclass);

testmealclass::testmealclass() {
}

testmealclass::~testmealclass() {
}

void testmealclass::setUp() {
}

void testmealclass::tearDown() {
}

void testmealclass::testCalculateTotalCalories() {
    Meal meal;
    Food* food1 = new Food("Banana", 200, 200, 200, 200);
    Food* food2 = new Food("Apple", 300, 200, 200, 200);
    meal.FoodNom(food1);
    meal.FoodNom(food2);
    double totalCalories = meal.CalculateTotalCalories();
    CPPUNIT_ASSERT_DOUBLES_EQUAL(500.0, totalCalories, 0.01);
    delete food1;
    delete food2;
}

