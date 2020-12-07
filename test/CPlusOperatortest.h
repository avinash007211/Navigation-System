

#ifndef CPLUSOPERATORTEST_H_
#define CPLUSOPERATORTEST_H_
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Test.h>

#include "../myCode/CRoute.h"
#include "../myCode/CPOI.h"
#include "../myCode/CWaypoint.h"
#include "../myCode/CPoiDatabase.h"
#include "../myCode/CWpDatabase.h"


/**
 * This class implements several test cases related to loading the
 * data for the database from a file. Each test case is implemented
 * as a method testXXX. The static method suite() returns a TestSuite
 * in which all tests are registered.
 */
class CPlusOperatortest: public CppUnit::TestFixture {
private:
	CPoiDatabase m_POIdbobject;
	CWpDatabase m_wpdbobject,m_anotherWPdb;
	CRoute m_route1,m_route2,m_mergedroute;

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

		m_route1.connectToWpDatabase(&m_wpdbobject);
		m_route1.addWaypoint("Location1");
		m_route1.addWaypoint("Location2");
		m_route1.connectToPoiDatabase(&m_POIdbobject);
		m_route1.addPoi("POI1","Location1");
		m_route1.addPoi("POI2","Location2");

		m_route2.connectToWpDatabase(&m_wpdbobject);
		m_route2.addWaypoint("Location3");
		m_route2.addWaypoint("Location4");
		m_route2.connectToPoiDatabase(&m_POIdbobject);
		m_route2.addPoi("POI3","Location3");
		m_route2.addPoi("POI4","Location4");

	}

	void mergingrouteswithsamedb()
	{
		setUp();
		m_route1.connectToWpDatabase(&m_wpdbobject);
		m_route1.addWaypoint("Location1");
		m_route1.addWaypoint("Location2");
		m_route1.connectToPoiDatabase(&m_POIdbobject);
		m_route1.addPoi("POI1","Location1");
		m_route1.addPoi("POI2","Location2");

		m_route2.connectToWpDatabase(&m_wpdbobject);
		m_route2.addWaypoint("Location3");
		m_route2.addWaypoint("Location4");
		m_route2.connectToPoiDatabase(&m_POIdbobject);
		m_route2.addPoi("POI3","Location3");
		m_route2.addPoi("POI4","Location4");
	//	m_mergedroute=m_route1+m_route2;


	}

	void mergingrouteswithdiffdb()
		{
			setUp();
			m_route1.connectToWpDatabase(&m_wpdbobject);
			m_route1.addWaypoint("Location1");
			m_route1.addWaypoint("Location2");
			m_route1.connectToPoiDatabase(&m_POIdbobject);
			m_route1.addPoi("POI1","Location1");
			m_route1.addPoi("POI2","Location2");

			CWaypoint Location5("Location5",44.1,70.2);
			m_anotherWPdb.addWaypoint(Location5);
			m_route2.connectToWpDatabase(&m_anotherWPdb);
			m_route2.addWaypoint("Location5");
			//m_route2.addWaypoint("Location4");
			m_route2.connectToPoiDatabase(&m_POIdbobject);
			m_route2.addPoi("POI3","Location3");
			m_route2.addPoi("POI4","Location4");
		//	m_mergedroute=m_route1+m_route2;


		}
	static CppUnit::TestSuite* suite()
	{
		CppUnit::TestSuite* suite = new CppUnit::TestSuite("PlusoperatorTests");

		suite->addTest(new CppUnit::TestCaller<CPlusOperatortest>("SetUp", &CPlusOperatortest::setUp));
		suite->addTest(new CppUnit::TestCaller<CPlusOperatortest>("mergingrouteswithsamedb", &CPlusOperatortest::mergingrouteswithsamedb));
		suite->addTest(new CppUnit::TestCaller<CPlusOperatortest>("mergingrouteswithdiffdb", &CPlusOperatortest::mergingrouteswithdiffdb));


		return suite;
	}
};


#endif /* CPLUSOPERATORTEST_H_ */
