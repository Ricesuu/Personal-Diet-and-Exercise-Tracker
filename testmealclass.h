/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testmealclass.h
 * Author: ivans
 *
 * Created on May 10, 2024, 9:46:50 PM
 */

#ifndef TESTMEALCLASS_H
#define TESTMEALCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "Meal.h"
#include "Food.h"

class testmealclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testmealclass);

    CPPUNIT_TEST(testCalculateTotalCalories);

    CPPUNIT_TEST_SUITE_END();

public:
    testmealclass();
    virtual ~testmealclass();
    void setUp();
    void tearDown();

private:
    void testCalculateTotalCalories();
};

#endif /* TESTMEALCLASS_H */

