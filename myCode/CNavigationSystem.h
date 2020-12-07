
#ifndef CNAVIGATIONSYSTEM_H
#define CNAVIGATIONSYSTEM_H
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CPOI.h"


class CNavigationSystem
{
public:
 // This method is called from main class to start the navigation system.
    CNavigationSystem();
// All the other private methods are called one by one here.
    void run();


private:
// This method is used to enter the route.
    void enterRoute();
// This method is used to print the nearest POI from the current position.
    void printRoute();

    CGPSSensor m_GPSSensor;

    CRoute m_route;

    CPoiDatabase m_PoiDatabase;

    CWpDatabase m_WpDatabase;

};
#endif  /*CNAVIGATIONSYSTEM_H*/

