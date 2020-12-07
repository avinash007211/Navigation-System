

#include "CNavigationSystem.h"
#include<iostream>
#include "CPersistentStorage.h"
#include "CCSV.h"


CNavigationSystem::CNavigationSystem()
{

}

void CNavigationSystem::run()
{

	//add POIs to a database and create a route
		enterRoute();

	//print the route
		printRoute();

	//calculate the closest POI for the current GPS position and not used in this code
	//printDistanceCurPosNextPoi();

	m_route.connectToPoiDatabase(&m_PoiDatabase); //here the address of CPOI database is passed to the route

}

void CNavigationSystem::enterRoute()
{
	// Create POI's
	    CPOI Djadoo       (restaurant, "Djadoo", "amazing restaurant", 11.5,21.2);
		CPOI Schlossgarten(sightseeing,"Schlossgarten", "huge open peaceful space", 11.0,14);
		CPOI Karstadt     (shoppingcomplex,"Karstadt", "all in 1 shopping place", 7.1,8);
		CPOI Karl         (gasstation,"Karl", "late night car service", 13.5,20);
		CPOI Deutschebank (bank,"Deutsche bank", "most common bank", 11.5,21.2);

	// Add POI's
		m_PoiDatabase.addPoi(Djadoo);
		m_PoiDatabase.addPoi(Schlossgarten);
		m_PoiDatabase.addPoi(Karstadt);
		m_PoiDatabase.addPoi(Karl );
		m_PoiDatabase.addPoi(Deutschebank);

	// addition of 4 number of way points into the route
	    CWaypoint amsterdam("Amsterdam",52.379189,4.8912);
		CWaypoint darmstadt("Darmstadt",49.8192,8.6449);
		CWaypoint berlin   ("Berlin   ",52.5166,13.3833);
		CWaypoint munich   ("Munich   ",48.1351,11.5820);

	//connect the POIDatabase to the m_route
		m_route.connectToPoiDatabase(&m_PoiDatabase);

	//connect the WpDatabase to the m_route
	    m_route.connectToWpDatabase(&m_WpDatabase);

	// Add Waypoints to the route
	     m_route.addWaypoint("Berlin");
	     m_route.addWaypoint("Amsterdam");
	     m_route.addWaypoint("Darmstadt");
	     m_route.addWaypoint("Munich");

   // addition of POI[point of interests] in to the route

		m_route.addPoi("Djadoo","Berlin");
		m_route.addPoi("Schlossgarten","Amsterdam");
		m_route.addPoi("Karstadt","Darmstadt");

		m_route.print();




}

void CNavigationSystem::printRoute()
{
	std:: cout<<" print function gets started"<<std::endl;
	    m_route.print();

}
/*
 * This code is used not in use anymore.
void CNavigationSystem::printDistanceCurPosNextPoi()
{
	CWaypoint curposition;
	double disnextPOI=0.0;
	curposition=m_GPSSensor.getCurrentPosition();
	CPOI arbitrary;
	//Here fetching the current position from the user and calculating it with the nearest POI into the route.
	disnextPOI=m_route.getDistanceNextPoi(curposition,arbitrary);
	cout<<"Actual distance to next POI = "<<disnextPOI<<"Km"<<endl;
    arbitrary.print();

}
*/




