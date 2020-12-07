
#include "CWaypoint.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<math.h>
//#define SHOWADDRESS


CWaypoint::CWaypoint(std::string name, double latitude, double longitude)
{
   set (name,latitude,longitude);
  // cout<<"Initializing object at "                               << this      <<endl;
// 1.1 (F) Header file is the best one put the define
#ifdef SHOWADDRESS
   cout<<"m_name is having value"<<m_name<<"m_name is having address"<<&m_name<<endl;
   cout<<"m_latitude is having value"<<m_latitude<<"m_latitude is having address" <<&m_latitude<<endl;
   cout<<"m_longitude is having value"<<m_longitude<<"m_longitude is having address"<<&m_latitude<<endl;
#endif
//m_name is a string having object of sizes Amsterdam= 10 bytes, Darmstadt=10 bytes, Berlin= 7 bytes, Tokio= 6 bytes
//m_longitude is a double having size 8 bytes
//m_latitude  is a double having size 8 bytes

}

std::string CWaypoint::getName()const
{
	return m_name;
}
double CWaypoint::getLongitude()const
{
	return m_longitude;
}
double CWaypoint::getLatitude()const
{
	return m_latitude;
}
void CWaypoint::getAllDataByReference(std::string& name,  double &latitude, double &longitude)
{
	name       = m_name;
	latitude   = m_latitude;
	longitude  = m_longitude;

	//Getting all data by the reference using & operator here
	std::cout<<"current class"<<std::endl;
	std::cout<<"name:     "<<name<<"     address:"<<&name<<"\n";
	std::cout<<"latitude: "<<latitude<<"   address:"<<&latitude<<"\n";
	std::cout<<"longitude:"<<longitude<<"   address:"<<&longitude<<std::endl;

}
/*double CWaypoint::calculateDistance(const CWaypoint& wp)
{
	double distance;
	distance=R*(acos(sin(m_latitude*pie/180)*sin(wp.m_latitude*pie/180)+cos(m_latitude*pie/180)*cos(wp.m_latitude*pie/180)*cos(m_longitude*pie/180-wp.m_longitude*pie/180)));
    return distance;
}*/
void CWaypoint::print(int format)
{
//1.1 (e) Here the print function is working as per the value passed into it, as said 1 or 2
	if (format==1)
	{

		std::cout<<m_name<<" on latitude = "<<m_latitude<<" and longitude = "<<m_longitude<<std::endl;
	}
	if(format==2)
	{
		int LatitudeDeg,LatitudeMin,LongitudeDeg,LongitudeMin;
		double LatitudeSec,LongitudeSec;
		trasnformlatitude2degmmss(LatitudeDeg,LatitudeMin,LatitudeSec);
		transformLongitude2degmmss(LongitudeDeg,LongitudeMin,LongitudeSec);
		std::cout<<m_name<<" on latitude = "<<LatitudeDeg<<"deg"<<LatitudeMin<<"min"<<LatitudeSec<<"s"<<" and longitude = "<<
				LongitudeDeg<<"deg"<<LongitudeMin<<"min"<<LongitudeSec<<"s"<<std::endl;
	}
}
/* 1.1 (b) The parameters here are checked with respect to there validity and passing
the values to the attributes in case of not fulfilling, the conditions defined in(1-2)*/

void CWaypoint::set(std::string name, double latitude, double longitude  )
{
	if((-90 <= latitude && latitude <= 90)&&(-180 <= longitude && longitude <= 180))
{
		m_latitude  = latitude;
		m_longitude = longitude ;
		m_name      = name;
}
	else
{
		m_latitude  = 0;
		m_longitude = 0 ;
		m_name      = name;
}


}

std::ostream& operator<<(std::ostream& out, CWaypoint& route)
{
	    int latitude_deg, latitude_mm, longitude_deg, longitude_mm;
		double latitude_ss, longitude_ss;
		route.trasnformlatitude2degmmss(latitude_deg, latitude_mm, latitude_ss);
		out << route.m_name << " on Latitude(in degmmss format) = \t" << latitude_deg << "deg\t"
				<< latitude_mm << "min\t" << latitude_ss << "ss" <<std:: endl;
		route.transformLongitude2degmmss(longitude_deg, longitude_mm, longitude_ss);
		out << route.m_name << " on Longitude(in degmmss format) = \t" << longitude_deg << "deg\t"
				<< longitude_mm << "min\t" << longitude_ss << "ss" << std:: endl;
		return out;
	}





void CWaypoint::trasnformlatitude2degmmss(int &deg, int &mm, double &ss)
{
	double remainder;
	deg=m_latitude;
	remainder=60*(m_latitude-deg);
	mm=remainder;
	ss=60*(remainder-mm);

}

void CWaypoint::transformLongitude2degmmss(int &deg, int &mm, double &ss)
{
	double remainder;
    deg=m_longitude;
	remainder=60*(m_longitude-deg);
	mm=remainder;
	ss=60*(remainder-mm);

}

CWaypoint::~CWaypoint()
{
	// TODO Auto-generated destructor stub
}

 /* namespace std */
