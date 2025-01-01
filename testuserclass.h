/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   testuserclass.h
 * Author: ivans
 *
 * Created on May 10, 2024, 9:15:59 PM
 */

#ifndef TESTUSERCLASS_H
#define TESTUSERCLASS_H

#include <cppunit/extensions/HelperMacros.h>
#include "User.h"

class testuserclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testuserclass);

    CPPUNIT_TEST(testCalculateBMI);
    CPPUNIT_TEST(testSetDailyTarget);

    CPPUNIT_TEST_SUITE_END();

public:
    testuserclass();
    virtual ~testuserclass();
    void setUp();
    void tearDown();

private:
    void testCalculateBMI();
    void testSetDailyTarget();
};

#endif /* TESTUSERCLASS_H */

