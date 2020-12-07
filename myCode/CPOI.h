

#ifndef CPOI_H
#define CPOI_H
#include<string>
#include "CWaypoint.h"

enum t_poi{restaurant,sightseeing,shoppingcomplex,gasstation,bank};
class CPOI: public CWaypoint
{
private:
   // This holds the type of the Point of interest.
	t_poi m_type;
  // This holds the short descripition.
	std:: string m_description;
public:
// This method is used to print the POI in defined format
    void print();
// CPOI constructor is declared and initialized to the default values.
    CPOI(t_poi type=restaurant,std:: string name ="", std::string description="", double latitude=0, double longitude=0);
// to get all data by reference
    void getAllDataByReference(std::string& name, double & latitude, double & longitude, t_poi& type, std::string & description);
// to return type of poi
    const t_poi getPoiType() const;
// to return the poi description
    const std::string getPoiDescription() const;
//Distructor of the class
   	virtual ~CPOI(){}
};

/********************
**  CLASS END
*********************/
#endif /* CPOI_H */
