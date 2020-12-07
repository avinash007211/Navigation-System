
#ifndef CROUTE_H
#define CROUTE_H


#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include <list>
#include<vector>

class CRoute
{
private:

	// Pointer to the Poidatabase
	CPoiDatabase* m_pPoiDatabase;
    // Pointer to the Wpdatabase
	CWpDatabase* m_pWpDatabase;
	// Implementation of list container
    std::list<CWaypoint*> route;
public:
    // Constructor part of the class
    CRoute();
    //copy constructor is declared here
    CRoute(CRoute const& origin);
    // destructor part is declared here
    virtual ~CRoute();
    // it is used to connect to the poidatabase
    void connectToPoiDatabase(CPoiDatabase* pPoiDB);
    // it is used to connect to the wpdatabase
    void connectToWpDatabase(CWpDatabase* pWpDB);
    // it is used to add way point in to the route
    void addWaypoint(std::string name);
    // method used to add the POI[point of interest] in to the route
    void addPoi(std::string namePoi, std::string afterWp);
    // print function
    void print();
    // operator overloading
     CRoute operator+=(std::string name);
    // friend function to access the private and protected members of the class
    friend CRoute operator+(CRoute& route1, CRoute& route2);
    // operator overloading
   	void operator=(const CRoute& origin);

   	const std:: vector <const CWaypoint*> getRoute();


};

/********************
**  CLASS END
*********************/
#endif /* CROUTE_H */
