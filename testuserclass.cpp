/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testuserclass.cpp
 * Author: ivans
 *
 * Created on May 10, 2024, 9:15:59 PM
 */

#include "testuserclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testuserclass);

testuserclass::testuserclass() {
}

testuserclass::~testuserclass() {
}

void testuserclass::setUp() {
}

void testuserclass::tearDown() {
}

void testuserclass::testCalculateBMI() {
    User user("Ivan", "Male", 25, 70, 170);
    double expectedBMI = 70 / ((170 / 100.0) * (170 / 100.0));
    CPPUNIT_ASSERT_DOUBLES_EQUAL(expectedBMI, user.CalculateBMI(), 0.01);
}

void testuserclass::testSetDailyTarget() {
    User user("Ivan", "Male", 25, 70, 170);
    double targetCalories = 2000;
    user.SetDailyTarget(targetCalories);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(targetCalories, user.GetUserDailyTarget(), 0.01);
}

