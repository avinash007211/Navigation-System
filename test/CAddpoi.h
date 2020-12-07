

#ifndef CADDPOI_H_
#define CADDPOI_H_
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Test.h>

#include "../myCode/CRoute.h"
#include "../myCode/CPOI.h"



/**
 * This class implements several test cases related to loading the
 * data for the database from a file. Each test case is implemented
 * as a method testXXX. The static method suite() returns a TestSuite
 * in which all tests are registered.
 */
class CAddPoi: public CppUnit::TestFixture {
private:
	CPoiDatabase m_POIdbobject;
	CWpDatabase m_wpdbobject;
	CRoute m_route;

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
	}

	void addingPOIwithoutconnection()
	{
		setUp();
	//	m_route.connectToWpDatabase(&m_wpdbobject);
	//	m_route.connectToPoiDatabase(&m_POIdbobject);
		m_route.addWaypoint("Location1");
		m_route.addWaypoint("Location2");
		m_route.addPoi("POI1","Location1");
		m_route.addPoi("POI2","Location2");
		CPPUNIT_ASSERT_EQUAL(0, (int) m_route.getRoute().size());
	}

	void addingPOIwithconnection()
		{
		setUp();
		m_route.connectToWpDatabase(&m_wpdbobject);
		m_route.connectToPoiDatabase(&m_POIdbobject);
		m_route.addWaypoint("Location3");
		m_route.addWaypoint("Location4");
		m_route.addPoi("POI3","Location3");
		m_route.addPoi("POI4","Location4");
		CPPUNIT_ASSERT_EQUAL(4, (int) m_route.getRoute().size());
		}



	static CppUnit::TestSuite* suite() {
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("addingpoiTests");

		suite->addTest(new CppUnit::TestCaller<CAddPoi>("SetUp", &CAddPoi::setUp));
		suite->addTest(new CppUnit::TestCaller<CAddPoi>("addingPOIwithoutconnection", &CAddPoi::addingPOIwithoutconnection));
		suite->addTest(new CppUnit::TestCaller<CAddPoi>("addingPOIwithconnection", &CAddPoi::addingPOIwithconnection));


		return suite;
	}
};








#endif /* CADDPOI_H_ */
