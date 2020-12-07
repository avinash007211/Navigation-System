#include "CPoiDatabase.h"
#include "CPOI.h"
#include<iostream>
#include <string>
using namespace std;

CPoiDatabase::CPoiDatabase()
{

}

void CPoiDatabase::addPoi(const CPOI& poi)
{
	/*std::string nameOfPOI;
	nameOfPOI = poi.getName();
	m_POI.insert(std::pair<std::string, CPOI>(nameOfPOI, poi));
	//It displays the no. of POI's added
	std::cout<<"No. of POI's added"<<m_POI.size()<<std::endl;*/

	add_wayp_poi(poi);
}


CPOI*CPoiDatabase::getPointerToPoi(std::string name)
{
	    /*std::map<std::string, CPOI>::iterator searchPoi;
		searchPoi = m_POI.find(name);
		if (searchPoi == m_POI.end()) return NULL;
		else return &m_POI[name];*/
	 return getPointerToWayp_poi(name);
}


const std::map<std::string, CPOI>& CPoiDatabase::getPoi() const
{
	/*return m_POI*/;
	return getWayp_poi();
}


bool CPoiDatabase::isClearPoiDatabase()
{
	/*m_POI.clear();
	if (m_POI.size() == 0) return true;
	return false;*/
	return isClearwaypPoiDatabaseWayp_poi();
}

CPoiDatabase::~CPoiDatabase()
{
}
