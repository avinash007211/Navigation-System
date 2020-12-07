

#ifndef CPLUSEQUALOPERATOR_H_
#define CPLUSEQUALOPERATOR_H_
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Test.h>

#include "../myCode/CRoute.h"
#include "../myCode/CWaypoint.h"
#include"../myCode/CPOI.h"
#include "../myCode/CPoiDatabase.h"
#include "../myCode/CWpDatabase.h"



/**
 * This class implements several test cases related to loading the
 * data for the database from a file. Each test case is implemented
 * as a method testXXX. The static method suite() returns a TestSuite
 * in which all tests are registered.
 */
class CPlusEqualOperator: public CppUnit::TestFixture {
private:
	CWpDatabase m_wpdbobject;
	CRoute m_route;
	CPoiDatabase m_POIdbobject;

public:

	void setUp()
	{
		CWaypoint Location1("Location1",14.1,20.2);
		CWaypoint Location2("Location2",44.1,70.2);

		CWaypoint Location3("Location3",14.1,20.2);
		CWaypoint Location4("Location4",44.1,70.2);
		m_wpdbobject.addWaypoint(Location1);
		m_wpdbobject.addWaypoint(Location2);
		m_wpdbobject.addWaypoint(Location3);
		m_wpdbobject.addWaypoint(Location4);

		CPOI POI1(restaurant,"POI1","Amazing restaurant",11.5,21.2);
		CPOI POI2(sightseeing,"POI2","huge open peaceful space",11.0,14.0);
		CPOI POI3(shoppingcomplex,"POI3","all in 1 shopping place",7.1,8.0);
		CPOI POI4(gasstation,"POI4","late night car service",13.5,20.0);

		m_POIdbobject.addPoi(POI1);
		m_POIdbobject.addPoi(POI2);
		m_POIdbobject.addPoi(POI3);
		m_POIdbobject.addPoi(POI4);
		//CPPUNIT_ASSERT(adb->loadFromFile());
	}

	void withoutconnectingWpDb()
	{
		setUp();

		//m_route.connectToWpDatabase(& m_wpdbobject);
		m_route += "Location1";

	}

	void withconnectingWpDb()
	{
		setUp();
		m_route.connectToWpDatabase(&m_wpdbobject);
		m_route +=("Location1");

	}
	void WpnotintheDB()
	{
		setUp();
		m_route.connectToWpDatabase(&m_wpdbobject);
		m_route +=("Location6");
	}

	void withoutconnectingPOIDb()
	{
		setUp();

		//m_route.connectToWpDatabase(&m_wpdbobject);
		m_route +=("POI1");

	}

	void withconnectingPOIDb()
	{
		setUp();
		m_route.connectToPoiDatabase(&m_POIdbobject);
	//	m_route +=("POI1");

	}
	void POInotintheDB()
	{
		setUp();
		m_route.connectToPoiDatabase(&m_POIdbobject);
	  // m_route  +=("POI6");
	}

	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("plusequaloperatorTests");

		suite->addTest(new CppUnit::TestCaller<CPlusEqualOperator>("SetUp", &CPlusEqualOperator::setUp));
		suite->addTest(new CppUnit::TestCaller<CPlusEqualOperator>("withoutconnectingWpDb", &CPlusEqualOperator::withoutconnectingWpDb));
		suite->addTest(new CppUnit::TestCaller<CPlusEqualOperator>("withconnectingWpDb", &CPlusEqualOperator::withconnectingWpDb));
		suite->addTest(new CppUnit::TestCaller<CPlusEqualOperator>("WpnotintheDB", &CPlusEqualOperator::WpnotintheDB));
		suite->addTest(new CppUnit::TestCaller<CPlusEqualOperator>("withoutconnectingPOIDb", &CPlusEqualOperator::withoutconnectingPOIDb));
		suite->addTest(new CppUnit::TestCaller<CPlusEqualOperator>("withconnectingPOIDb", &CPlusEqualOperator::withconnectingPOIDb));
		suite->addTest(new CppUnit::TestCaller<CPlusEqualOperator>("POInotintheDB", &CPlusEqualOperator::POInotintheDB));

		return suite;
	}

};




#endif /* CPLUSEQUALOPERATOR_H_ */
