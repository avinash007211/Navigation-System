
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <string>
#include "CWaypoint.h"
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CNavigationSystem.h"
#include "CPOI.h"
#include "CJsonPersistance.h"
#include "CCSV.h"

int main (void)
{
   setbuf(stdout, NULL);
   std::string name = "empty";
// TEST case for exercise 1.1
/*
      string name;
      double latitude;
      double distance;
      double longitude;
      cout << "Navigation system gets started." <<  endl;
// 1.1(d) Four objects are created along with newWaypoint object and there respective coordinates are passed into the parameters

      CWaypoint Amsterdam("Amsterdam",52.379189,4.8912);
      CWaypoint Darmstadt("Darmstadt",49.8192,8.6449);
      CWaypoint Berlin   ("Berlin",52.5166,13.3833);
      CWaypoint Tokio    ("Tokio",35.6895,139.69171);
      CWaypoint newWaypoint();

      cout<<"===Test case=====  "<<endl;//starting of test case
//  1.1 (f) Print
 * ing Berlin in both formats
      Berlin.print(DEGREE);
	  Berlin.print(MMSS);
//  1.1 (g) Test case for getName()
	  name=Amsterdam.getName();
//  1.1 (g) Test case for getLatitude()
	  latitude=Amsterdam.getLatitude();
//  1.1 (g) Test case for getLongitude()
	  longitude=Amsterdam.getLongitude();

// 1.1 (h) using getAllDataByRefrence() to return all way point of tokio in a single call
  	  cout<<"===Test case=====  "<<endl;
	  Tokio.getAllDataByReference(name,latitude,longitude);
      cout<<"In main"<<endl;
      cout<<"name:     "<<name<<"\t"<<"    address:"<<&name<<endl;
	  cout<<"latitude :"<<latitude<<"\t"<<"address:"<<&latitude<<endl;
  	  cout<<"longitude:"<<longitude<<"\t"<<"address:"<<&longitude<<endl;

// 1.1 (i)Test case to calculate distance between two cities.
	  cout<<"and a  first real method "<<endl;
	  cout<<"========================="<<endl;
	  distance=Berlin.calculateDistance(Amsterdam);
      cout<<"Distance between Amsterdam and Berlin:"<<distance<<endl;
      distance=Tokio.calculateDistance(Berlin);
      cout<<"Distance between Tokio and Berlin:"<<distance<<endl;
      cout<<"========================="<<endl;*/

 //TEST case for exercise 1.3 and complete navigation system
 //Run CNavigationSystem for persistence




    CPoiDatabase testPoiDatabase;
   	CWpDatabase testWpDatabase;
    CJsonPersistance test;
   	CWaypoint Amsterdam("Amsterdam", -52.379189, -4.899431);
   	CWaypoint Darmstadt("Darmstadt", 49.8192, 8.6449);
   	CWaypoint Berlin("Berlin", -52.5166, -13.4);
   	CWaypoint Munich("Munich", 48.1351,11.5820);

    CPOI Djadoo       (restaurant, "Djadoo", "amazing restaurant", 11.5,21.2);
   	CPOI Schlossgarten(sightseeing,"Schlossgarten", "huge open peaceful space", 11.0,14);
   	CPOI Karstadt     (shoppingcomplex,"Karstadt", "all in 1 shopping place", 7.1,8);
   	CPOI Karl         (gasstation,"Karl", "late night car service", 13.5,20);
   	CPOI Deutschebank (bank,"Deutsche bank", "most common bank", 11.5,21.2);

   	testWpDatabase.addWaypoint(Amsterdam);
   	testWpDatabase.addWaypoint(Berlin);
   	testWpDatabase.addWaypoint(Munich);
   	testWpDatabase.addWaypoint(Darmstadt);

   	testPoiDatabase.addPoi(restaurant);
   	testPoiDatabase.addPoi(sightseeing);
   	testPoiDatabase.addPoi(shoppingcomplex);
   	testPoiDatabase.addPoi(gasstation);

   CNavigationSystem navigation;
   navigation.run();

  // test.setmediaName("");
  //test.writeData(testWpDatabase,testPoiDatabase);
   test.readData(testWpDatabase, testPoiDatabase, CPersistentStorage::MERGE);

	return 0;
}
