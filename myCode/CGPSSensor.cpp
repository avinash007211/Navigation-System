
#include "CGPSSensor.h"
#include<iostream>


CGPSSensor::CGPSSensor()
{
}

CWaypoint CGPSSensor::getCurrentPosition()
{
	    double latitude,longitude;
        CWaypoint setcurrentposition;
        std::cout<<"GPS Sensor: "<<"\n";
        std::cout<<"Enter Latitude:"<<"\n";//To enter the inputs for current position,latitude and longitude.
        std::cin>>latitude;
        std::cout<<"Enter Longitude:"<<"\n";;
        std::cin>>longitude;
		setcurrentposition.set("Position",latitude,longitude); // saves the current position in the way point
		return setcurrentposition;
}



