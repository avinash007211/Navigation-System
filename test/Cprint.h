
#ifndef CPRINT_H_
#define CPRINT_H_
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Test.h>

#include "../myCode/CRoute.h"
#include "../myCode/CWaypoint.h"



/**
 * This class implements several test cases related to loading the
 * data for the database from a file. Each test case is implemented
 * as a method testXXX. The static method suite() returns a TestSuite
 * in which all tests are registered.
 */
class Cprint: public CppUnit::TestFixture {
private:
	//CWpDatabase m_wpdbobject;
	CRoute m_route;
	CPoiDatabase m_POIdbobject;
		CWpDatabase m_wpdbobject;

public:

	void setUp()
	{
				CWaypoint Location1("Location1",14.1,20.2);
				CWaypoint Location2("Location2",44.1,70.2);

				m_wpdbobject.addWaypoint(Location1);
				m_wpdbobject.addWaypoint(Location2);

				CPOI POI1(restaurant,"POI1","Amazing restaurant",11.5,21.2);
				CPOI POI2(sightseeing,"POI2","huge open peaceful space",11.0,14.0);


				m_POIdbobject.addPoi(POI1);
				m_POIdbobject.addPoi(POI2);

				m_route.connectToWpDatabase(&m_wpdbobject);
				m_route.connectToPoiDatabase(&m_POIdbobject);
				m_route.addWaypoint("Location1");
				m_route.addWaypoint("Location2");
				m_route.addPoi("POI1","Location1");
				m_route.addPoi("POI2","Location2");
	}

	void printtest()
	{
		m_route.print();

	}
	static CppUnit::TestSuite* suite() {CppUnit::TestSuite* suite = new CppUnit::TestSuite("addingprintTests");

		suite->addTest(new CppUnit::TestCaller<Cprint>("SetUp", &Cprint::setUp));
		suite->addTest(new CppUnit::TestCaller<Cprint>("printtest", &Cprint::printtest));

		return suite;
	}
};






#endif /* CADDWAYPOINT_H_ */
