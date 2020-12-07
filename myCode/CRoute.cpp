#include "CRoute.h"
#include<iostream>
using namespace std;

CRoute::CRoute()
{
	/*Constructor of CRoute class and assigning the attributes to there default values*/

	//allocate of new memory for the pointers and initialization from null
		m_pWpDatabase = new CWpDatabase;
		m_pWpDatabase = NULL;

		m_pPoiDatabase = new CPoiDatabase;
		m_pPoiDatabase = NULL;
}

CRoute::CRoute(CRoute const& origin)
{

	m_pPoiDatabase = origin.m_pPoiDatabase;
	m_pWpDatabase = origin.m_pWpDatabase;

	for(std::list<CWaypoint*>::const_iterator it = origin.route.begin();it!=origin.route.end();it++)
	{
		route.push_back(*it);
	}
}

//Destructor of the class
CRoute::~CRoute()
{

}


void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB)
{
	if (pPoiDB != NULL)	m_pPoiDatabase = pPoiDB;
	else std::cout << "Problem! while connecting to poi database, Please check your connection" << std::endl << std::endl;
}

void CRoute::connectToWpDatabase(CWpDatabase* pWpDB)
{
	if (pWpDB != NULL) m_pWpDatabase = pWpDB;
	else std::cout << "Problem! while connecting to Wp database, Please check your connection" << std::endl << std::endl;
}

void CRoute::addWaypoint(std::string name)
{
	if (m_pWpDatabase != NULL)
	{
		int checkWp=0;
		for (std::list<CWaypoint*>:: iterator findName = route.begin();
				findName != route.end(); findName++)
		{
		if ((*findName)->getName()==name) checkWp++;
		}

		if (m_pWpDatabase->getPointerToWaypoint(name)==NULL){
        std::cout << "Problem! Waypoint is not present in Wp database" <<std:: endl << std::endl;
		}

		else if (checkWp != 0){
		std::cout << "Problem! Waypoint is already present in Wp database" <<std:: endl << std::endl;
		}
		else {
			route.insert(route.end(), m_pWpDatabase->getPointerToWaypoint(name));
		}
	}

	else std::cout << "Problem! Waypoint database is not connected" <<std::endl << std::endl;
}


void CRoute::addPoi(std::string namePoi,std:: string afterWp)
{
    if (m_pPoiDatabase != NULL){
        std::list<CWaypoint*>::iterator i = route.end();
        std::list<CWaypoint*>::iterator position;
        position = route.end();
        while (i != route.begin()){
            i--;
            if((*i)->getName() == afterWp){
            position=i;
            break;
            }
        }

        if(m_pPoiDatabase->getPointerToPoi(namePoi)== NULL){
            std::cout << "Problem! Poi is not present in Poidatabase" << std::endl <<std:: endl;
        }

        else if (position == route.end())
            std::cout << "Problem! Waypoint is not present in route" <<std:: endl << std::endl;

        else{
            route.insert(++position, m_pPoiDatabase->getPointerToPoi(namePoi));
        }
    }
    else std::cout << "Problem! POI database is not connected" << std::endl << std::endl;
}

CRoute CRoute::operator +=( std::string name)
{
		addWaypoint(name);
		addPoi(name, name);
		return *this;
}

CRoute operator+(CRoute& route1, CRoute& route2)
{
		std::list<CWaypoint*> :: iterator i;
		CRoute result;

		if (route1.m_pWpDatabase==route2.m_pWpDatabase && route1.m_pPoiDatabase==route2.m_pPoiDatabase)
		{

			for (i=(route1.route).begin(); i!=(route1.route).end(); i++)
			{
				(result.route).push_back(*i);
			}

			for (i=(route1.route).begin(); i!=(route2.route).end(); i++)
			{
				(result.route).push_back(*i);
			}
		}

		else std::cout << "Problem! Both routes are not pointing to the same database" << std::endl <<std:: endl;
		return result;
}

void CRoute:: print()
{

	std::list<CWaypoint*>::iterator i;
	for(i = route.begin(); i!=route.end(); i++)
	{

		if (dynamic_cast <CPOI*>(*i)!=NULL){
			std::cout << *(dynamic_cast<CPOI*>(*i)) << std::endl;
		}
		else std::cout << **i << std::endl;
	}
}

const vector< const CWaypoint*> CRoute::getRoute()
{
	vector<const CWaypoint*> vec;
	list<CWaypoint*>::iterator it_wp;
	for(it_wp=route.begin();it_wp!=route.end();++it_wp)
	{
		vec.push_back(*it_wp);
	}
	return vec;
}

