
#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_
#include <string>
#include<iostream>
#include<math.h>
#define R 6378
#define DEGREE 1
#define MMSS 2
enum wp_type{Waypoint, poi};


class CWaypoint
{
	/* 1.1(a) Class is declared here according to the UML diagram*/
public:
	//Constructor part of the class.
	CWaypoint(std::string name="null", double latitude=0, double longitude=0);

    //It is used here to set the different parameters.
    void set(std::string name, double latitude, double longitude  );

    //It is used to get the Name of the location.
    std:: string getName() const;

    //It is used to get the Latitude of the location.
    double getLatitude()const;

    //It is  used to get the Longitude of the location.
    double getLongitude()const;

    //It is used to get all data by reference
    void getAllDataByReference(std::string &name, double &latitude, double &longitude);

    // It is used to calculate the distance between two locations and CWaypoint object is passed to calculate the distance
    //and it's a constant so that no changes can be made to this.
    double calculateDistance(const CWaypoint& wp);
    // It is used to print the position with parameters defined.
    virtual void print(int format);
    // It is used to access the private and protected members of the class
    friend std::ostream& operator<<(std::ostream& out, CWaypoint & route);



protected:
    double m_latitude;
    double m_longitude;
    std::string m_name;
    wp_type m_type;
private:
    // Method used to transform Longitude to degree,minutes and seconds
    void transformLongitude2degmmss(int &deg, int &mm, double &ss);
    // Method used to transform Latitude degree,minutes and seconds
    void trasnformlatitude2degmmss(int &deg, int &mm, double &ss);

public:
	virtual ~CWaypoint();
};

 /* namespace std */

#endif /* CWAYPOINT_H_ */
