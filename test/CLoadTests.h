
#ifndef CLOADTESTS_H_
#define CLOADTESTS_H_

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"




/**
 * This class implements several test cases related to loading the
 * data for the database from a file. Each test case is implemented
 * as a method testXXX. The static method suite() returns a TestSuite
 * in which all tests are registered.
 */
class CLoadExisting: public CppUnit::TestCase {
public:
CLoadExisting() : TestCase("Load existing") {
}
void runTest() {
CRoute a;
a.print();
}
};


#endif /* CLOADTESTS_H_ */
