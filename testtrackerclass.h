/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testtrackerclass.h
 * Author: ivans
 *
 * Created on May 10, 2024, 9:31:30 PM
 */

#ifndef TESTTRACKERCLASS_H
#define TESTTRACKERCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "Tracker.h"
#include "Meal.h"
#include "Walking.h"

class testtrackerclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testtrackerclass);

    CPPUNIT_TEST(testAddMeal);
    CPPUNIT_TEST(testAddExercise);

    CPPUNIT_TEST_SUITE_END();

public:
    testtrackerclass();
    virtual ~testtrackerclass();
    void setUp();
    void tearDown();

private:
    void testAddMeal();
    void testAddExercise();
};

#endif /* TESTTRACKERCLASS_H */

