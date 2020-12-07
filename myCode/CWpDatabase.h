#ifndef CWPDATABASE_H_
#define CWPDATABASE_H_
#include <map>
#include "Cwaypoint.h"
#include "CPOI.h"
#include "Ctemplate.h"


class CWpDatabase:public Ctemplate<std::string,CWaypoint>

{
/*private:
	std::map<std::string,CWaypoint>m_Wp;*/
public:
    //Constructor part of the class
	CWpDatabase();
    // It will add the waypoint to the database
    void addWaypoint(CWaypoint const & wp);
    // For getting the pointer to particular waypoint parameters.
    CWaypoint* getPointerToWaypoint(std::string name);
   // For printing all waypoints in the database
    void print();
    // For accessing the waypoint database
    const std::map<std::string, CWaypoint>& getWp() const;
    // For freeing up the database and clearing the memory.
    bool isClearWpDatabase();
};



#endif /* CWPDATABASE_H_ */
