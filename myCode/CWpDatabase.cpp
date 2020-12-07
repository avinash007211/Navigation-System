#include "CWpDatabase.h"

CWpDatabase::CWpDatabase()
{
	// Auto generated constructor
}


void CWpDatabase::addWaypoint(const CWaypoint& wp)
{
/*	std::string n_Waypoint;
	n_Waypoint = wp.getName();
	m_Wp.insert(std::pair <std::string, CWaypoint> (n_Waypoint, wp));*/
	add_wayp_poi(wp);
}

CWaypoint* CWpDatabase::getPointerToWaypoint(std::string name)
{
	/*std::map <std::string, CWaypoint>:: iterator searchWp;
	searchWp = m_Wp.find(name);
	if (searchWp == m_Wp.end())return NULL;
	return &m_Wp[name];*/
	return getPointerToWayp_poi(name);
}

void CWpDatabase::print()
{
}

const std::map<std::string, CWaypoint>& CWpDatabase::getWp() const
{
	return getWayp_poi();
}

bool CWpDatabase::isClearWpDatabase()
{
	/*m_Wp.clear();
	if (m_Wp.size() == 0) return true;
	return false;*/
	return isClearwaypPoiDatabaseWayp_poi();
}

