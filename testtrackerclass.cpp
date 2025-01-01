/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testtrackerclass.cpp
 * Author: ivans
 *
 * Created on May 10, 2024, 9:31:30 PM
 */

#include "testtrackerclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testtrackerclass);

testtrackerclass::testtrackerclass() {
}

testtrackerclass::~testtrackerclass() {
}

void testtrackerclass::setUp() {
}

void testtrackerclass::tearDown() {
}

void testtrackerclass::testAddMeal() {
    Tracker tracker;
    Meal* meal = new Meal();
    tracker.AddMeal(meal);
    CPPUNIT_ASSERT_EQUAL(static_cast<size_t>(1), tracker.GetMealsConsumed().size());
    delete meal;
}

void testtrackerclass::testAddExercise() {
    Tracker tracker;
    Exercise* exercise = new Walking();
    tracker.AddExercise(exercise);
    CPPUNIT_ASSERT_EQUAL(static_cast<size_t>(1), tracker.GetExercisesDone().size());
    delete exercise;
}

