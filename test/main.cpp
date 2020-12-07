
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
#include <iostream>
//#include "CLoadTests.h"
#include "CAddWaypoint.h"
#include"Cprint.h"
#include"CAddPoi.h"
#include"CPlusEqualOperator.h"
#include"CPlusOperatortest.h"
//#include "CLoadTests.h"
#include "../myCode/CWaypoint.h"
#include "../mycode/CGPSSensor.h"
#include "../myCode/CNavigationSystem.h"
#include "../myCode/CPOI.h"
#include "../myCode/CPoiDatabase.h"
#include "../myCode/CRoute.h"
#include "../myCode/CPersistentStorage.h"
#include "../myCode/CJsonPersistance.h"

using namespace CppUnit;
using namespace std;

int main (int argc, char* argv[]) {
	cout<<"Hello"<<endl;
	TextUi::TestRunner runner;

	runner.addTest( CAddWaypoint::suite() );
	runner.addTest( Cprint::suite() );
	runner.addTest(CAddPoi::suite());
	runner.addTest(CPlusEqualOperator::suite());
	runner.addTest(CPlusOperatortest::suite());
	runner.run();

	return 0;
}



