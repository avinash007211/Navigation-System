#include "CPOI.h"
#include <string>
#include<iostream>
#include "CWaypoint.h"
using namespace std;



CPOI::CPOI(t_poi type, string name, string description, double latitude, double longitude):CWaypoint(name,latitude,longitude)
{
	    m_type=type;
		m_description=description;
		m_latitude = latitude;
		m_longitude = longitude;
		m_name = name;
/*Here name, latitude and longitude are inherited from base class from CWaypoint for the initialization of the constructor*/

}

void CPOI::print()
{
	    cout<<"--Point of Interest--"<<endl;
		cout<<"====================="<<endl;
		switch(m_type)
		{
		case restaurant:
		cout<<" of type "<<"Restaurant"<<" : "<<m_description      <<endl;

		break;

		case sightseeing:
		cout<<" of type "<<"sightseeing"<<" : "<<m_description     <<endl;
		break;

		case shoppingcomplex:
		cout<<" of type "<<"shoppingcomplex"<<" : "<<m_description <<endl;
		break;

		case gasstation:
		cout<<" of type "<<"gasstation"<<" : "<<m_description      <<endl;
		break;

		case bank:
		cout<<" of type "<<"bank"<<" : "<<m_description            <<endl;
		break;
		default:
		break;
		}
		CWaypoint::print(MMSS);
}
void CPOI::getAllDataByReference(string& name,double& latitude,double& longitude, t_poi& type, string& description)
{

	    type        = m_type;
		description = m_description;
	    /*name        = m_name ;
		latitude    = m_latitude;
		longitude   = m_longitude;
*/
		CWaypoint::getAllDataByReference(name, latitude, longitude);
}

const t_poi CPOI::getPoiType() const
{
	return m_type;
}

const string CPOI::getPoiDescription() const
{
	return m_description;
}
