/*
 * CAddWaypoint.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Avinash
 */

#ifndef CADDWAYPOINT_H_
#define CADDWAYPOINT_H_

#include <list>
#include <cppunit/Test.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include "../myCode/CWaypoint.h"
#include "../myCode/CPoiDatabase.h"
#include "../myCode/CWpDatabase.h"
#include "../myCode/CRoute.h"

class CAddWaypoint: public CppUnit::TestFixture

{
private:
	CPoiDatabase m_pPoiDatabase;
	CWpDatabase m_WpDatabase;
	std::list<CWaypoint*> route;
	CRoute m_route;


public:

	void setUp(){
		CWaypoint Amsterdam("Amsterdam", -52.379189, -4.899431);
		CWaypoint Darmstadt("Darmstadt", 49.8192, 8.6449);
		CWaypoint Berlin("Berlin", -52.5166, -13.4);
		CWaypoint Tokio("Tokio(Japan)", -35.6895, -139.69171);

		m_WpDatabase.addWaypoint(Amsterdam);
		m_WpDatabase.addWaypoint(Darmstadt);
		m_WpDatabase.addWaypoint(Berlin);
		m_WpDatabase.addWaypoint(Tokio);
		//CPPUNIT_ASSERT(0);
	}

	void connectToWaypointDb(){
		m_route.connectToWpDatabase(&m_WpDatabase);
	}

	void connectToWaypointDbWithNull(){
		m_route.connectToWpDatabase(NULL);
	}

	void addWaypointTestWithoutDb(){
		m_route.addWaypoint("Berlin");
		m_route.addWaypoint("Amsterdam");
		m_route.addWaypoint("Darmstadt");
		m_route.addWaypoint("Tokio(Japan)");
		CPPUNIT_ASSERT_EQUAL(0, (int) m_route.getRoute().size());
	}

	void addWaypointTestWithDb(){
		connectToWaypointDb();
		m_route.addWaypoint("Berlin");
		m_route.addWaypoint("Amsterdam");
		m_route.addWaypoint("Darmstadt");
		m_route.addWaypoint("Tokio(Japan)");
		m_route.addWaypoint("test");
		m_route.addWaypoint("Berlin");
		CPPUNIT_ASSERT_EQUAL(4, (int) m_route.getRoute().size());
	}

	void addAbsentWaypoint(){
		connectToWaypointDb();
		m_route.addWaypoint("test");
	}
	void addDuplicateWaypoint(){
		connectToWaypointDb();
		m_route.addWaypoint("Darmstadt");
		m_route.addWaypoint("Darmstadt");
	}
	static CppUnit::TestSuite* suite(){
		CppUnit::TestSuite* suite = new CppUnit:: TestSuite("addWaypointTest");
		suite->addTest(new CppUnit:: TestCaller<CAddWaypoint> ("setUp", &CAddWaypoint::setUp));
		suite->addTest(new CppUnit:: TestCaller<CAddWaypoint> ("connectToWaypointTest", &CAddWaypoint::connectToWaypointDb));
		suite->addTest(new CppUnit:: TestCaller<CAddWaypoint> ("addWaypointTest", &CAddWaypoint::addWaypointTestWithoutDb));
		suite->addTest(new CppUnit:: TestCaller<CAddWaypoint> ("addWaypointTest", &CAddWaypoint::addWaypointTestWithDb));

		suite->addTest(new CppUnit:: TestCaller<CAddWaypoint> ("addWaypointTest", &CAddWaypoint::addDuplicateWaypoint));
		suite->addTest(new CppUnit:: TestCaller<CAddWaypoint> ("addWaypointTest", &CAddWaypoint::addAbsentWaypoint));
		suite->addTest(new CppUnit:: TestCaller<CAddWaypoint> ("addWaypointTest", &CAddWaypoint::connectToWaypointDbWithNull));
		return suite;
	}
};




#endif /* CADDWAYPOINT_H_ */
